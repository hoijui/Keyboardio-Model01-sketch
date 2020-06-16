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

#include <Kaleidoscope.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-OneShot.h>

#include "Layers.h"
#include "TapDance.h"
#include "Leader.h"

namespace algernon {
namespace TapDance {

static void TMUX(uint8_t tapCount, byte row, byte col, kaleidoscope::plugin::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction != kaleidoscope::plugin::TapDance::Release)
    return;

  Key key, modifier;

  Serial.print("TMUX: tapCount=");
  Serial.println(tapCount);

  if (tapCount == 1) {
    key = Key_Spacebar;
    modifier = Key_LeftAlt;
  } else {
    key = Key_A;
    modifier = Key_LeftControl;
  }

  Kaleidoscope.hid().keyboard().pressKey(modifier);
  Kaleidoscope.hid().keyboard().pressKey(key);
  Kaleidoscope.hid().keyboard().sendReport();
  Kaleidoscope.hid().keyboard().releaseKey(modifier);
  Kaleidoscope.hid().keyboard().releaseKey(key);
  Kaleidoscope.hid().keyboard().sendReport();
}

static void TMUXPane(uint8_t tapCount, byte row, byte col, kaleidoscope::plugin::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction != kaleidoscope::plugin::TapDance::Release)
    return;

  // Alt + Space
  Kaleidoscope.hid().keyboard().pressKey(Key_LeftAlt);
  Kaleidoscope.hid().keyboard().pressKey(Key_Spacebar);
  Kaleidoscope.hid().keyboard().sendReport();
  Kaleidoscope.hid().keyboard().releaseKey(Key_LeftAlt);
  Kaleidoscope.hid().keyboard().releaseKey(Key_Spacebar);
  Kaleidoscope.hid().keyboard().sendReport();

  // P, or Z
  Key key = Key_P;
  if (tapCount == 2)
    key = Key_Z;

  Kaleidoscope.hid().keyboard().pressKey(key);
  Kaleidoscope.hid().keyboard().sendReport();
  Kaleidoscope.hid().keyboard().releaseKey(key);
}

bool cancelOneShot = false;
}

}

void tapDanceAction(uint8_t tapDanceIndex, byte row, byte col, uint8_t tapCount, kaleidoscope::plugin::TapDance::ActionType tapDanceAction) {
  if (tapDanceAction == kaleidoscope::plugin::TapDance::Release)
    algernon::TapDance::cancelOneShot = true;

  switch (tapDanceIndex) {
  case TMUX:
    return algernon::TapDance::TMUX(tapCount, row, col, tapDanceAction);
  case TMUXP:
    return algernon::TapDance::TMUXPane(tapCount, row, col, tapDanceAction);

  case LPB: {
    if (tapCount < 3) {
      return tapDanceActionKeys(tapCount, tapDanceAction,
                                Key_LeftBracket,
                                Key_LeftParen);
    } else {
      if (tapDanceAction == kaleidoscope::plugin::TapDance::Release)
        return Unicode.type(0x300c);
      return;
    }
  }
  case RPB: {
    if (tapCount < 3) {
      return tapDanceActionKeys(tapCount, tapDanceAction,
                                Key_RightBracket,
                                Key_RightParen);
    } else {
      if (tapDanceAction == kaleidoscope::plugin::TapDance::Release)
        return Unicode.type(0x300d);
      return;
    }
  }

  case COLON:
    return tapDanceActionKeys(tapCount, tapDanceAction,
                              LSHIFT(Key_Semicolon),
                              Key_Semicolon);

  case MNP:
    return tapDanceActionKeys(tapCount, tapDanceAction,
                              Consumer_ScanNextTrack,
                              Consumer_ScanPreviousTrack);

  case VOLD:
    return tapDanceActionKeys(tapCount, tapDanceAction,
                              Consumer_VolumeDecrement,
                              Consumer_VolumeIncrement,
                              Key_Mute);
  }
}
