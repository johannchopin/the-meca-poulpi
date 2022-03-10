#include <Arduino.h>
#include "constants.h"
#include "ble.h"
#include <CurieBLE.h>

BLEPeripheral blePeripheral;

// PoulpiService
BLEService poulpiService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEUnsignedIntCharacteristic waterGoalCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

void Ble::setup() {
  // Set name
  blePeripheral.setLocalName("Poulpi");
  blePeripheral.setDeviceName("Poulpi");

  // Set the service with characteristics properly
  blePeripheral.setAdvertisedServiceUuid(poulpiService.uuid());
  blePeripheral.addAttribute(poulpiService);
  blePeripheral.addAttribute(waterGoalCharacteristic);
  waterGoalCharacteristic.setValue(DEFAULT_WATER_TO_DRINK_IN_ML);

  blePeripheral.begin();
}

void Ble::loop(States* states) {
    BLECentral central = blePeripheral.central();
    if(central){
        if (waterGoalCharacteristic.written()) {
            states->waterObjective = waterGoalCharacteristic.value();
        }
    }
}
