# the-meca-poulpi

## Getting started

## Components

### ChainableLED
Checkout the library https://github.com/pjpmarques/ChainableLED  
[Download v1.3](https://github.com/pjpmarques/ChainableLED/releases/tag/v1.3)

### Grove_LCD_RGB_Backlight
Checkout the doc https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight  
[Download (last version)](https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight/archive/refs/heads/master.zip)  
Rename the zip to "rgb_lcd.zip" before importing in Arduino IDE

### Grove-LED_Bar
Checkout the doc https://github.com/Seeed-Studio/Grove_LED_Bar  
[Download (last version)](https://github.com/Seeed-Studio/Grove_LED_Bar/archive/refs/tags/1.0.0.zip) -> because the last tagged version has a bug
Rename the zip to "Grove_LED_Bar.zip" before importing in Arduino IDE

### Grove-Servo
Checkout the doc https://wiki.seeedstudio.com/Grove-Servo/  
[Download (last version)](https://github.com/Seeed-Studio/Seeed_PCA9685/archive/refs/heads/master.zip)  
Rename the zip to "Servo.zip" before importing in Arduino IDE

## Last Sprint

* [x] Potentiomètre (inverser les valeurs)
* [x] Ajuster screen avec les dernières features
* [x] (dans un état de rappel) 
    * [x] Primary Button - > accepte l'activité
* [x] (dans un état de rappel) -> stateSwitchButtonstateSwitchButton -> décline l'activité -> retour au state SLEEPY
* [ ] Les reminders doivent être évité lorsque leur state dans "isActive" est à faux (cf: goToNextReminder)
* [ ] bug: dans un state REMINDER, appuyer sur le bouton bleu fait passer le poulpi dans un mauvais state
  - au bout d'un petit nombre d'interaction avec le bouton bleu, le state `DRINKING_WATER` est 'remplacé' par le state `DOING_SPORT` (je suppose un problème d'incrémentation à un endroit du code)
* [x] Potentiometer: refresh at a rate instead of waiting for potentiometer modifications 
