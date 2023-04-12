/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

// Original SE translations author: Kjell Kernen <kjell.kernen@gmail.com>
// Adapted to new string handling in EdgeTX, added and revised translations: Ulf Hedlund <ulfh05@hotmail.com>

/*
 * Formatting octal codes available in TR_ strings:
 *  \037\x           -sets LCD x-coord (x value in octal)
 *  \036             -newline
 *  \035             -horizontal tab (ARM only)
 *  \001 to \034     -extended spacing (value * FW/2)
 *  \0               -ends current string
 */

#define TR_MIN_PLURAL2  2
#define TR_MAX_PLURAL2  2
// For this number of minute in the last decimal place singular form is used in
// plural
#define TR_USE_SINGULAR_IN_PLURAL 1
#define TR_USE_PLURAL2_SPECIAL_CASE 0
// If the number of minutes is above this value PLURAL2 is used
#define TR_USE_PLURAL2 INT_MAX

#define TR_MINUTE_SINGULAR              "minut"
#define TR_MINUTE_PLURAL1               "minuter"
#define TR_MINUTE_PLURAL2               "minuter"

// NON ZERO TERMINATED STRINGS
#define TR_OFFON                        "Av","På"
#define TR_MMMINV                       "---","INV"
#define TR_VBEEPMODE                    "Tyst","Alarm","Ej knapp","Alla"
#define TR_COUNTDOWNVALUES              "5s","10s","20s","30s"
#define TR_VBLMODE                      "Av",TR("Knapp","Knappar"),TR("Spak","Spakar"),"Allt","PÅ"
#define TR_TRNMODE                      "Av","Addera","Ersätt"
#define TR_TRNCHN                       "KA1","KA2","KA3","KA4"
#define TR_AUX_SERIAL_MODES             "AV","Speglad telemetri","Telemetri in","SBUS Lärare","LUA","CLI","GPS","Debug","SpaceMouse","Extern modul"

#if LCD_W > LCD_H
  #define TR_SWTYPES                    "Ingen", "2 pos flipp","2 pos","3 pos"
#else
  #define TR_SWTYPES                    "Ingen","Flipp","2 pos","3 pos"
#endif

#define TR_POTTYPES                     "Ingen",TR("Vred m. mitt","Vred med mittläge"),TR("Multipos","Flerlägesväljare"),"Vred"
#define TR_SLIDERTYPES                  "Inga","Reglage"
#define TR_VPERSISTENT                  "Av","Flygning","Nolla själv"
#define TR_COUNTRY_CODES                TR("US","Amerika"),TR("JP","Japan"),TR("EU","Europa")
#define TR_USBMODES                     "Fråga","Joystick",TR("SD-kort","SD-kortlagring"),"Seriell"
#define TR_JACK_MODES                   "Fråga","Audio","Lärare"
#define TR_TELEMETRY_PROTOCOLS          "FrSky S.Port","FrSky D","FrSky D (sladd)","TBS Crossfire","Spektrum","AFHDS2A IBUS","Multi Telemetry"
#define TR_SBUS_INVERSION_VALUES        "normal","ej inverterad"
#define TR_MULTI_TELEMETRY_MODE         "Av","På","Av+Aux","På+Aux"
#define TR_MULTI_CUSTOM                 "Anpassad"
#define TR_VTRIMINC                     TR("Expo","Exponentiell"),TR("xFin","Extra fin"),"Fin","Medium","Grov"
#define TR_VDISPLAYTRIMS                "Nej","Ändring","Ja"
#define TR_VBEEPCOUNTDOWN               "Tyst", "Pip", "Röst", "Vibrera", TR2_2("P & Vib","Pip & Vibrera"),TR2_2("R & Vib","Röst & Vibrera")
#define TR_VVARIOCENTER                 "Pip","Tyst"
#define TR_CURVE_TYPES                  "Normal","Anpassad"

#define TR_ADCFILTERVALUES              "Global","Av","På"

#define TR_VCURVETYPE                   "Diff","Expo","Funk","Egen"                                  
#define TR_VCURVEFUNC                   "---","x>0","x<0","|x|","f>0","f<0","|f|"
#define TR_VMLTPX                       "Addera","Multiplicera","Ersätt"
#define TR_VMLTPX2                      "+=","*=",":="

#if LCD_W >= 212
  #define TR_CSWTIMER                   "Timer"
  #define TR_CSWSTICKY                  "Seg"
  #define TR_CSWRANGE                   "Vidd"
  #define TR_CSWSTAY                    "Kant"
#else
  #define TR_CSWTIMER                   "Tim"
  #define TR_CSWSTICKY                  "Seg"
  #define TR_CSWRANGE                   "Vidd"
  #define TR_CSWSTAY                    "Kant"
#endif

#define TR_CSWEQUAL                     "a=x"
#define TR_VCSWFUNC                     "---",TR_CSWEQUAL,"a" STR_CHAR_TILDE "x","a>x","a<x",TR_CSWRANGE,"|a|>x","|a|<x","AND","OR","XOR",TR_CSWSTAY,"a=b","a>b","a<b",STR_CHAR_DELTA "≥x","|" STR_CHAR_DELTA "|≥x",TR_CSWTIMER,TR_CSWSTICKY

#define TR_TEXT_SIZE                    "Std","XS","S","M","L"

#if defined(VARIO)
  #define TR_VVARIO                     "Vario"
#else
  #define TR_VVARIO                     "[Vario]"
#endif

#if defined(AUDIO)
  #define TR_SOUND                      "Spela ljud"
#else
  #define TR_SOUND                      "Pip"
#endif

#if defined(HAPTIC)
  #define TR_HAPTIC                     "Haptisk"
#else
  #define TR_HAPTIC                     "[Haptisk]"
#endif

#if defined(VOICE)
  #define TR_PLAY_TRACK                 "Spela upp"
  #define TR_PLAY_VALUE                 "Säg värdet"
#else
  #define TR_PLAY_TRACK                 "[Sp. upp]"
  #define TR_PLAY_VALUE                 "[Sp. värde]"
#endif

#define TR_SF_BG_MUSIC                  "Musik","Pausa musik"

#if defined(SDCARD)
  #define TR_SDCLOGS                    "Logga data"
#else
  #define TR_SDCLOGS                    "[Logga data]"
#endif

#ifdef GVARS
  #define TR_ADJUST_GVAR                "Justera"
#else
  #define TR_ADJUST_GVAR                "[Just. GV]"
#endif

#if defined(LUA)
  #define TR_SF_PLAY_SCRIPT             "Lua-skript"
#else
  #define TR_SF_PLAY_SCRIPT             "[Lua]"
#endif

#if defined(DEBUG)
  #define TR_SF_TEST                    "Test"
#else
  #define TR_SF_TEST
#endif

#if defined(OVERRIDE_CHANNEL_FUNCTION) && LCD_W >= 212
  #define TR_SF_SAFETY                  "Lås "
#elif defined(OVERRIDE_CHANNEL_FUNCTION)
  #define TR_SF_SAFETY                  "Lås "
#else
  #define TR_SF_SAFETY                  "---"
#endif

#define TR_SF_SCREENSHOT                "Skärmbild"
#define TR_SF_RACING_MODE               "Tävlingsläge"
#define TR_SF_DISABLE_TOUCH             "Ej pekskärm"
#define TR_SF_SET_SCREEN                "Sätt huvudskärm"
#define TR_SF_RESERVE                   "[reserv]"

#define TR_VFSWFUNC                     TR_SF_SAFETY,"Lärare","Spara trimmar","Återställ","Sätt ",TR_ADJUST_GVAR,"Volym","Sätt failsafe","Range check","Bind modul",TR_SOUND,TR_PLAY_TRACK,TR_PLAY_VALUE, TR_SF_RESERVE,TR_SF_PLAY_SCRIPT,TR_SF_RESERVE,TR_SF_BG_MUSIC,TR_VVARIO,TR_HAPTIC,TR_SDCLOGS,"Belysning",TR_SF_SCREENSHOT,TR_SF_RACING_MODE,TR_SF_DISABLE_TOUCH,TR_SF_SET_SCREEN TR_SF_TEST

#define TR_FSW_RESET_TELEM              TR("Telm","Telemetri")

#if LCD_W >= 212
  #define TR_FSW_RESET_TIMERS           "Timer 1","Timer 2","Timer 3"
#else
  #define TR_FSW_RESET_TIMERS           "Tmr1","Tmr2","Tmr3"
#endif

#define TR_VFSWRESET                    TR_FSW_RESET_TIMERS,"Alla",TR_FSW_RESET_TELEM
#define TR_FUNCSOUNDS                   TR("Bp1","Beep1"),TR("Bp2","Beep2"),TR("Bp3","Beep3"),TR("Wrn1","Warn1"),TR("Wrn2","Warn2"),TR("Chee","Cheep"),TR("Rata","Ratata"),"Tick",TR("Sirn","Siren"),"Ring",TR("SciF","SciFi"),TR("Robt","Robot"),TR("Chrp","Chirp"),"Tada",TR("Crck","Crickt"),TR("Alrm","AlmClk")


#if defined(PCBTARANIS)
#else
#endif


#define LENGTH_UNIT_IMP                "fot"
#define SPEED_UNIT_IMP                 "mph"
#define LENGTH_UNIT_METR               "m"
#define SPEED_UNIT_METR                "kmh"

#define TR_VUNITSSYSTEM                TR("Metr.","Metriska"),TR("Brit.","Brittiska")
#define TR_VTELEMUNIT                  "-","V","A","mA","kts","m/s","f/s","kmh","mph","m","ft","°C","°F","%","mAh","W","mW","dB","rpm","g","°","rad","ml","fOz","mlm","Hz","ms","us","km","dBm"

#define STR_V                          (STR_VTELEMUNIT[1])
#define STR_A                          (STR_VTELEMUNIT[2])

#define TR_VTELEMSCREENTYPE            "Inget","Siffror","Staplar","Skript"
#define TR_GPSFORMAT                   "DMS","NMEA"


#define TR_VSWASHTYPE                  "---","120","120X","140","90"

#define TR_STICK_NAMES                 "Rod", "Hjd", "Gas", "Ske"
#define TR_SURFACE_NAMES               "Rod", "Gas"

#if defined(PCBNV14)
#define  TR_RFPOWER_AFHDS2             "Default","Hög"
#endif


#define TR_ROTARY_ENCODERS
#define TR_ROTENC_SWITCHES

#if defined(COLORLCD)
  #define TR_ROTARY_ENC_OPT             "Normal","Inverterad"
#else
  #define TR_ROTARY_ENC_OPT             "Normal","Inverterad","V-I H-N","V-I H-A"
#endif

#define TR_ON_ONE_SWITCHES              "PÅ","Ett"

#if defined(IMU)
  #define TR_IMU_VSRCRAW                "TltX","TltY",
#else
  #define TR_IMU_VSRCRAW
#endif

#if defined(HELI)
  #define TR_CYC_VSRCRAW                "CYK1","CYK2","CYK3"
#else
  #define TR_CYC_VSRCRAW                "[C1]","[C2]","[C3]"
#endif


#define TR_SRC_BATT                    "Batt"
#define TR_SRC_TIME                    "Time"
#define TR_SRC_GPS                     "GPS"
#define TR_SRC_TIMER                   "Tmr"

#define TR_VTMRMODES                    "Av","På","Strt","GAs","GA%","GAt"
#define TR_VTRAINER_MASTER_OFF          "AV"
#define TR_VTRAINER_MASTER_JACK         "Lärare/Uttag"
#define TR_VTRAINER_SLAVE_JACK          "Elev/Uttag"
#define TR_VTRAINER_MASTER_SBUS_MODULE  "Lärare/SBUS-modul"
#define TR_VTRAINER_MASTER_CPPM_MODULE  "Lärare/CPPM-modul"
#define TR_VTRAINER_MASTER_BATTERY      "Lärare/Seriell"
#define TR_VTRAINER_BLUETOOTH           TR("Lärare/BT","Lärare/Bluetooth"),TR("Elev/BT","Elev/Bluetooth")
#define TR_VTRAINER_MULTI               "Lärare/Multi"

#define TR_VFAILSAFE                    "Ej inställt","Lås senaste",TR("Eget","Egna värden"),"Inga pulser","Mottagare"
#define TR_VSENSORTYPES                 "Anpassad","Beräknad"
#define TR_VFORMULAS                    "Addera","Medel","Min","Max","Multipl.","Summa","Cell","Förbrukning","Sträcka"
#define TR_VPREC                        "0.--","0.0","0.00"
#define TR_VCELLINDEX                   "Lägsta","1","2","3","4","5","6","7","8","Högsta","Skillnad"
#define TR_SUBTRIMMODES                 STR_CHAR_DELTA " (endast center)","= (symmetrisk)"
#define TR_TIMER_DIR                    TR("Återst.", "Visa återstående"), TR("Förbrukad", "Visa förbrukad")

#if defined(COLORLCD)
  #if defined(BOLD)
    #define TR_FONT_SIZES               "STD"
  #else
    #define TR_FONT_SIZES               "STD","FET","XXS","XS","L","XL","XXL"
  #endif
#endif


#if defined(PCBFRSKY)
  #define TR_ENTER                      "[ENTER]"
#elif defined(PCBNV14)
  #define TR_ENTER                      "[NÄSTA]"
#else
  #define TR_ENTER                      "[MENY]"
#endif

#if defined(PCBHORUS)
  #define TR_EXIT                       "RTN"
  #define TR_OK                         TR_ENTER
#else
  #define TR_EXIT                       "EXIT"
  #define TR_OK                         "\010" "\010" "\010" TR("[OK]", "\010" "\010" "[OK]")
#endif

#if defined(PCBTARANIS)
  #define TR_POPUPS_ENTER_EXIT          TR(TR_EXIT "\010" TR_ENTER, TR_EXIT "\010" "\010" "\010" "\010" TR_ENTER)
#else
  #define TR_POPUPS_ENTER_EXIT          TR_ENTER "\010" TR_EXIT
#endif

#define TR_FREE                         "kvar"
#define TR_YES                          "Ja"
#define TR_NO                           "Nej"
#define TR_DELETEMODEL                  "RADERA MODELL"
#define TR_COPYINGMODEL                 "Kopierar..."
#define TR_MOVINGMODEL                  "Flyttar..."
#define TR_LOADINGMODEL                 "Laddar..."
#define TR_UNLABELEDMODEL               "Utan etikett"
#define TR_NAME                         "Namn"
#define TR_MODELNAME                    "Modellnamn"
#define TR_PHASENAME                    "Lägesnamn"
#define TR_MIXNAME                      "Mixernamn"
#define TR_INPUTNAME                    TR("Namn","Inputnamn")
#define TR_EXPONAME                     TR("Namn","Radnamn")
#define TR_NO_PICTURE                   "Ingen bild"
#define TR_BITMAP                       "Modellikon"
#define TR_TIMER                        TR("Timer","Timer ")
#define TR_START                        "Start"
#define TR_ELIMITS                      TR("Gränser++","Utökade gränser")
#define TR_ETRIMS                       TR("Trimmar++","Utökade trimmar")
#define TR_TRIMINC                      TR("Trimning","Trimmökning")
#define TR_DISPLAY_TRIMS                TR("Visa trimm", "Visa trimmar")
#define TR_TTRACE                       TR("Källa", INDENT "Källa")
#define TR_TTRIM                        TR("Gastrimm", INDENT "Trimma endast tomgång")
#define TR_TTRIM_SW                     TR("Trimmknp", INDENT "Trimmknapp")
#define TR_BEEPCTR                      TR("Cent.pip", "Centerpip")
#define TR_USE_GLOBAL_FUNCS             TR("Glob.funk.", "Anv. globala funk.")
#define TR_PROTOCOL                     TR("Proto.", "Protokoll")
#define TR_PPMFRAME                     INDENT "PPM-paket"
#define TR_REFRESHRATE                  TR(INDENT "Refresh", INDENT "Refresh rate")
#define STR_WARN_BATTVOLTAGE            TR(INDENT "Utspänning = VBAT: ", INDENT "VARNING: Utspänning är VBAT: ")
#define TR_WARN_5VOLTS                  "VARNING: Spänning ut är 5 volt"
#define TR_MS                           "ms"
#define TR_SWITCH                       "Brytare"
#define TR_SF_SWITCH                    "Trigger"
#define TR_TRIMS                        "Trimmar"
#define TR_FADEIN                       "Tona in"
#define TR_FADEOUT                      "Tona ut"
#define TR_DEFAULT                      "Default"
#if defined(COLORLCD)
  #define TR_CHECKTRIMS                 "Kolla FL-trimmar"
#else
  #define TR_CHECKTRIMS                 CENTER "\006Kolla\012trimmar"
#endif 
#define OFS_CHECKTRIMS                  CENTER_OFS+(9*FW)
#define TR_SWASHTYPE                    "Swashtyp"
#define TR_COLLECTIVE                   "Kollektiv"
#define TR_AILERON                      "Skevroderkälla"
#define TR_ELEVATOR                     "Höjdroderkälla"
#define TR_SWASHRING                    "Swashring"
#define TR_MODE                         "Typ"
#if LCD_W > LCD_H
  #define TR_LEFT_STICK                 "Vänster"
#else
  #define TR_LEFT_STICK                 "Vä"
#endif
#define TR_SUBTYPE                      INDENT "Subtyp"
#define TR_NOFREEEXPO                   "Ingen ledig expo!"
#define TR_NOFREEMIXER                  "Ingen ledig mixer!"
#define TR_SOURCE                       "Källa"
#define TR_WEIGHT                       "Vikt"
#define TR_SIDE                         "Sida"
#define TR_OFFSET                       "Offset"
#define TR_TRIM                         "Trimm"
#define TR_DREX                         "DRex"
#define DREX_CHBOX_OFFSET               30
#define TR_CURVE                        "Kurva"
#define TR_FLMODE                       TR("Flygläge","Flyglägen")
#define TR_MIXWARNING                   "Varning"
#define TR_OFF                          "AV"
#define TR_ANTENNA                      "Antenn"
#define TR_NO_INFORMATION               TR("Ingen info", "Ingen information")
#define TR_MULTPX                       "Multiplex"
#define TR_DELAYDOWN                    TR("Dröj ned","Fördröj ned")
#define TR_DELAYUP                      TR("Dröj upp","Fördröj upp")
#define TR_SLOWDOWN                     "Trög ned"
#define TR_SLOWUP                       "Trög upp"
#define TR_MIXES                        "MIXAR"
#define TR_CV                           "KU"

#if defined(PCBNV14)
  #define TR_GV                         "GV"
#else
  #define TR_GV                         TR("G","GV")
#endif

#define TR_RANGE                        INDENT "MinMax"
#define TR_CENTER                       INDENT "Center"
#define TR_ALARM                        "Alarm"
#define TR_BLADES                       "Blad"
#define TR_SCREEN                       "Skärm\001"
#define TR_SOUND_LABEL                  "Ljud"
#define TR_LENGTH                       "Tid"
#define TR_BEEP_LENGTH                  "Piplängd"
#define TR_BEEP_PITCH                   "Pipton"
#define TR_HAPTIC_LABEL                 "Vibration"
#define TR_STRENGTH                     "Styrka"
#define TR_IMU_LABEL                    "IMU"
#define TR_IMU_OFFSET                   "Offset"
#define TR_IMU_MAX                      "Max"
#define TR_CONTRAST                     "Kontrast"
#define TR_ALARMS_LABEL                 "Alarm"
#define TR_BATTERY_RANGE                TR("Batt. min-max", "Batteriindikator min-max")
#define TR_BATTERYCHARGING              "Laddar..."
#define TR_BATTERYFULL                  "Batteri fullt"
#define TR_BATTERYNONE                  "None!"
#define TR_BATTERYWARNING               "Batteri"
#define TR_INACTIVITYALARM              "Inaktivitet"
#define TR_MEMORYWARNING                "Lite minne"
#define TR_ALARMWARNING                 "Ljud av"
#define TR_RSSI_SHUTDOWN_ALARM          TR("RSSI avstängn.", "Kolla RSSI vid avstängning")
#define TR_MODEL_STILL_POWERED          TR("Modell på","Modell fortfarande på")
#define TR_USB_STILL_CONNECTED          "USB fortfarande ansluten"
#define TR_MODEL_SHUTDOWN               "Stänga av?"
#define TR_PRESS_ENTER_TO_CONFIRM       "Tryck [ENTER] för att bekräfta"
#define TR_THROTTLE_LABEL               "Gas"
#define TR_THROTTLE_START               "Gas Start"
#define TR_THROTTLEREVERSE              TR("Omv. gas", INDENT "Omvänd gas")
#define TR_MINUTEBEEP                   "Minutpip"
#define TR_BEEPCOUNTDOWN                INDENT "Nedräkning"
#define TR_PERSISTENT                   TR(INDENT "Beständig", INDENT "Beständighet")
#define TR_BACKLIGHT_LABEL              "Belysning"
#define TR_GHOST_MENU_LABEL             "GHOST MENY"
#define TR_STATUS                       "Status"
#define TR_BLDELAY                      INDENT "Av efter"
#define TR_BLONBRIGHTNESS               INDENT "Ljusstyrka på"
#define TR_BLOFFBRIGHTNESS              INDENT "Ljusstyrka av"
#define TR_KEYS_BACKLIGHT               "Tangentbelysning"
#define TR_SPLASHSCREEN                 "Startbild"
#define TR_PWR_ON_DELAY                 "Fördröj start"
#define TR_PWR_OFF_DELAY                "Fördröj avslut"
#define TR_BLCOLOR                      "Färg"
#define TR_THROTTLE_WARNING             TR(INDENT "Gasvarn.", INDENT "Gasvarning")
#define TR_CUSTOM_THROTTLE_WARNING      TR(INDENT INDENT INDENT INDENT "Egen pos", INDENT INDENT INDENT INDENT "Egen position?")
#define TR_CUSTOM_THROTTLE_WARNING_VAL  TR("Pos. %", "Position %")
#define TR_SWITCHWARNING                TR(INDENT "Bryt.varn.", INDENT "Brytarvarning")
#define TR_POTWARNINGSTATE              TR(INDENT "Vred&Regl.", INDENT "Vred & reglage")
#define TR_SLIDERWARNING                TR(INDENT "Regl. pos.", INDENT "Reglagepositioner")
#define TR_POTWARNING                   TR(INDENT "Vredläge", INDENT "Vredlägen")
#define TR_TIMEZONE                     "Tidszon"
#define TR_ADJUST_RTC                   "Justera RTC"
#define TR_GPS                          "GPS"
#define TR_RXCHANNELORD                 TR("Kanalordn. Rx","Kanalordning i Rx")
#define TR_STICKS                       "Spakar"
#define TR_POTS                         "Vred"
#define TR_SWITCHES                     "Brytare"
#define TR_SWITCHES_DELAY               TR("Fördröj ljud", "Fördröj ljuduppspelning")
#define TR_SLAVE                        "Elev"
#define TR_MODESRC                      "Läge\006% källa"
#define TR_MULTIPLIER                   "Styrka"
#define TR_CAL                          "Kal."
#define TR_CALIBRATION                  "Kalibrering"
#define TR_VTRIM                        "Trimm - +"
#define TR_CALIB_DONE                   "Kalibrering färdig"

#if defined(PCBHORUS)
  #define TR_MENUTOSTART                "Tryck [Enter] för att börja"
  #define TR_SETMIDPOINT                "Centrera spakar/vred/reglage och tryck [Enter]"
  #define TR_MOVESTICKSPOTS             "Rör spakar/vred/reglage och tryck [Enter]"
#elif defined(COLORLCD)
  #define TR_MENUTOSTART                TR_ENTER " FÖR ATT STARTA"
  #define TR_SETMIDPOINT                "CENTRERA ALLT"
  #define TR_MOVESTICKSPOTS             "RÖR SPAKAR/REGLAGE"
#else
  #define TR_MENUTOSTART                CENTER TR_ENTER " FÖR ATT STARTA"
//  #define TR_MENUTOSTART                CENTER "\010" TR_ENTER " FÖR ATT STARTA"
  #define TR_SETMIDPOINT                TR(CENTER "\006CENTRERA ALLT", CENTER "\004CENTRERA SPAKAR/VRED/REGLAGE")
//  #define TR_SETMIDPOINT                TR(CENTER "\004CENTRERA ALLT", CENTER "\004CENTRERA SPAKAR/VRED/REGLAGE")
  #define TR_MOVESTICKSPOTS             CENTER "RÖR SPAKAR/VRED/REGLAGE"
//  #define TR_MOVESTICKSPOTS             CENTER "\006RÖR SPAKAR/VRED/REGLAGE"
  #define TR_MENUWHENDONE               CENTER "\006" TR_ENTER " AVSLUTAR"
#endif

#define TR_TXnRX                        "Tx:\0Rx:"
#define OFS_RX                          4
#define TR_NODATA                       CENTER "DATA SAKNAS"
#define TR_US                           "us"
#define TR_HZ                           "Hz"

#define TR_TMIXMAXMS                    "Tmix max"
#define TR_FREE_STACK                   "Fri stack"
#define TR_INT_GPS_LABEL                "Intern GPS"
#define TR_HEARTBEAT_LABEL              "Heartbeat"
#define TR_LUA_SCRIPTS_LABEL            "Lua-skript"
#define TR_FREE_MEM_LABEL               "Ledigt minne"
#define TR_TIMER_LABEL                  "Timer"
#define TR_THROTTLE_PERCENT_LABEL       "Gas %"
#define TR_BATT_LABEL                   "Batteri"
#define TR_SESSION                      "Session"
#define TR_MENUTORESET                  TR_ENTER " nollar"
#define TR_PPM_TRAINER                  "TR"
#define TR_CH                           "KA"
#define TR_MODEL                        "MODELL"
#define TR_FM                           "FL"
#define TR_EEPROMLOWMEM                 "Minnesbrist"
#define TR_PRESS_ANY_KEY_TO_SKIP        "Avbryt med valfri knapp"
#define TR_THROTTLE_NOT_IDLE            "Gasen är på!"
#define TR_ALARMSDISABLED               "Alarmen avstängda!"
#define TR_PRESSANYKEY                  TR("\010Tryck på en knapp", "Tryck på valfri knapp")
#define TR_BADEEPROMDATA                "Minnet kan inte tolkas"
#define TR_BAD_RADIO_DATA               "Data från radion kan inte tolkas"
#define TR_RADIO_DATA_RECOVERED         TR3("Anv. backupradiodata","Anv. backupradioinställningar","Radioinställningar återställda från backup")
#define TR_RADIO_DATA_UNRECOVERABLE     TR3("Ogiltiga radioinställn.","Ogiltiga radioinställningar", "Kan inte läsa giltiga radioinställningar")
#define TR_EEPROMFORMATTING             "Minnet formateras"
#define TR_STORAGE_FORMAT               "SD-Lagring förbereds"
#define TR_EEPROMOVERFLOW               "Minnesfel"
#define TR_RADIO_SETUP                  "INSTÄLLNINGAR"
#define TR_MENUTRAINER                  "LÄRARE"
#define TR_MENUSPECIALFUNCS             "GLOBALA FUNKTIONER"
#define TR_MENUVERSION                  "VERSION"
#define TR_MENU_RADIO_SWITCHES          TR("BRYTARE","TEST AV BRYTARE")
#define TR_MENU_RADIO_ANALOGS           TR("ANALOGA", "TEST AV ANALOGA")
#define TR_MENU_RADIO_ANALOGS_CALIB     "KALIBRERADE ANALOGA"
#define TR_MENU_RADIO_ANALOGS_RAWLOWFPS "RÅA ANALOGA (5Hz)"
#define TR_MENUCALIBRATION              "KALIBRERING"
#if defined(COLORLCD)
  #define TR_TRIMS2OFFSETS              "[Spara trimvärden]"
#else
  #define TR_TRIMS2OFFSETS              "\006[Spara trimvärden]"
#endif
#define TR_CHANNELS2FAILSAFE            "Kanaler=>Failsafe"
#define TR_CHANNEL2FAILSAFE             "Kanal=>Failsafe"
#define TR_MENUMODELSEL                 TR("MODELL","VÄLJ MODELL")
#define TR_MENU_MODEL_SETUP             TR("MODELLINSTÄLLNING","MODELLINSTÄLLNINGAR")
#define TR_MENUFLIGHTMODE               "FLYGLÄGE"
#define TR_MENUFLIGHTMODES              "FLYGLÄGEN"
#define TR_MENUHELISETUP                "HELIKOPTER"

#define TR_MENUINPUTS                   "INPUT"
#define TR_MENULIMITS                   "OUTPUT"
#define TR_MENUCURVES                   "KURVOR"
#define TR_MENUCURVE                    "KURVA"
#define TR_MENULOGICALSWITCH            "LOGISK BRYTARE"
#define TR_MENULOGICALSWITCHES          "LOGISKA BRYTARE"
#define TR_MENUCUSTOMFUNC               "SPECIALFUNKTIONER"
#define TR_MENUCUSTOMSCRIPTS            "SKRIPT"
#define TR_MENUTELEMETRY                "TELEMETRI"
#define TR_MENUSTAT                     "STATISTIK"
#define TR_MENUDEBUG                    "DEBUG"
#define TR_MONITOR_CHANNELS1            "KANALÖVERSIKT - KA 1-8"
#define TR_MONITOR_CHANNELS2            "KANALÖVERSIKT - KA 9-16"
#define TR_MONITOR_CHANNELS3            "KANALÖVERSIKT - KA 17-24"
#define TR_MONITOR_CHANNELS4            "KANALÖVERSIKT - KA 25-32"
#define TR_MONITOR_SWITCHES             "ÖVERSIKT - LOGISKA BRYTARE"
#define TR_MONITOR_OUTPUT_DESC          "Utdata"
#define TR_MONITOR_MIXER_DESC           "Mixar"
#define TR_RECEIVER_NUM                 TR("RxNum","Mottagare nr.")
#define TR_RECEIVER                     "Mottagare"
#define TR_MULTI_RFTUNE                 TR("Frekv.just", "Finjustera radiofrekvens")
#define TR_MULTI_RFPOWER                "RF styrka"
#define TR_MULTI_WBUS                   "Output"
#define TR_MULTI_TELEMETRY              "Telemetri"
#define TR_MULTI_VIDFREQ                TR("Vid.frekv", "Videofrekvens")
#define TR_RF_POWER                     "RF styrka"
#define TR_MULTI_FIXEDID                TR("FastID", "Fast ID")
#define TR_MULTI_OPTION                 TR("Alternativ", "Alternativets värde")
#define TR_MULTI_AUTOBIND               TR(INDENT "Bind ka.",INDENT "Bind via kanal")
#define TR_DISABLE_CH_MAP               TR("Ej ka.översikt", "Inaktivera kanalöversikt")
#define TR_DISABLE_TELEM                TR("Ej telem.", "Inaktivera telemetri")
#define TR_MULTI_DSM_AUTODTECT          TR(INDENT "Auto", INDENT "Autodetektera format")
#define TR_MULTI_LOWPOWER               TR(INDENT "Låg effekt", INDENT "Lågeffektläge")
#define TR_MULTI_LNA_DISABLE            INDENT "LNA disable"
#define TR_MODULE_TELEMETRY             TR(INDENT "S.Port", INDENT "S.Port link")
#define TR_MODULE_TELEM_ON              TR("På", "Aktiverad")
#define TR_DISABLE_INTERNAL             TR("Inaktiv. int. RF", "Inaktivera intern RF")
#define TR_MODULE_NO_SERIAL_MODE        TR("!seriellt läge", "Ej i seriellt läge")
#define TR_MODULE_NO_INPUT              TR("Ingen input", "Ingen seriell input")
#define TR_MODULE_NO_TELEMETRY          TR3("Ingen telem.", "Ingen MULTI_TELEMETRY", "Ingen MULTI_TELEMETRY detekterad")
#define TR_MODULE_WAITFORBIND           "Bind för att ladda protokoll"
#define TR_MODULE_BINDING               "Binder"
#define TR_MODULE_UPGRADE_ALERT         TR3("Uppdat.krävs", "Modulen måste uppdateras", "Modulen\nbehöver uppdateras")
#define TR_MODULE_UPGRADE               TR("Uppdat. rekomm", "Moduluppdatering rekommenderas")
#define TR_REBIND                       "Ny bindning krävs"
#define TR_REG_OK                       "Registrering ok"
#define TR_BIND_OK                      "Bindning klar"
#define TR_BINDING_CH1_8_TELEM_ON       "Ka1-8 Telem på"
#define TR_BINDING_CH1_8_TELEM_OFF      "Ka1-8 Telem av"
#define TR_BINDING_CH9_16_TELEM_ON      "Ka9-16 Telem på"
#define TR_BINDING_CH9_16_TELEM_OFF     "Ka9-16 Telem av"
#define TR_PROTOCOL_INVALID             TR("Prot ogiltigt", "Ogiltigt protokoll")
#define TR_MODULE_STATUS                TR(INDENT "Status", INDENT "Modulstatus")
#define TR_MODULE_SYNC                  TR(INDENT "Synk", INDENT "Proto synk.status")
#define TR_MULTI_SERVOFREQ              TR("Servofart", "Servouppdateringsfrekvens")
#define TR_MULTI_MAX_THROW              TR("Max. utslag", "Aktivera max. utslag")
#define TR_MULTI_RFCHAN                 TR("RF kanal", "Välj RF kanal")
#define TR_FLYSKY_TELEMETRY             TR("FlySky RSSI #", "Använd FlySky RSSI-värde utan skalning")
#define TR_GPS_COORDS_FORMAT            TR("GPS-koord.sys", "GPS-koordinatsystem")
#define TR_VARIO                        TR("Vario", "Variometer")
#define TR_PITCH_AT_ZERO                "Ton vid noll"
#define TR_PITCH_AT_MAX                 "Ton vid max"
#define TR_REPEAT_AT_ZERO               TR("Rep. vid noll", "Repetera vid noll")
#define TR_BATT_CALIB                   TR("Kalib. batt." ,"Kalibrera batteri")
#define TR_CURRENT_CALIB                "Kalib. ström"
#define TR_VOLTAGE                      INDENT "Volt"
#define TR_SELECT_MODEL                 "Välj modell"
#define TR_MODELS                       "Modeller"
#define TR_SELECT_MODE                  "Välj läge"
#define TR_CREATE_MODEL                 "Skapa modell"
#define TR_FAVORITE_LABEL               "Favoriter"
#define TR_MODELS_MOVED                 "Oanvända modeller flyttade till"
#define TR_NEW_MODEL                    "Ny modell"
#define TR_INVALID_MODEL                "Ogiltig modell"
#define TR_EDIT_LABELS                  "Redigera etiketter"
#define TR_MOVE_UP                      "Flytta upp"
#define TR_MOVE_DOWN                    "Flytta ner"
#define TR_ENTER_LABEL                  "Ange etikett"
#define TR_LABEL                        "Etikett"
#define TR_LABELS                       "Etiketter"
#define TR_CURRENT_MODEL                "Nuvarande"
#define TR_NEW                          "Ny"
#define TR_NEW_LABEL                    "Ny etikett"
#define TR_RENAME_LABEL                 "Byt namn på etikett"
#define TR_DELETE_LABEL                 "Radera etikett"
#define TR_DUPLICATE_MODEL              "Duplicera modell"
#define TR_COPY_MODEL                   "Kopiera modell"
#define TR_MOVE_MODEL                   "Flytta modell"
#define TR_BACKUP_MODEL                 "Modellbackup"
#define TR_DELETE_MODEL                 "Radera modell"
#define TR_RESTORE_MODEL                "Återställ modell"
#define TR_DELETE_ERROR                 "Raderingsfel"
#define TR_SDCARD_ERROR                 "SD-kortfel"
#define TR_SDCARD                       "SD-kort"
#define TR_NO_FILES_ON_SD               "Inga filer på SD!"
#define TR_NO_SDCARD                    "SD-kort saknas"
#define TR_WAITING_FOR_RX               "Väntar på Rx..."
#define TR_WAITING_FOR_TX               "Väntar på Tx..."
#define TR_WAITING_FOR_MODULE           TR("Inväntar modul", "Inväntar radiomodulen...")
#define TR_NO_TOOLS                     "Inga verktyg tillgängliga"
#define TR_NORMAL                       "Normal"
#define TR_NOT_INVERTED                 "Ej inv"
#define TR_NOT_CONNECTED                "!Ansluten"
#define TR_CONNECTED                    "Ansluten"
#define TR_FLEX_915                     "Flex 915MHz"
#define TR_FLEX_868                     "Flex 868MHz"
#define TR_16CH_WITHOUT_TELEMETRY       TR("16KA utan telem.", "16 KA utan telemetri")
#define TR_16CH_WITH_TELEMETRY          TR("16KA med telem.", "16 KA med telemetri")
#define TR_8CH_WITH_TELEMETRY           TR("8KA med telem.", "8 KA med telemetri")
#define TR_EXT_ANTENNA                  "Ext. antenn"
#define TR_PIN                          "Pin"
#define TR_UPDATE_RX_OPTIONS            "Uppdatera Rx alternativ?"
#define TR_UPDATE_TX_OPTIONS            "Uppdatera Tx alternativ?"
#define TR_MODULES_RX_VERSION           "Moduler / Rx version"
#define TR_SHOW_MIXER_MONITORS          "Visa mixervärden"
#define TR_MENU_MODULES_RX_VERSION      "MODULER / RX VERSION"
#define TR_MENU_FIRM_OPTIONS            "FIRMWAREFUNKTIONER"
#define TR_IMU                          "IMU"
#define TR_STICKS_POTS_SLIDERS          "Spakar/Vred/Reglage"
#define TR_PWM_STICKS_POTS_SLIDERS      "PWM Spakar/Vred/Reglage"
#define TR_RF_PROTOCOL                  "RF Protokoll"
#define TR_MODULE_OPTIONS               "Modulalternativ"
#define TR_POWER                        "Power"
#define TR_NO_TX_OPTIONS                "Inga TX-alternativ"
#define TR_RTC_BATT                     "RTC Batteri"
#define TR_POWER_METER_EXT              "Power Meter (EXT)"
#define TR_POWER_METER_INT              "Power Meter (INT)"
#define TR_SPECTRUM_ANALYSER_EXT        "Spektrum (EXT)"
#define TR_SPECTRUM_ANALYSER_INT        "Spektrum (INT)"
#define TR_SDCARD_FULL                  "SD-kort fullt"
#define TR_NEEDS_FILE                   "BEHÖVER FIL"
#define TR_EXT_MULTI_SPEC               "opentx-inv"
#define TR_INT_MULTI_SPEC               "stm-opentx-noinv"
#define TR_INCOMPATIBLE                 "Inkompatibel"
#define TR_WARNING                      "VARNING"
#define TR_EEPROMWARN                   "EEPROM"
#define TR_STORAGE_WARNING              "LAGRINGS-"
#define TR_EEPROM_CONVERTING            "EEPROM konvertering"
#define TR_SDCARD_CONVERSION_REQUIRE    "SD-kortet behöver konverteras"
#define TR_CONVERTING                   "Konverteras: "
#define TR_THROTTLE_UPPERCASE           "GAS-"
#define TR_ALARMSWARN                   "ALARM"
#define TR_SWITCHWARN                   "BRYTAR-"
#define TR_FAILSAFEWARN                 "FAILSAFE-"
#define TR_TEST_WARNING                 TR("TEST", "TESTBYGGE")
#define TR_TEST_NOTSAFE                 "Använd endast för test"
#define TR_WRONG_SDCARDVERSION          TR("Förväntad ver: ","Förväntad version: ")
#define TR_WARN_RTC_BATTERY_LOW         "RTC-batteriet lågt"
#define TR_WARN_MULTI_LOWPOWER          "Lågeffektläge"
#define TR_BATTERY                      "BATTERI"
#define TR_WRONG_PCBREV                 "Fel PCB detekterad"
#define TR_EMERGENCY_MODE               "EMERGENCY MODE"
#define TR_NO_FAILSAFE                  "Failsafe ej angiven"
#define TR_KEYSTUCK                     "Knappfel"
#define TR_VOLUME                       "Volym"
#define TR_LCD                          "LCD"
#define TR_BRIGHTNESS                   "Ljusstyrka"
#define TR_CPU_TEMP                     "CPU temp.\016>"
#define TR_CPU_CURRENT                  "Ström\022>"
#define TR_CPU_MAH                      "Förbrukn."
#define TR_COPROC                       "CoProc."
#define TR_COPROC_TEMP                  "MB temp. \016>"
#define TR_CAPAWARNING                  INDENT "Låg kapacitet"
#define TR_TEMPWARNING                  TR(INDENT "Hög temp", INDENT "Hög temperatur")
#define TR_TTL_WARNING                  "Varning: använd 3.3V logiska nivåer"
#define TR_FUNC                         "Funktion"
#define TR_V1                           "Värde 1"
#define TR_V2                           "Värde 2"
#define TR_DURATION                     "Varaktighet"
#define TR_DELAY                        "Fördröjning"
#define TR_SD_CARD                      "SD-KORT"
#define TR_SDHC_CARD                    "SD/HC-kort"
#define TR_NO_SOUNDS_ON_SD              "Inga ljud på SD"
#define TR_NO_MODELS_ON_SD              "Inga modeller på SD"
#define TR_NO_BITMAPS_ON_SD             "Inga ikoner på SD"
#define TR_NO_SCRIPTS_ON_SD             "Inga skript på SD"
#define TR_SCRIPT_SYNTAX_ERROR          TR("Syntaxfel", "Skriptsyntaxfel")
#define TR_SCRIPT_PANIC                 "Script panic"
#define TR_SCRIPT_KILLED                "Script dödat"
#define TR_SCRIPT_ERROR                 "Okänt fel"
#define TR_PLAY_FILE                    "Spela"
#define TR_DELETE_FILE                  "Radera"
#define TR_COPY_FILE                    "Kopiera"
#define TR_RENAME_FILE                  "Byt namn"
#define TR_ASSIGN_BITMAP                "Tilldela ikon"
#define TR_ASSIGN_SPLASH                "Startbild"
#define TR_EXECUTE_FILE                 "Kör"
#define TR_REMOVED                      " raderad"
#define TR_SD_INFO                      "Information"
#define TR_SD_FORMAT                    "Formatera"
#define TR_NA                           "N/A"
#define TR_HARDWARE                     "HÅRDVARA"
#define TR_FORMATTING                   "Formaterar..."
#define TR_TEMP_CALIB                   "Temp. kalib."
#define TR_TIME                         "Tid"
#define TR_BAUDRATE                     "Baudrate"
#define TR_MAXBAUDRATE                  "Max bauds"
#define TR_SAMPLE_MODE                  TR("Sampling","Sample Mode")
#define TR_SAMPLE_MODES                 "Normal","OneBit"
#define TR_LOADING                      "Laddar..."
#define TR_DELETE_THEME                 "Radera tema?"
#define TR_SAVE_THEME                   "Spara tema?"
#define TR_EDIT_COLOR                   "Redigera färg"
#define TR_BACKLIGHT_TIMER              "Timeout vid inaktivitet"
#define TR_NO_THEME_IMAGE               "Ingen temabild"

#if defined(COLORLCD)
  #define TR_MODEL_QUICK_SELECT         "Snabbval av modell"
#endif

#define TR_SELECT_TEMPLATE_FOLDER       "VÄLJ MALLKATALOG"
#define TR_SELECT_TEMPLATE              "VÄLJ MODELLMALL"
#define TR_NO_TEMPLATES                 "Det finns inga modellmallar i denna katalog"
#define TR_SAVE_TEMPLATE                "Spara som mall"
#define TR_BLANK_MODEL                  "Tom modell"
#define TR_BLANK_MODEL_INFO             "Skapa en tom modell"
#define TR_FILE_EXISTS                  "FILEN FINNS REDAN"
#define TR_ASK_OVERWRITE                "Vill du skriva över?"

#define TR_BLUETOOTH                    "Bluetooth"
#define TR_BLUETOOTH_DISC               "Upptäck"
#define TR_BLUETOOTH_INIT               "Init"
#define TR_BLUETOOTH_DIST_ADDR          "Dist addr"
#define TR_BLUETOOTH_LOCAL_ADDR         "Lokal addr"
#define TR_BLUETOOTH_PIN_CODE           "PIN-kod"
#define TR_BLUETOOTH_NODEVICES          "Inga enheter funna"
#define TR_BLUETOOTH_SCANNING           "Skannar..."
#define TR_BLUETOOTH_BAUDRATE           "BT baudrate"
#if defined(PCBX9E)
  #define TR_BLUETOOTH_MODES            "---","Aktiverad"
#else
  #define TR_BLUETOOTH_MODES            "---","Telemetri","Lärare"
#endif
#define TR_SD_INFO_TITLE                "SD INFO"
#define TR_SD_TYPE                      "Typ: "
#define TR_SD_SPEED                     "Hastighet:"
#define TR_SD_SECTORS                   "Sektorer:"
#define TR_SD_SIZE                      "Strl:"
#define TR_TYPE                         INDENT "Typ"
#define TR_GLOBAL_VARS                  "Globala variabler"
#define TR_GVARS                        "GLOBAL V."
#define TR_GLOBAL_VAR                   "Global variabel"
#define TR_MENU_GLOBAL_VARS             "GLOBALA VARIABLER"
#define TR_OWN                          "Egen"
#define TR_DATE                         "Datum"
#define TR_MONTHS                       { "Jan", "Feb", "Mar", "Apr", "Maj", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dec" }
#define TR_ROTARY_ENCODER               "R.H."
#define TR_ROTARY_ENC_MODE              TR("Rullhjulsinst.","Rullhjulsinställning")
#define TR_CHANNELS_MONITOR             "Kanalöversikt"
#define TR_MIXERS_MONITOR               "MIXERSKÄRM"
#define TR_PATH_TOO_LONG                "För lång sökväg"
#define TR_VIEW_TEXT                    "Visa text"

#define TR_FLASH_BOOTLOADER             "Skriv bootloader"
#define TR_FLASH_DEVICE                 "Flasha enhet"
#define TR_FLASH_EXTERNAL_DEVICE        "Flasha extern enhet"
#define TR_FLASH_RECEIVER_OTA           "Flasha Rx OTA"
#define TR_FLASH_RECEIVER_BY_EXTERNAL_MODULE_OTA          "Flash Rx gnm ext. OTA"
#define TR_FLASH_RECEIVER_BY_INTERNAL_MODULE_OTA          "Flash Rx gnm int. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_EXTERNAL_MODULE_OTA "Flash FC gnm ext. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_INTERNAL_MODULE_OTA "Flash FC gnm int. OTA"
#define TR_FLASH_BLUETOOTH_MODULE       TR("Flasha BT-modul", "Flasha Bluetoothmodul")
#define TR_FLASH_POWER_MANAGEMENT_UNIT  "Flash pwr mngt unit"
#define TR_DEVICE_NO_RESPONSE           TR("Device not responding", "Device not responding")
#define TR_DEVICE_FILE_ERROR            TR("Device file prob.", "Device file prob.")
#define TR_DEVICE_DATA_REFUSED          TR("Device data refused", "Device data refused")
#define TR_DEVICE_WRONG_REQUEST         TR("Device access problem", "Device access problem")
#define TR_DEVICE_FILE_REJECTED         TR("Device file refused", "Device file refused")
#define TR_DEVICE_FILE_WRONG_SIG        TR("Device file sig.", "Device file sig.")
#define TR_CURRENT_VERSION              TR("Nuvarande ver. ", "Nuvarande version: ")
#define TR_FLASH_INTERNAL_MODULE        "Flasha intern modul"
#define TR_FLASH_INTERNAL_MULTI         TR("Flasha int. Multi", "Flasha intern Multi")
#define TR_FLASH_EXTERNAL_MODULE        "Flasha extern modul"
#define TR_FLASH_EXTERNAL_MULTI         TR("Flasha ext. Multi", "Flasha extern Multi")
#define TR_FLASH_EXTERNAL_ELRS          TR("Flasha ext. ELRS", "Flasha extern ELRS")

#define TR_FIRMWARE_UPDATE_ERROR        TR("FW update Error","Firmware update error")
#define TR_FIRMWARE_UPDATE_SUCCESS      "Flash successful"
#define TR_WRITING                      "Skriver..."
#define TR_CONFIRM_FORMAT               "Formatera minnet?"
#define TR_INTERNALRF                   "Intern radiomodul"
#define TR_INTERNAL_MODULE              TR("Int. modul","Intern modul")
#define TR_EXTERNAL_MODULE              TR("Ext. modul","Extern modul")
#define TR_OPENTX_UPGRADE_REQUIRED      "EdgeTX behöver uppgraderas"
#define TR_TELEMETRY_DISABLED           "Telem. inaktiverad"
#define TR_MORE_OPTIONS_AVAILABLE       "Fler alternativ finns"
#define TR_NO_MODULE_INFORMATION        "Modulinformation saknas"
#define TR_EXTERNALRF                   "Extern radiomodul"
#define TR_FAILSAFE                     TR(INDENT "Failsafe", INDENT "Failsafeläge")
#define TR_FAILSAFESET                  "Failsafeinställning"
#define TR_REG_ID                       "Reg. ID"
#define TR_OWNER_ID                     "Ägar-ID"
#define TR_HOLD                         "Håll"
#define TR_HOLD_UPPERCASE               "HÅLL"
#define TR_NONE                         "Ingen"
#define TR_NONE_UPPERCASE               "INGEN"
#define TR_MENUSENSOR                   "SENSOR"
#define TR_POWERMETER_PEAK              "Peak"
#define TR_POWERMETER_POWER             "Power"
#define TR_POWERMETER_ATTN              "Attn"
#define TR_POWERMETER_FREQ              "Freq."
#define TR_MENUTOOLS                    "VERKTYG"
#define TR_TURN_OFF_RECEIVER            "Stäng av mottagare"
#define TR_STOPPING                     "Stoppar..."
#define TR_MENU_SPECTRUM_ANALYSER       "SPEKTRUMANALYSATOR"
#define TR_MENU_POWER_METER             "EFFEKTMÄTARE"
#define TR_SENSOR                       "SENSOR"
#define TR_COUNTRY_CODE                 "Landskod"
#define TR_USBMODE                      "USB-läge"
#define TR_JACK_MODE                    "Uttagsläge"
#define TR_VOICE_LANGUAGE               "Röstspråk"
#define TR_UNITS_SYSTEM                 "Enheter"
#define TR_EDIT                         "Redigera"
#define TR_INSERT_BEFORE                "Addera före"
#define TR_INSERT_AFTER                 "Addera efter"
#define TR_COPY                         "Kopiera"
#define TR_MOVE                         "Flytta"
#define TR_PASTE                        "Infoga"
#define TR_PASTE_AFTER                  "Klistra in efter"
#define TR_PASTE_BEFORE                 "Klistra in före"
#define TR_DELETE                       "Radera"
#define TR_INSERT                       "Addera"
#define TR_RESET_FLIGHT                 "Återställ flygning"
#define TR_RESET_TIMER1                 "Återställ timer1"
#define TR_RESET_TIMER2                 "Återställ timer2"
#define TR_RESET_TIMER3                 "Återställ timer3"
#define TR_RESET_TELEMETRY              "Återställ telemetri"
#define TR_STATISTICS                   "Statistik"
#define TR_ABOUT_US                     "Om EdgeTX"
#define TR_USB_JOYSTICK                 "USB Joystick (HID)"
#define TR_USB_MASS_STORAGE             "USB Lagring (SD)"
#define TR_USB_SERIAL                   "USB Seriell (Debug)"
#define TR_SETUP_SCREENS                "Setupskärmar"
#define TR_MONITOR_SCREENS              "Monitorer"
#define TR_AND_SWITCH                   "AND-brytare"
#define TR_SF                           "SF"
#define TR_GF                           "GF"
#define TR_ANADIAGS_CALIB               "Kalibrerade analoga"
#define TR_ANADIAGS_FILTRAWDEV          "Filterade råa analoga med avvikelse"
#define TR_ANADIAGS_UNFILTRAW           "Ofiltrerade råa analoga"
#define TR_ANADIAGS_MINMAX              "Min., max. och omfång"
#define TR_ANADIAGS_MOVE                "Rör analoga till sina ytterlägen!"
#define TR_SPEAKER                      INDENT "Högtalare"
#define TR_BUZZER                       INDENT "Summer"
#define TR_BYTES                        "byte"
#define TR_MODULE_BIND                  BUTTON(TR("Bnd", "Bind"))
#define TR_POWERMETER_ATTN_NEEDED       "Attenuator behövs"
#define TR_PXX2_SELECT_RX               "Välj Rx"
#define TR_PXX2_DEFAULT                 "<default>"
#define TR_BT_SELECT_DEVICE             "Välj enhet"
#define TR_DISCOVER                     "Upptäck"
#define TR_BUTTON_INIT                  BUTTON("Init")
#define TR_WAITING                      "Väntar..."
#define TR_RECEIVER_DELETE              "Radera mottagare?"
#define TR_RECEIVER_RESET               "Återställ mottagare?"
#define TR_SHARE                        "Dela"
#define TR_BIND                         "Binder"
#define TR_REGISTER                     TR("Reg", "Registrera")
#define TR_MODULE_RANGE                 BUTTON(TR("Tst", "Testa"))
#define TR_RECEIVER_OPTIONS             TR("RX ALTERNATIV", "MOTTAGARALTERNATIV")
#define TR_RESET_BTN                    TR(BUTTON("Nolla"), BUTTON("Återställ"))
#define TR_DEBUG                        "Debug"
#define TR_KEYS_BTN                     BUTTON(TR("Bryt.","Brytare"))
#define TR_ANALOGS_BTN                  BUTTON(TR("Ana.","Analoga"))
#define TR_TOUCH_NOTFOUND               "Pekskärm hittas ej"
#define TR_TOUCH_EXIT                   "Peka på skärmen för att avsluta"
#define TR_SET                          BUTTON(TR("Def", "Ställ in"))
#define TR_TRAINER                      "Lärare"
#define TR_CHANS                        "Kan"
#define TR_ANTENNAPROBLEM               CENTER "Fel på TX-antennen"
#if defined(COLORLCD)
  #define TR_MODELIDUSED                "ID använt i:"
#else
  #define TR_MODELIDUSED                TR("ID använt i:","Mottagar-ID använt i:")
#endif
#define TR_MODELIDUNIQUE                "ID är unikt"
#define TR_MODULE                       "Modul"
#define TR_RX_NAME                      "Rx namn"
#define TR_TELEMETRY_TYPE               "Telemetrityp"
#define TR_TELEMETRY_SENSORS            "Sensorer"
#define TR_VALUE                        "Värde"
#define TR_PERIOD                       "Period"
#define TR_INTERVAL                     "Intervall"
#define TR_REPEAT                       "Upprepa"
#define TR_ENABLE                       "Aktivera"
#define TR_TOPLCDTIMER                  "Översta LCD timer"
#define TR_UNIT                         "Enhet"
#define TR_TELEMETRY_NEWSENSOR          INDENT "Lägg till..." 
#define TR_CHANNELRANGE                 TR(INDENT "Kanalomr.", INDENT "Kanalområde")
#define TR_RXFREQUENCY                  TR("Rx frekv.", "Rx frekvens")
#define TR_AFHDS3_RX_FREQ               TR("Rx frekv", "Rx frekvens")
#define TR_AFHDS3_ONE_TO_ONE_TELEMETRY  TR("Unicast/Tel.", "Unicast/Telemetry")
#define TR_AFHDS3_ONE_TO_MANY           "Multicast"
#define TR_AFHDS3_ACTUAL_POWER          TR("Act. pow", "Actual power")
#define TR_AFHDS3_POWER_SOURCE          "Strömkälla"
#define TR_ANTENNACONFIRM1              "EXT. ANTENN"

#if defined(PCBX12S)
  #define TR_ANTENNA_MODES              "Intern","Fråga","Per modell","Intern + Extern"
#else
  #define TR_ANTENNA_MODES              "Intern","Fråga","Per modell","Extern"
#endif

#define TR_USE_INTERNAL_ANTENNA         TR("Anv int. antenn", "Använd intern antenn")
#define TR_USE_EXTERNAL_ANTENNA         TR("Anv ext. antenn", "Använd extern antenn")
#define TR_ANTENNACONFIRM2              TR("Kontr. antenn", "Kontrollera att antennen är installerad!")
#define TR_MODULE_PROTOCOL_FLEX_WARN_LINE1        "Kräver inte"
#define TR_MODULE_PROTOCOL_FCC_WARN_LINE1         "Kräver FCC"
#define TR_MODULE_PROTOCOL_EU_WARN_LINE1          "Kräver EU"
#define TR_MODULE_PROTOCOL_WARN_LINE2             "certifierad firmware"
#define TR_LOWALARM                     INDENT "Lågalarm"
#define TR_CRITICALALARM                INDENT "Kritiskt alarm"
#define TR_RSSIALARM_WARN               TR("RSSI","TELEMETRI RSSI")
#define TR_NO_RSSIALARM                 TR(INDENT "Alarm inaktiverade", INDENT "Telemetrialarm inaktiverade")
#define TR_DISABLE_ALARM                TR(INDENT "Inaktivera alarm", INDENT "Inaktivera telemetrialarm")
#define TR_POPUP                        "Popup"
#define TR_MIN                          "Min"
#define TR_MAX                          "Max"
#define TR_CURVE_PRESET                 "Förinställd..."
#define TR_PRESET                       "Lutning"
#define TR_MIRROR                       "Spegla"
#define TR_CLEAR                        "Rensa"
#define TR_RESET                        "Återställ"
#define TR_RESET_SUBMENU                "Återställ..."
#define TR_COUNT                        "Antal"
#define TR_PT                           "pt"
#define TR_PTS                          "pkt"
#define TR_SMOOTH                       "Mjuk"
#define TR_COPY_STICKS_TO_OFS           TR("Kop. spak->subtrim","Spara spakläge som subtrim")
#define TR_COPY_MIN_MAX_TO_OUTPUTS      TR("Kop. min/max för allt","Kopiera min/max/center till all output")
#define TR_COPY_TRIMS_TO_OFS            TR("Kop. trim->subtrim","Spara trimmar som subtrim")
#define TR_INCDEC                       "Öka/Minska"
#define TR_GLOBALVAR                    "Globala var"
#define TR_MIXSOURCE                    "Mixerkälla"
#define TR_CONSTANT                     "Konstant"
#define TR_PREFLIGHT_POTSLIDER_CHECK    "Av","På","Auto"
#define TR_PREFLIGHT                    "Startkontroller"
#define TR_PREFLIGHT_POTSLIDER_CHECK    "Av","På","Auto"
#define TR_CHECKLIST                    TR(INDENT "Checklista", INDENT "Visa checklista")
#define TR_AUX_SERIAL_MODE              "Serieport"
#define TR_AUX2_SERIAL_MODE             "Serieport 2"
#define TR_AUX_SERIAL_PORT_POWER        "Strömkälla"
#define TR_SCRIPT                       "Programkod"
#define TR_INPUTS                       "Inputs"
#define TR_OUTPUTS                      "Outputs"
#define STR_EEBACKUP                    "Säkerhetskopiera EEPROM"
#define STR_FACTORYRESET                "Fabriksåterställning"
#define TR_CONFIRMRESET                 "Radera ALLA modeller och inställningar?"
#define TR_TOO_MANY_LUA_SCRIPTS         "För många Lua-skript!"
#define TR_SPORT_UPDATE_POWER_MODE      "S.Port Pwr"
#define TR_SPORT_UPDATE_POWER_MODES     "Auto","På"
#define TR_NO_TELEMETRY_SCREENS         "Ingen telemetriskärm"
#define TR_TOUCH_PANEL                  "Pekskärm:"
#define TR_FILE_SIZE                    "Filstorlek"
#define TR_FILE_OPEN                    "Öppna ändå?"
#define TR_TIMER_MODES                  {TR_OFFON,TR_START,TR_THROTTLE_LABEL,TR_THROTTLE_PERCENT_LABEL,TR_THROTTLE_START}

// Horus and Taranis column headers
#define TR_PHASES_HEADERS_NAME          "Namn"
#define TR_PHASES_HEADERS_SW            "Brytare"
#define TR_PHASES_HEADERS_RUD_TRIM      "Rodertrim"
#define TR_PHASES_HEADERS_ELE_TRIM      "Höjdrodertrim"
#define TR_PHASES_HEADERS_THT_TRIM      "Gastrim"
#define TR_PHASES_HEADERS_AIL_TRIM      "Skevrodertrim"
#define TR_PHASES_HEADERS_CH5_TRIM      "Trim 5"
#define TR_PHASES_HEADERS_CH6_TRIM      "Trim 6"
#define TR_PHASES_HEADERS_FAD_IN        "Tona in"
#define TR_PHASES_HEADERS_FAD_OUT       "Tona ut"

#define TR_LIMITS_HEADERS_NAME          "Namn"
#define TR_LIMITS_HEADERS_SUBTRIM       "Subtrim"
#define TR_LIMITS_HEADERS_MIN           "Min"
#define TR_LIMITS_HEADERS_MAX           "Max"
#define TR_LIMITS_HEADERS_DIRECTION     "Riktning"
#define TR_LIMITS_HEADERS_CURVE         "Kurva"
#define TR_LIMITS_HEADERS_PPMCENTER     "PPM-center"
#define TR_LIMITS_HEADERS_SUBTRIMMODE   "Subtrim-läge"
#define TR_INVERTED                     "Inverterad"

//#define TR_CHECK_FM_TRIMS               "Kolla FL-trimmar"

// Horus footer descriptions
#define TR_LSW_DESCRIPTIONS             { "Jämförelsetyp eller funktion", "Första variabeln", "Andra variabeln eller konstant", "Andra variabeln eller konstant", "Ytterligare villkor för att raden ska aktiveras", "Minsta tid PÅ för den logiska brytaren", "Minsta varaktighet för SANT för att brytaren ska slås PÅ" }

#if defined(COLORLCD)
  // Horus layouts and widgets
  #define TR_FIRST_CHANNEL              "Första kanal"
  #define TR_FILL_BACKGROUND            "Fyll bakgrund?"
  #define TR_BG_COLOR                   "Bakgrundsfärg"
  #define TR_SLIDERS_TRIMS              "Reglage+Trimmar"
  #define TR_SLIDERS                    "Reglage"
  #define TR_FLIGHT_MODE                "Flygläge"
  #define TR_INVALID_FILE               "Ogiltig fil"
  #define TR_TIMER_SOURCE               "Timerkälla"
  #define TR_SIZE                       "Storlek"
  #define TR_SHADOW                     "Skugga"
  #define TR_ALIGN_LABEL                "Justera etikett"
  #define TR_ALIGN_VALUE                "Justera värde"
  #define TR_ALIGN_OPTS                 { "Vänster", "Mitten", "Höger" }
  #define TR_TEXT                       "Text"
  #define TR_COLOR                      "Färg"
  #define TR_MAIN_VIEW_X                "Huvudvy X"
  #define TR_PANEL1_BACKGROUND          "Panel 1 bakgrund"
  #define TR_PANEL2_BACKGROUND          "Panel 2 bakgrund"
  #define TR_WIDGET_GAUGE               "Mätare"
  #define TR_WIDGET_MODELBMP            "Modellinfo"
  #define TR_WIDGET_OUTPUTS             "Output"
  #define TR_WIDGET_TEXT                "Text"
  #define TR_WIDGET_TIMER               "Timer"
  #define TR_WIDGET_VALUE               "Värde"
#endif

// Bootloader common
#define TR_BL_USB_CONNECT_BOOT          CENTER "\011USB ansluten"
#define TR_BL_USB_CONNECTED             "USB ansluten"
#define TR_BL_USB_PLUGIN                "Eller anslut med en USB-kabel"
#define TR_BL_USB_MASS_STORE            "foer masslagring"
#define TR_BL_USB_PLUGIN_MASS_STORE     "Eller anslut med en USB-kabel foer masslagring"
#define TR_BL_WRITE_FW                  "Skriv firmware"
#define TR_BL_FORK                      "Gren:"
#define TR_BL_VERSION                   "Version:"
#define TR_BL_RADIO                     "Radio:"
#define TR_BL_EXIT                      "Avsluta"
#define TR_BL_DIR_MISSING               " Katalogen saknas"
#define TR_BL_DIR_EMPTY                 " Katalogen aer tom"

#if LCD_W >= 480
  #define TR_BL_INVALID_FIRMWARE        "Inte en giltig firmwarefil"
#elif LCD_W >= 212
  #define TR_BL_OR_PLUGIN_USB_CABLE     TR_BL_USB_PLUGIN_MASS_STORE
  #define TR_BL_HOLD_ENTER_TO_START     "\012Tryck [ENT] foer att boerja skriva  "
  #define TR_BL_INVALID_FIRMWARE        "\011Inte en giltig firmwarefil!       "
  #define TR_BL_INVALID_EEPROM          "\011Inte en giltig EEPROM-fil!        "
#else
  #define TR_BL_OR_PLUGIN_USB_CABLE     TR_BL_USB_PLUGIN
  #define TR_BL_HOLD_ENTER_TO_START     "\006Tryck [ENT] för att boerja      "
  #define TR_BL_INVALID_FIRMWARE        "\004Inte en giltig firmware!     "
  #define TR_BL_INVALID_EEPROM          "\004Inte en giltig EEPROM!       "
#endif

#if defined(PCBTARANIS)
   // Bootloader Taranis specific
  #define TR_BL_RESTORE_EEPROM          "Aaterställ EEPROM"
  #define TR_BL_WRITING_FW              CENTER "\015Skriver..."
  #define TR_BL_WRITING_COMPL           CENTER "\007Skrivning klar"
  #if defined(RADIO_COMMANDO8)
    #define TR_BL_POWER_KEY             "Tryck paa startknappen."
    #define TR_BL_FLASH_EXIT            "Avsluta flashningsläget."
  #endif
#elif defined(PCBHORUS)
   // Bootloader Horus specific
  #define TR_BL_WRITING_FW              "Skriver firmware ..."
  #define TR_BL_WRITING_COMPL           "Skrivning klar"
  #define TR_BL_SELECT_KEY              "[ENT] för att vaelja fil"
  #define TR_BL_FLASH_KEY               "Tryck [ENT] foer att flasha"
  #define TR_BL_EXIT_KEY                "[RTN] foer att avbryta"
#elif defined(PCBNV14)
   // Bootloader NV14 specific
  #define TR_BL_WRITING_FW              "Skriver firmware ..."
  #define TR_BL_WRITING_COMPL           "Skrivning klar"
  #define TR_BL_RF_USB_ACCESS           "RF USB access"
  #define TR_BL_CURRENT_FW              "Nuvarande firmware:"
  #define TR_BL_SELECT_KEY              "[R TRIM] foer att vaelja fil"
  #define TR_BL_FLASH_KEY               "Tryck [R TRIM] foer att flasha"
  #define TR_BL_EXIT_KEY                " [L TRIM] för att avsluta"
#endif

// About screen
#define TR_ABOUTUS                      "Om oss"

#define TR_CHR_HOUR                     'h'
#define TR_CHR_INPUT                    'I'   // Values between A-I will work

#define TR_BEEP_VOLUME                  "Volym Pip"
#define TR_WAV_VOLUME                   "Volym Wav"
#define TR_BG_VOLUME                    "Volym Bg"

#define TR_TOP_BAR                      "Titelrad"
#define TR_FLASH_ERASE                  "Flash raderas..."
#define TR_FLASH_WRITE                  "Flash skrivs..."
#define TR_OTA_UPDATE                   "OTA uppdatering..."
#define TR_MODULE_RESET                 "Module reset..."
#define TR_UNKNOWN_RX                   "Okänd Rx"
#define TR_UNSUPPORTED_RX               "Rx stöds ej"
#define TR_OTA_UPDATE_ERROR             "OTA uppdateringsfel"
#define TR_DEVICE_RESET                 "Device reset..."
#define TR_ALTITUDE                     INDENT "Höjd"
#define TR_SCALE                        "Skala"
#define TR_VIEW_CHANNELS                "Visa kanaler"
#define TR_VIEW_NOTES                   "Visa anteckningar"
#define TR_MODEL_SELECT                 "Välj modell"
#define TR_ID                           "ID"
#define TR_PRECISION                    "Precision"
#define TR_RATIO                        "Ratio"
#define TR_FORMULA                      "Formel"
#define TR_CELLINDEX                    "Cellindex"
#define TR_LOGS                         "Loggar"
#define TR_OPTIONS                      "Options"
#define TR_FIRMWARE_OPTIONS             "Firmwarefunktioner"

#define TR_ALTSENSOR                    "Höjdsensor"
#define TR_CELLSENSOR                   "Cellsensor"
#define TR_GPSSENSOR                    "GPS-sensor"
#define TR_CURRENTSENSOR                "Sensor"
#define TR_AUTOOFFSET                   "Auto offset"
#define TR_ONLYPOSITIVE                 "Positiv"
#define TR_FILTER                       "Filter"
#define TR_TELEMETRYFULL                "Alla telemetriplatser upptagna!"

#define TR_INVERTED_SERIAL              INDENT "Inverterad"
#define TR_IGNORE_INSTANCE              TR(INDENT "Ej inst.", INDENT "Ignorera instansfel")
#define TR_DISCOVER_SENSORS             "Sök nya"
#define TR_STOP_DISCOVER_SENSORS        "Avbryt sökning"
#define TR_DELETE_ALL_SENSORS           "Ta bort alla sensorer"
#define TR_CONFIRMDELETE                "Ta bort alla?"
#define TR_SELECT_WIDGET                "Välj widget"
#define TR_REMOVE_WIDGET                "Ta bort widget"
#define TR_WIDGET_SETTINGS              "Widgetinställningar"
#define TR_WIDGET_FULLSCREEN            "Hel skärm"
#define TR_REMOVE_SCREEN                "Ta bort huvudvy"

#if LCD_W > LCD_H
  #define TR_SETUP_WIDGETS              "Konfigurera widgets"
#else
  #define TR_SETUP_WIDGETS              "Konfig. widgets"
#endif

#define TR_USER_INTERFACE               "Användargränssnitt"
#define TR_THEME                        "Tema"
#define TR_SETUP                        "Konfigurera"
#define TR_LAYOUT                       "Layout"
#define TR_ADD_MAIN_VIEW                "Lägg till huvudvy"
#define TR_BACKGROUND_COLOR             "Bakgrundsfärg"
#define TR_MAIN_COLOR                   "Huvudfärg"
#define TR_BAR2_COLOR                   "Sekundär stapelfärg"
#define TR_BAR1_COLOR                   "Primär stapelfärg"
#define TR_TEXT_COLOR                   "Textfärg"
#define TR_TEXT_VIEWER                  "Textgranskare"

#define TR_MENU_INPUTS                  STR_CHAR_INPUT "Input"
#define TR_MENU_LUA                     STR_CHAR_LUA "Lua-skript"
#define TR_MENU_STICKS                  STR_CHAR_STICK "Spakar"
#define TR_MENU_POTS                    STR_CHAR_POT "Vred"
#define TR_MENU_MAX                     STR_CHAR_FUNCTION "MAX"
#define TR_MENU_HELI                    STR_CHAR_CYC "Cyklisk"
#define TR_MENU_TRIMS                   STR_CHAR_TRIM "Trimm"
#define TR_MENU_SWITCHES                STR_CHAR_SWITCH "Brytare"
#define TR_MENU_LOGICAL_SWITCHES        STR_CHAR_SWITCH "Logiska brytare"
#define TR_MENU_TRAINER                 STR_CHAR_TRAINER "Lärare"
#define TR_MENU_CHANNELS                STR_CHAR_CHANNEL "Kanaler"
#define TR_MENU_GVARS                   STR_CHAR_SLIDER "GVars"
#define TR_MENU_TELEMETRY               STR_CHAR_TELEMETRY "Telemetri"
#define TR_MENU_DISPLAY                 "DISPLAY"
#define TR_MENU_OTHER                   "Övrigt"
#define TR_MENU_INVERT                  "Invertera"
#define TR_JITTER_FILTER                "ADC-filter"
#define TR_DEAD_ZONE                    "Dödläge"
#define TR_RTC_CHECK                    TR("Kolla RTC", "Kolla RTC-batteriet")
#define TR_AUTH_FAILURE                 "Auth-failure"
#define TR_RACING_MODE                  "Tävlingsläge"

#define TR_USE_THEME_COLOR              "Använd temafärg"

#define TR_ADD_ALL_TRIMS_TO_SUBTRIMS    "Addera alla trimmar till subtrimmar"

#if LCD_W > LCD_H
  #define TR_OPEN_CHANNEL_MONITORS      "Öppna kanalmonitorn" 
#else
  #define TR_OPEN_CHANNEL_MONITORS      "Öppna kanalmon." 
#endif

#define TR_DUPLICATE                    "Duplicera"
#define TR_ACTIVATE                     "Aktivera"
#define TR_RED                          "Röd"
#define TR_BLUE                         "Blå"
#define TR_GREEN                        "Grön"
#define TR_COLOR_PICKER                 "Färgväljare"
#define TR_EDIT_THEME_DETAILS           "Ändra temadetaljer"
#define TR_AUTHOR                       "Författare"
#define TR_DESCRIPTION                  "Beskrivning"
#define TR_SAVE                         "Spara"
#define TR_CANCEL                       "Avbryt"
#define TR_EDIT_THEME                   "ÄNDRA TEMA"
#define TR_DETAILS                      "Detaljer"
#define TR_THEME_EDITOR                 "TEMAN"

// Main menu
#define TR_MAIN_MENU_SELECT_MODEL       "Välj\nmodell"
#define TR_MAIN_MENU_MODEL_NOTES        "Modell-\nanteckn."
#define TR_MAIN_MENU_CHANNEL_MONITOR    "Kanal-\nmonitor"
#define TR_MAIN_MENU_MODEL_SETTINGS     "Modell-\ninställn."
#define TR_MAIN_MENU_RADIO_SETTINGS     "Radio-\ninställn."
#define TR_MAIN_MENU_SCREEN_SETTINGS    "Skärm-\ninställn."
#define TR_MAIN_MENU_RESET_TELEMETRY    "Återställ\ntelemetri"
#define TR_MAIN_MENU_STATISTICS         "Statistik"
#define TR_MAIN_MENU_ABOUT_EDGETX       "Om\nEdgeTX"
// End Main menu

// Voice in native language
#define TR_VOICE_ENGLISH                "Engelska"
#define TR_VOICE_CHINESE                "Kinesiska"
#define TR_VOICE_CZECH                  "Tjeckiska"
#define TR_VOICE_DANISH                 "Danska"
#define TR_VOICE_DEUTSCH                "Tyska"
#define TR_VOICE_DUTCH                  "Holländska"
#define TR_VOICE_ESPANOL                "Spanska"
#define TR_VOICE_FRANCAIS               "Franska"
#define TR_VOICE_HUNGARIAN              "Ungerska"
#define TR_VOICE_ITALIANO               "Italienska"
#define TR_VOICE_POLISH                 "Polska"
#define TR_VOICE_PORTUGUES              "Portugisiska"
#define TR_VOICE_RUSSIAN                "Ryska"
#define TR_VOICE_SLOVAK                 "Slovakiska"
#define TR_VOICE_SWEDISH                "Svenska"
#define TR_VOICE_TAIWANESE              "Taiwanesiska"
