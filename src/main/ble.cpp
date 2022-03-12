
#include "ble.h"

BLEPeripheral blePeripheral;

// PoulpiService
BLEService poulpiService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEIntCharacteristic waterReminderCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic sportReminderCharacteristic("19B10011-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic meditationReminderCharacteristic("19B10100-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic taskReminderCharacteristic("19B10101-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

BLEIntCharacteristic waterGoalCharacteristic("19B10110-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLECharacteristic sportListCharacteristic("19B10111-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite, 1000);
BLEIntCharacteristic sportMusicCharacteristic("19B11001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLECharacteristic taskListCharacteristic("19B11000-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite, 1000);

void Ble::setup() {
  // Set name
  blePeripheral.setLocalName("Poulpi");
  blePeripheral.setDeviceName("Poulpi");

  // Set the service with characteristics properly
  blePeripheral.setAdvertisedServiceUuid(poulpiService.uuid());
  blePeripheral.addAttribute(poulpiService);
  blePeripheral.addAttribute(waterReminderCharacteristic);
  waterReminderCharacteristic.setValue(Switch::ON);
  blePeripheral.addAttribute(sportReminderCharacteristic);
  sportReminderCharacteristic.setValue(Switch::ON);
  blePeripheral.addAttribute(meditationReminderCharacteristic);
  meditationReminderCharacteristic.setValue(Switch::ON);
  blePeripheral.addAttribute(taskReminderCharacteristic);
  taskReminderCharacteristic.setValue(Switch::ON);

  blePeripheral.addAttribute(waterGoalCharacteristic);
  waterGoalCharacteristic.setValue(DEFAULT_WATER_GOAL_IN_ML);
  blePeripheral.addAttribute(sportListCharacteristic);
  sportListCharacteristic.setValue("Define me in the app!");
  blePeripheral.addAttribute(taskListCharacteristic);
  taskListCharacteristic.setValue("Define me in the app!");

  blePeripheral.addAttribute(sportMusicCharacteristic);
  sportMusicCharacteristic.setValue(Music::TAKE_ON_ME);

  blePeripheral.begin();
}

void Ble::loop(States* states) {
    BLECentral central = blePeripheral.central();
    if(central){
        if (waterReminderCharacteristic.written()) {
            // TODO
        }
        if (sportReminderCharacteristic.written()) {
            // TODO
        }
        if (meditationReminderCharacteristic.written()) {
            // TODO
        }
        if (taskReminderCharacteristic.written()) {
            // TODO
        }

        if (waterGoalCharacteristic.written()) {
            states->waterGoal = waterGoalCharacteristic.value();
        }
        if (sportListCharacteristic.written()) {
            states->sportExercices = LocalUtils::split(String((char *)sportListCharacteristic.value()), CARRIAGE_RETURN);
            states->sportExercicesAmount = LocalUtils::countItemsInArray(states->sportExercices);
        }
        if (sportMusicCharacteristic.written()) {
            states->sportMusic = sportMusicCharacteristic.value();
        }
        if (taskListCharacteristic.written()) {
            states->tasks = LocalUtils::split(String((char *)taskListCharacteristic.value()), CARRIAGE_RETURN);
            states->tasksAmount = LocalUtils::countItemsInArray(states->tasks);
        }
    }
}
