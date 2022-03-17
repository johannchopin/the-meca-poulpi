
#include "ble.h"
#include "localUtils.h"

BLEPeripheral blePeripheral;

// PoulpiService
/*
BLEService poulpiService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEIntCharacteristic waterReminderCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic sportReminderCharacteristic("19B10011-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic meditationReminderCharacteristic("19B10100-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic taskReminderCharacteristic("19B10101-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

BLEIntCharacteristic waterGoalCharacteristic("19B10110-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic sportMusicCharacteristic("19B11001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
*/


BLEService poulpiService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEUnsignedCharCharacteristic switchReminderCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic waterGoalCharacteristic("19B10110-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEShortCharacteristic sportMusicCharacteristic("19B11001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);


void Ble::setup()
{
    Serial.print("Before poulpi ble is set: ");
    Serial.println(availableMemory());
    // Set name
    blePeripheral.setLocalName("PoulpiB");
    Serial.print("setLocalName: ");
    Serial.println(availableMemory());
    blePeripheral.setDeviceName("PoulpiB");
    Serial.print("setDeviceName: ");
    Serial.println(availableMemory());

    // Set the service with characteristics properly
    
    blePeripheral.setAdvertisedServiceUuid(poulpiService.uuid());
    blePeripheral.addAttribute(poulpiService);
    Serial.print("After setAdvertisedServiceUid and PoulpiService: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(switchReminderCharacteristic);
    switchReminderCharacteristic.setValue(Switch::WATER_REMINDER_ON);
    Serial.print("ReminderCharacteristic: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(waterGoalCharacteristic);
    waterGoalCharacteristic.setValue(DEFAULT_WATER_GOAL_IN_ML);
    Serial.print("After waterGoalCharacteristic attribute is added: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(sportMusicCharacteristic);
    sportMusicCharacteristic.setValue(Music::TAKE_ON_ME);
    Serial.print("sportMusicCharacteristic: ");
    Serial.println(availableMemory());

    /*
    waterReminderCharacteristic : 00010001          'a'
    sportReminderCharacteristic : 00010011          'b'
    meditationReminderCharacteristic : 00010100     'c'
    taskReminderCharacteristic : 00010101           'd'
    waterGoalCharacteristic : 00010110              'e'
    sportMusicCharacteristic : 00011001             'f'
    */

    /*
    blePeripheral.setAdvertisedServiceUuid(poulpiService.uuid());
    blePeripheral.addAttribute(poulpiService);
    Serial.print("After setAdvertisedServiceUid and PoulpiService: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(waterReminderCharacteristic);
    waterReminderCharacteristic.setValue(Switch::ON);
    Serial.print("ReminderCharacteristic: ");
    Serial.println(availableMemory());

    blePeripheral.addAttribute(sportReminderCharacteristic);
    sportReminderCharacteristic.setValue(Switch::ON);
    Serial.print("sportReminderCharacteristic: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(meditationReminderCharacteristic);
    meditationReminderCharacteristic.setValue(Switch::ON);
    Serial.print("meditationReminderCharacteristic: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(taskReminderCharacteristic);
    taskReminderCharacteristic.setValue(Switch::ON);
    Serial.print("After taskReminderCharacteristic attribute is added: ");
    Serial.println(availableMemory());

    blePeripheral.addAttribute(waterGoalCharacteristic);
    waterGoalCharacteristic.setValue(DEFAULT_WATER_GOAL_IN_ML);
    Serial.print("After waterGoalCharacteristic attribute is added: ");
    Serial.println(availableMemory());
    blePeripheral.addAttribute(sportMusicCharacteristic);
    sportMusicCharacteristic.setValue(Music::TAKE_ON_ME);
    */
    

    blePeripheral.begin();
    Serial.print("After ble begin: ");
    Serial.println(availableMemory());
}

void Ble::loop(States *states)
{
    BLECentral central = blePeripheral.central();
    if (central)
    {
        states->deviceConnectedOnce = true;
        // if (waterReminderCharacteristic.written())
        // {
        //    states->waterReminderIsActive = waterReminderCharacteristic.value() == Switch::ON;
        // }
        // if (sportReminderCharacteristic.written())
        // {
        //     states->sportReminderIsActive = sportReminderCharacteristic.value() == Switch::ON;
        // }
        // if (meditationReminderCharacteristic.written())
        // {
        //     states->meditationReminderIsActive = meditationReminderCharacteristic.value() == Switch::ON;
        // }
        // if (taskReminderCharacteristic.written())
        // {
        //     states->taskReminderIsActive = taskReminderCharacteristic.value() == Switch::ON;
        // }

        //if (waterGoalCharacteristic.written())
        //{
            //states->waterGoal = waterGoalCharacteristic.value();
        //}
        // if (sportMusicCharacteristic.written())
        // {
        //     states->sportMusic = sportMusicCharacteristic.value();
        // }
    }
}
