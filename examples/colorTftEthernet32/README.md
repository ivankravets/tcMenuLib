# Colour ILI9431 TFT example with Ethernet control

 This example shows a more complex menu with the following components.
 
 * 320x240 ILI9431 screen controlled via Adafruit_GFX library.
 * Rotary encoder wired via a PCF8574 IO expander
 * I2C EEPROM device to load and save menu.
 * Ethernet shield for MKR range attached.

 Out of the box this is built for an MKR board with an I2C 8574 expander and an I2C EEPROM also attached. For simplicity it does not use DHCP to configure the network interface. Just change the address to one within your networks range.

 The files in this example are as follows:

 * `colorTftEthernet.emf` the menu editor designer file, used only to load menu into the designer.
 * `colorTftEthernet32.ino` the main sketch file, this will be modified by designer when new callbacks are added.
 * `EthernetTransport.cpp` and `.h` contain the ethernet plugin for tcMenu and should not be altered. Rewritten each code generation
 * `tcMenuAdaFruitGfx.cpp` and `.h` contain the graphics drawing plugin and should not be altered. Rewritten each code generation.
 * `colorTftEthernet32_menu.cpp` and `.h` contain the definitions of the menu item, and should not be altered. Rewritten each code generation.
 