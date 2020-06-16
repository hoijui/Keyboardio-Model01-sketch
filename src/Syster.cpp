/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016, 2017, 2018, 2019  Gergely Nagy
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

#include "Syster.h"
#include "SymUnI.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-Unicode.h>

void systerAction(kaleidoscope::plugin::Syster::action_t action, const char *symbol) {
  switch (action) {
  case kaleidoscope::plugin::Syster::StartAction:
    Unicode.type(0x2328);
    break;
  case kaleidoscope::plugin::Syster::EndAction:
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation, WAS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    break;
  case kaleidoscope::plugin::Syster::SymbolAction:
    algernon::SymUnI::input(symbol);
    break;
  }
}
