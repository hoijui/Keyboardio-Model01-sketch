/* -*- mode: c++ -*-
 * Model01-Sketch -- algernon's Model01 Sketch
 * Copyright (C) 2016-2022  Gergely Nagy
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
#include "gitrevs.h"

#include <Kaleidoscope.h>

#include <Kaleidoscope-Colormap.h>
#include <Kaleidoscope-CycleTimeReport.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-Focus-Version.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-IdleLEDs.h>
#include <Kaleidoscope-LED-ActiveModColor.h>
#include <Kaleidoscope-LED-Palette-Theme.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-MagicCombo.h>

#include "Layers.h"

#include "FocusCycleTime.h"
#include "Leader.h"
#include "MagicCombo.h"
#include "Syster.h"
#include "TapDance.h"

#include "keymap.h"

const macro_t *macroAction(uint8_t macroIndex, KeyEvent &event) {
  if (macroIndex == F11) {
    if (!keyToggledOff(event.state))
      return MACRO_NONE;
    return MACRO(T(F11));
  }

  if (!keyToggledOn(event.state))
    return MACRO_NONE;

  switch (macroIndex) {
  case BDN:
    Serial.println(F("b:d"));
    break;
  case BUP:
    Serial.println(F("b:u"));
    break;
  }
  return MACRO_NONE;
}

MAKE_FOCUS_VERSION_COMMAND("algernon/Model01-Sketch",
                           GIT_REV,
                           KALEIDOSCOPE_GITREV);

KALEIDOSCOPE_INIT_PLUGINS(
  Focus,
#if WITH_FOCUS_VERSION
  FocusVersionCommand,
#endif
  LEDControl,
#if WITH_IDLE_LEDS
  IdleLEDs,
#endif
  LEDOff,
  HostOS,
  EEPROMSettings,
  EEPROMKeymap,
  LEDPaletteTheme,
  ColormapEffect,
  Leader,
  Unicode,
  TapDance,
  OneShot,
  Syster,
  MagicCombo,
  EscapeOneShot,
  Macros,
  Hungarian,
  MouseKeys,
  ActiveModColorEffect,
  FocusSettingsCommand,
  FocusEEPROMCommand,
  FocusHostOSCommand
#if WITH_CYCLE_REPORT
  , FocusCycleTime,
  CycleTimeReport
#endif
);

void setup() {
  Kaleidoscope.setup();

  ColormapEffect.max_layers(LAYER_MAX);
  ColormapEffect.activate();

  algernon::Leader::configure();

  MouseKeys.setSpeedLimit(64);

  MouseKeys.speed = 15;
  MouseKeys.accelDelay = 35;

  Unicode.input_delay(25);

#if WITH_PROGMEM_KEYMAP
  EEPROMKeymap.setup(LAYER_MAX);
  layer_count++;
#else
  EEPROMKeymap.max_layers(LAYER_MAX);
  Layer.getKey = EEPROMKeymap.getKey;
  layer_count = LAYER_MAX + 1;
#endif
}

void loop() {
  Kaleidoscope.loop();

  if (algernon::TapDance::cancelOneShot) {
    OneShot.cancel();
    algernon::TapDance::cancelOneShot = false;
  }

  if (Layer.isActive(_EMPTY)) {
    LEDControl.set_all_leds_to(CRGB(0x0, 0x0, 0x0));
  }
}
