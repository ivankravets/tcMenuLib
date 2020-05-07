/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
*/

#include <tcMenu.h>
#include "unoSsd1306Ascii_menu.h"

// Global variable declarations

const PROGMEM ConnectorLocalInfo applicationInfo = { "Uno1306Ascii", "c4858c2f-4134-4597-a7a0-b6719631a99b" };
SSD1306AsciiRenderer renderer(20, Arial14, System5x7);

// Global Menu Item declarations

ListRuntimeMenuItem menuListItem(11, 10, fnListItemRtCall, NULL);
const AnalogMenuInfo PROGMEM minfoStatusTemprature = { "Temprature", 9, 0xFFFF, 255, NO_CALLBACK, -40, 2, "C" };
AnalogMenuItem menuStatusTemprature(&minfoStatusTemprature, 0, NULL);
const FloatMenuInfo PROGMEM minfoStatusVoltageIn = { "Voltage In", 8, 0xFFFF, 0, NO_CALLBACK };
FloatMenuItem menuStatusVoltageIn(&minfoStatusVoltageIn, &menuStatusTemprature);
const FloatMenuInfo PROGMEM minfoStatusPowerUse = { "Power Use", 7, 0xFFFF, 2, NO_CALLBACK };
FloatMenuItem menuStatusPowerUse(&minfoStatusPowerUse, &menuStatusVoltageIn);
const SubMenuInfo PROGMEM minfoStatus = { "Status", 6, 0xFFFF, 0, NO_CALLBACK };
RENDERING_CALLBACK_NAME_INVOKE(fnStatusRtCall, backSubItemRenderFn, "Status", -1, NO_CALLBACK)
BackMenuItem menuBackStatus(fnStatusRtCall, &menuStatusPowerUse);
SubMenuItem menuStatus(&minfoStatus, &menuBackStatus, &menuListItem);
const AnyMenuInfo PROGMEM minfoPressMe = { "Press me", 10, 0xFFFF, 0, onActionPressed };
ActionMenuItem menuPressMe(&minfoPressMe, &menuStatus);
const BooleanMenuInfo PROGMEM minfoStandby = { "Standby", 5, 10, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuStandby(&minfoStandby, false, &menuPressMe);
const AnalogMenuInfo PROGMEM minfoBlue = { "Blue", 4, 8, 100, NO_CALLBACK, 0, 1, "%" };
AnalogMenuItem menuBlue(&minfoBlue, 0, &menuStandby);
const AnalogMenuInfo PROGMEM minfoGreen = { "Green", 3, 6, 100, NO_CALLBACK, 0, 1, "%" };
AnalogMenuItem menuGreen(&minfoGreen, 0, &menuBlue);
const AnalogMenuInfo PROGMEM minfoRed = { "Red", 2, 4, 100, NO_CALLBACK, 0, 1, "%" };
AnalogMenuItem menuRed(&minfoRed, 0, &menuGreen);
const AnalogMenuInfo PROGMEM minfoBrightness = { "Brightness", 1, 2, 100, NO_CALLBACK, 0, 1, "%" };
AnalogMenuItem menuBrightness(&minfoBrightness, 0, &menuRed);


// Set up code

void setupMenu() {
    menuStatusPowerUse.setReadOnly(true);
    menuStatusVoltageIn.setReadOnly(true);
    menuStatusTemprature.setReadOnly(true);

    renderer.setGraphicsDevice(&gfx);
    switches.initialise(ioUsingArduino(), true);
    menuMgr.initForEncoder(&renderer, &menuBrightness, 2, 3, A3);
    remoteServer.begin(&Serial, &applicationInfo);
}
