#include "constants.h"
#include "ble.h"
#include <string.h>
#include <CurieBLE.h>

BLEPeripheral blePeripheral;

// EyeService
BLEService poulpiEyeService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEUnsignedCharCharacteristic winkEyeCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

void Ble::setup() {
  // Set name
  blePeripheral.setLocalName("Poulpi");
  blePeripheral.setDeviceName("Poulpi");

  // Set EyeService and eye characteristic toggle
  blePeripheral.setAdvertisedServiceUuid(poulpiEyeService.uuid());
  blePeripheral.addAttribute(poulpiEyeService);
  blePeripheral.addAttribute(winkEyeCharacteristic);
  winkEyeCharacteristic.setValue(0);

  blePeripheral.begin();
}

void Ble::loop(States* states) {
    BLECentral central = blePeripheral.central();
    if(central){
        if (winkEyeCharacteristic.written()) {
            states->winkEye = winkEyeCharacteristic.value();
        }
    }
}
