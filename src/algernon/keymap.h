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

#pragma once

#include "00-config.h"

namespace LP = kaleidoscope::language;

#define R(n) (Key){.raw = LP::n}
#define MW(d) Key_mouseWarp ## d
#define MM(d) Key_mouse ## d

enum {
  // Starting at 8, for compatibility's sake
  F11 = 8,
  BDN,
  BUP,
};

#define Key_AT    LSHIFT(Key_2)
#define Key_STAR  LSHIFT(Key_8)
#define Key_DOLLR LSHIFT(Key_4)
#define Key_CARET LSHIFT(Key_6)
#define Key_PRCNT LSHIFT(Key_5)
#define Key_EXCLM LSHIFT(Key_1)
#define Key_HASH  LSHIFT(Key_3)
#define Key_AND   LSHIFT(Key_7)
#define Key_LCB   LSHIFT(Key_LeftBracket)
#define Key_RCB   LSHIFT(Key_RightBracket)
#define Key_Plus  LSHIFT(Key_Equals)

#define MS_SUP MM(ScrollUp)
#define MS_SDN MM(ScrollDn)
#define MS_SL  MM(ScrollL)
#define MS_SR  MM(ScrollR)

#define Key_PlayPause Consumer_PlaySlashPause
#define Key_LArrow Key_LeftArrow
#define Key_RArrow Key_RightArrow
#define Key_DnArrow Key_DownArrow
#define Key_PageDn Key_PageDown

#define Key_Underscore LSHIFT(Key_Minus)

// *INDENT-OFF*

#if WITH_PROGMEM_KEYMAP
KEYMAPS(
  [_DVORAK] = KEYMAP_STACKED
  (
    M(F11)        ,Key_LCB   ,Key_AT    ,Key_STAR   ,Key_DOLLR ,Key_CARET ,TD(TMUX)
   ,Key_Backtick  ,Key_Quote ,Key_Comma ,Key_Period ,Key_P     ,Key_Y     ,TD(LPB)
   ,Key_Tab       ,Key_A     ,Key_O     ,Key_E      ,Key_U     ,Key_I
   ,TD(MNP)       ,Key_Slash ,Key_Q     ,Key_J      ,Key_K     ,Key_X     ,TD(COLON)

   ,OSM(LeftControl) ,Key_Backspace ,OSM(LeftShift) ,Key_Escape
   ,OSL(_NAV)

   ,TD(TMUXP)    ,Key_PRCNT ,Key_EXCLM ,Key_HASH ,Key_AND ,Key_RCB ,Key_PlayPause
   ,TD(RPB)      ,Key_F     ,Key_G     ,Key_C    ,Key_R   ,Key_L   ,Key_Backslash
                 ,Key_D     ,Key_H     ,Key_T    ,Key_N   ,Key_S   ,Key_Equals
   ,Key_Minus    ,Key_B     ,Key_M     ,Key_W    ,Key_V   ,Key_Z   ,LEAD(MAIN)

   ,Key_LeftGui ,Key_Enter ,Key_Spacebar ,OSM(LeftAlt)
   ,OSL(_AUX)
  ),

  [_ADORE] = KEYMAP_STACKED
  (
    M(F11)        ,Key_LCB   ,Key_AT ,Key_STAR ,Key_DOLLR ,Key_CARET ,TD(TMUX)
   ,Key_Backslash ,Key_Quote ,Key_W  ,Key_C    ,Key_H     ,Key_F     ,TD(LPB)
   ,Key_Tab       ,Key_A     ,Key_O  ,Key_E    ,Key_I     ,Key_U
   ,TD(MNP)       ,Key_Z     ,Key_Q  ,Key_X    ,Key_B     ,Key_Comma ,TD(COLON)

   ,OSM(LeftControl) ,Key_Backspace ,OSM(LeftShift) ,Key_Escape
   ,OSL(_NAV)

   ,TD(TMUXP)    ,Key_PRCNT  ,Key_EXCLM ,Key_HASH ,Key_AND ,Key_RCB   ,Key_PlayPause
   ,TD(RPB)      ,Key_M      ,Key_G     ,Key_L    ,Key_P   ,Key_Slash ,Key_Backslash
                 ,Key_D      ,Key_R     ,Key_T    ,Key_N   ,Key_S     ,Key_Equals
   ,Key_Minus    ,Key_Period ,Key_K     ,Key_V    ,Key_Y   ,Key_J     ,LEAD(MAIN)

   ,Key_LeftGui ,Key_Enter ,Key_Spacebar ,OSM(LeftAlt)
   ,OSL(_AUX)
  ),

  [_NAV] = KEYMAP_STACKED
  (
    ___ ,Key_F9 ,Key_F7 ,Key_F5 ,Key_F3 ,Key_F1 ,Key_PrintScreen
   ,XXX ,MS_SL  ,MW(NW) ,MM(Up) ,MW(NE) ,MS_SUP ,MW(End)
   ,XXX ,MS_SR  ,MM(L)  ,MM(Dn) ,MM(R)  ,MS_SDN
   ,___ ,XXX    ,MW(SW) ,XXX    ,MW(SE) ,XXX    ,MM(BtnL)

   ,___ ,Key_Delete ,___ ,___
   ,___

   ,LGUI(Key_L) ,Key_F10    ,Key_F2     ,Key_F4      ,Key_F6     ,Key_F8 ,XXX
   ,XXX         ,Key_PageUp ,Key_Home   ,Key_UpArrow ,Key_End    ,XXX    ,XXX
                ,Key_PageDn ,Key_LArrow ,Key_DnArrow ,Key_RArrow ,XXX    ,XXX
   ,MM(BtnR)    ,XXX        ,XXX        ,XXX         ,XXX        ,XXX    ,XXX

   ,TD(VOLD) ,___ ,___ ,___
   ,OSL(_EMPTY)
  ),

  [_AUX] = KEYMAP_STACKED
  (
    XXX ,XXX       ,XXX        ,XXX       ,XXX        ,XXX       ,M(BUP)
   ,XXX ,XXX       ,R(HUN_ODA) ,XXX       ,R(HUN_UDA) ,XXX       ,M(BDN)
   ,XXX ,R(HUN_AA) ,R(HUN_OA)  ,R(HUN_EA) ,R(HUN_UA)  ,R(HUN_IA)
   ,XXX ,XXX       ,R(HUN_OU)  ,XXX       ,R(HUN_UU)  ,XXX       ,XXX

   ,___ ,___ ,___ ,___
   ,OSL(_EMPTY)

   ,XXX            ,XXX        ,XXX   ,XXX   ,XXX   ,XXX       ,XXX
   ,XXX            ,XXX        ,Key_1 ,Key_2 ,Key_3 ,XXX       ,Key_Equals
                   ,Key_0      ,Key_4 ,Key_5 ,Key_6 ,Key_Minus ,Key_Plus
   ,Key_Underscore ,Key_Period ,Key_7 ,Key_8 ,Key_9 ,XXX       ,XXX

   ,XXX ,XXX ,XXX ,___
   ,___
  ),

  [_EMPTY] = KEYMAP_STACKED
  (
    XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX
   ,___

   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
        ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

   ,XXX ,XXX ,XXX ,XXX
   ,___
  ),
);
#else
namespace kaleidoscope {
namespace sketch_exploration {
void pluginsExploreSketch() {}
}
}
#endif

// *INDENT-ON*
