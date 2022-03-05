/*
 * Copyright (c) 2016 Intel Corporation.  All rights reserved.
 * See the bottom of this file for the license terms.
 */

/*
 * Sketch: LedControl.ino
 *
 * Description:
 *   This is a Central sketch that looks for a particular Sevice with a
 *   certain Characteristic from a Peripheral.  Upon succesful discovery,
 *   it reads the state of a button and write that value to the
 *   Peripheral Characteristic.
 *
 * Notes:
 *
 *  - Expected Peripheral Service: 19b10000-e8f2-537e-4f6c-d104768a1214
 *  - Expected Peripheral Characteristic: 19b10001-e8f2-537e-4f6c-d104768a1214
 *  - Expected Peripheral sketch:
 *
 */

#include <CurieBLE.h>
#include <ChainableLED.h>

#define NUM_LEDS 2
#define CHAINABLE_LEDS_POS 6
#define CHAINABLE_LEDS_DATA (CHAINABLE_LEDS_POS + 1)

ChainableLED leds(CHAINABLE_LEDS_POS, CHAINABLE_LEDS_DATA, NUM_LEDS);

BLEPeripheral blePeripheral;

// EyeService
BLEService poulpiEyeService = "19B10000-E8F2-537E-4f6C-D104768A1214";
BLEUnsignedCharCharacteristic winkEyeCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  leds.init();

  // Set up BLE
  // initialize the BLE hardware
  blePeripheral.setLocalName("Poulpi");
  blePeripheral.setDeviceName("Poulpi");

  // Set EyeService and itscharacteristics
  blePeripheral.setAdvertisedServiceUuid(poulpiEyeService.uuid());
  blePeripheral.addAttribute(winkEyeCharacteristic);
 
  blePeripheral.begin();
  
  Serial.println("BLE Peripheral initialized");
}

void loop() {
  // check if a peripheral has been discovered
  BLECentral central = blePeripheral.central();
  if (central)
  {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    if (winkEyeCharacteristic.written()) {
      // TODO: make enumeration 0: off and 1: on
      if(winkEyeCharacteristic.value() == 0) {
        for (byte i=0; i<NUM_LEDS; i++) {
          leds.setColorHSL(i, 0.358f, 1.0f, 0.5f);
        }
      }
      else {
        for (byte i=0; i<NUM_LEDS; i++) {
          leds.setColorHSL(i, 0.270f, 0.0f, 0.0f);
        }
      }
    }
  }
  delay(100);
}
