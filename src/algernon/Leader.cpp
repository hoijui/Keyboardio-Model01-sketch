/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016-2021  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "00-config.h"
#include "Layers.h"
#include "Leader.h"

#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-OneShot.h>

namespace algernon {
namespace Leader {

// Leaders
enum {
  LEAD_UNICODE_UCIS,

  LEAD_SHRUGGY,

  LEAD_LEDEFFECT,

  LEAD_BUTTERFLY,
  LEAD_COMPOSE,
  LEAD_REBOOT,
};

static void Shruggy(uint8_t seqIndex) {
  ::Unicode.type(0xaf);
  ::Macros.play(MACRO(I(25),
                      Tc(Backslash),
                      D(RightShift),
                      Tc(Minus),
                      Tc(9),
                      U(RightShift)));
  ::Unicode.type(0x30c4);
  ::Macros.play(MACRO(I(25),
                      D(RightShift),
                      Tc(0),
                      Tc(Minus),
                      U(RightShift),
                      Tc(Slash)));
  ::Unicode.type(0xaf);
}

static void startUCIS(uint8_t seqIndex) {
  handleKeyswitchEvent(SYSTER, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
}

static void NextLEDEffect(uint8_t seqIndex) {
  LEDControl.next_mode();
}

static void Butterfly(uint8_t seqIndex) {
  ::Macros.play(MACRO(I(10),
                      D(LeftAlt), W(100), Tc(X), W(100), U(LeftAlt),
                      W(100), W(100),
                      Tc(B), Tc(U), Tc(T), Tc(T), Tc(E), Tc(R), Tc(F), Tc(L), Tc(Y),
                      W(100), W(100),
                      Tc(Enter), W(100),
                      Tc(Y)));
}

static void Compose(uint8_t seqIndex) {
  ::Macros.play(MACRO(T(RightAlt)));
}

static void Reboot(uint8_t seqIndex) {
  Serial.println(F("reboot"));
  ::Kaleidoscope.device().rebootBootloader();
}

static const kaleidoscope::plugin::Leader::dictionary_t dictionary[] PROGMEM = LEADER_DICT
    ([LEAD_UNICODE_UCIS]   = {LEADER_SEQ(LEAD(MAIN), Key_U), startUCIS},

     [LEAD_SHRUGGY]         = {LEADER_SEQ(LEAD(MAIN), Key_S), Shruggy},

     [LEAD_LEDEFFECT]       = {LEADER_SEQ(LEAD(MAIN), LEAD(MAIN)), NextLEDEffect},

     [LEAD_BUTTERFLY]       = {LEADER_SEQ(LEAD(MAIN), OSM(LeftAlt)), Butterfly},
     [LEAD_COMPOSE]         = {LEADER_SEQ(LEAD(MAIN), Key_R), Compose},
     [LEAD_REBOOT]          = {LEADER_SEQ(LEAD(MAIN), Key_X), Reboot});

void configure(void) {
  ::Leader.dictionary = dictionary;
}

}
}
