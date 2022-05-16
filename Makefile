ARDUINO_CLI ?= arduino-cli
SOURCES=$(wildcard src/algernon/*.cpp src/algernon/*.h src/algernon/*.ino)
OUTPUT_DIR ?= output
DEVICE_TTY ?= /dev/ttyACM1

ifdef DRONE_COMMIT
VERBOSE=-v
endif

build: ${OUTPUT_DIR}/algernon.ino.hex

${OUTPUT_DIR}/algernon.ino.hex: src/algernon/gitrevs.h ${SOURCES}
	ARDUINO_DIRECTORIES_USER=${CURDIR}/lib \
	${ARDUINO_CLI} compile \
		--libraries lib \
		--libraries lib/hardware/keyboardio/avr/libraries/Kaleidoscope/plugins \
		--build-path ${CURDIR}/build \
		--output-dir ${CURDIR}/${OUTPUT_DIR} \
		${VERBOSE} \
		src/algernon

src/algernon/gitrevs.h.new: GIT_REV=$(shell git describe --tags --always --dirty)
src/algernon/gitrevs.h.new: KALEIDOSCOPE_GITREV=$(shell cd lib/hardware/keyboardio/avr/libraries/Kaleidoscope && git rev-parse --short HEAD)
src/algernon/gitrevs.h.new:
	echo "#define GIT_REV \"${GIT_REV}\"" >$@
	echo "#define KALEIDOSCOPE_GITREV \"${KALEIDOSCOPE_GITREV}\"" >>$@

src/algernon/gitrevs.h: src/algernon/gitrevs.h.new
	cmp -s $@ $^ || mv $^ $@
	rm -f $^

setup update: tools/bootstrap.sh
	. tools/bootstrap.sh && $@

upload: build
	${ARDUINO_CLI} upload \
		-p ${DEVICE_TTY} \
		--input-dir ${CURDIR}/${OUTPUT_DIR} \
		${VERBOSE} \
		src/algernon

.PHONY: setup build update upload
