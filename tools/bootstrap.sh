# -*- mode: sh -*-
update () {
    for f in lib/Kaleidoscope-LangPack-Hungarian \
                 lib/Kaleidoscope-Focus-Version \
                 lib/Kaleidoscope-LEDEffect-DigitalRain \
                 lib/hardware/keyboardio; do
        echo "Updating $f"
        (cd $f;
         git checkout -q master;
         git pull -q -ff;
         git submodule --quiet update --init --recursive;
         git submodule --quiet foreach --recursive 'echo "Updating $path..."; git checkout -q master; git pull -q -ff';)
    done
}

link () {
    rm -f ~/Arduino/hardware/keyboardio
    install -d ~/Arduino/hardware
    ln -s $(pwd)/lib/hardware/keyboardio ~/Arduino/hardware/keyboardio
}

setup () {
    echo "Cloning..."
    [ -e lib/Kaleidoscope-LangPack-Hungarian ] || \
        git clone -q https://github.com/algernon/Kaleidoscope-LangPack-Hungarian lib/Kaleidoscope-LangPack-Hungarian
    [ -e lib/Kaleidoscope-LEDEffect-DigitalRain ] || \
        git clone -q https://github.com/tremby/Kaleidoscope-LEDEffect-DigitalRain.git lib/Kaleidoscope-LEDEffect-DigitalRain
    [ -e lib/Kaleidoscope-Focus-Version ] || \
        git clone -q https://git.madhouse-project.org/algernon/Kaleidoscope-Focus-Version.git lib/Kaleidoscope-Focus-Version
    [ -e lib/hardware/keyboardio ] || \
        git clone -q https://github.com/keyboardio/Kaleidoscope-Bundle-Keyboardio lib/hardware/keyboardio
    link
    update
}
