/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016, 2017  Gergely Nagy
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

#include "Macros.h"
#include "Layers.h"
#include "Leader.h"

#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-LangPack-Hungarian.h>

namespace algernon {
namespace Macros {

namespace LP = kaleidoscope::language;

void Csilla() {
  ::Macros.play(MACRO(Tr(LSHIFT(Key_C)),
                      Tc(S),
                      Tc(I),
                      Tc(L),
                      Tc(L)));

  handleKeyswitchEvent((Key) {
    .raw = LP::HUN_AA
  }, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);

  ::Macros.play(MACRO(Tc(M),
                      Tc(A),
                      Tc(S),
                      Tc(S),
                      Tc(Z),
                      Tc(O),
                      Tc(N),
                      Tc(Y),
                      Tc(K)));

  handleKeyswitchEvent((Key) {
    .raw = LP::HUN_AA
  }, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);

  ::Macros.play(MACRO(Tc(M)));
}

void Gergo() {
  ::Macros.play(MACRO(Tr(LSHIFT(Key_G)),
                      Tc(E),
                      Tc(J),
                      Tc(G)));

  handleKeyswitchEvent((Key) {
    .raw = LP::HUN_ODA
  }, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
  Keyboard.sendReport();
  handleKeyswitchEvent((Key) {
    .raw = LP::HUN_ODA
  }, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
  Keyboard.sendReport();
  handleKeyswitchEvent((Key) {
    .raw = LP::HUN_ODA
  }, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
}

}
}
