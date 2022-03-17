
#include "ble.h"
#include "localUtils.h"

BLEPeripheral blePeripheral;

// PoulpiService
BLEService poulpiService("19B10000-E8F2-537E-4f6C-D104768A1214");
BLEIntCharacteristic switchReminderCharacteristic("19B10001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEIntCharacteristic waterGoalCharacteristic("19B10110-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);
BLEShortCharacteristic sportMusicCharacteristic("19B11001-E8F2-537E-4f6C-D104768A1214", BLERead | BLEWrite);

void Ble::setup()
{
    // Set name
    blePeripheral.setLocalName(DEVICE_NAME_ON_BLE);
    blePeripheral.setDeviceName(DEVICE_NAME_ON_BLE);

    // Set the service with characteristics properly
    blePeripheral.setAdvertisedServiceUuid(poulpiService.uuid());
    blePeripheral.addAttribute(poulpiService);
    blePeripheral.addAttribute(switchReminderCharacteristic);
    switchReminderCharacteristic.setValue(SwitchReminders::WATER_REMINDER_ON);
    blePeripheral.addAttribute(waterGoalCharacteristic);
    waterGoalCharacteristic.setValue(DEFAULT_WATER_GOAL_IN_ML);
    blePeripheral.addAttribute(sportMusicCharacteristic);
    sportMusicCharacteristic.setValue(Music::TAKE_ON_ME);

    /*
    waterReminderCharacteristic : 00010001          'a'
    sportReminderCharacteristic : 00010011          'b'
    meditationReminderCharacteristic : 00010100     'c'
    taskReminderCharacteristic : 00010101           'd'
    waterGoalCharacteristic : 00010110              'e'
    sportMusicCharacteristic : 00011001             'f'
    */
    blePeripheral.begin();
}

void Ble::loop(States *states)
{
    BLECentral central = blePeripheral.central();
    if (central)
    {
        states->deviceConnectedOnce = true;

        if (switchReminderCharacteristic.written())
        {
            SwitchReminders value = (SwitchReminders)switchReminderCharacteristic.value();
            if (value == SwitchReminders::MEDITATION_REMINDER_OFF || value == SwitchReminders::MEDITATION_REMINDER_ON)
            {
                states->waterReminderIsActive = value == SwitchReminders::MEDITATION_REMINDER_ON;
            }
            if (value == SwitchReminders::WATER_REMINDER_OFF || value == SwitchReminders::WATER_REMINDER_ON)
            {
                states->waterReminderIsActive = value == SwitchReminders::WATER_REMINDER_ON;
            }
            if (value == SwitchReminders::TASK_REMINDER_OFF || value == SwitchReminders::TASK_REMINDER_ON)
            {
                states->waterReminderIsActive = value == SwitchReminders::TASK_REMINDER_ON;
            }
            if (value == SwitchReminders::SPORT_REMINDER_OFF || value == SwitchReminders::SPORT_REMINDER_ON)
            {
                states->waterReminderIsActive = value == SwitchReminders::SPORT_REMINDER_ON;
            }
        }
        if (waterGoalCharacteristic.written())
        {
            states->waterGoal = waterGoalCharacteristic.value();
        }
        if (sportMusicCharacteristic.written())
        {
            states->sportMusic = sportMusicCharacteristic.value();
        }
    }
}
