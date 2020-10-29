# Weather-Scrapper
Arduino UnoR3 + Esp8266 (Esp-01) + LCD 

## Parts 🔧🔨

* [Arduino Elegoo Super Starter Kit](https://www.amazon.ca/Elegoo-Project-Starter-Tutorial-Arduino/dp/B01D8KOZF4/ref=sr_1_1_sspa?dchild=1&keywords=arduino&qid=1603991079&s=electronics&sr=1-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyNTlMVTJPSjZBUklUJmVuY3J5cHRlZElkPUEwNDYwNTY1MVhHMUM4TklJS1NIJmVuY3J5cHRlZEFkSWQ9QTA5MTU0MDIyTlVaRkYwNUZNRFY1JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)

* [Diymall Esp8266 (Esp-01) Wifi Module](https://www.amazon.ca/Diymall%C2%AE-Esp8266-Wireless-Transceiver-Mega2560/dp/B00O34AGSU/ref=sr_1_1?dchild=1&keywords=diymall+esp8266&qid=1603991104&s=electronics&sr=1-1)

## Guide 📃
You can find resources online for setting up your Esp8266 (Esp-01) WiFi Module. This includes running AT-Commands as well as flashing new software on to the module. The Esp8266 is an extremly versatile WiFi Module packed with some handy features in a low-cost chip.
* [Technical Overview](https://nurdspace.nl/ESP8266#Introduction)
* [Github Library](https://github.com/sleemanj/ESP8266_Simple)
* [Youtube Tutorial](https://www.youtube.com/watch?v=qU76yWHeQuw)

### Flashing Arduino Code on to Esp8266 (Esp-01) 📶
To flash the WiFi Module ensure you have the following wirings connected:
| Esp8266        | Arduino      |
| ------------- |:-------------:| 
| VCC           | 3.3v          | 
| Ground        | Ground        |   
| Tx            |Tx             | 
| Rx            |Rx             | 
| CHPD(Enable)  |3.3v           | 
| GPIO          |Ground         | 
|               |Reset - Ground | 

**Arduino IDE setup:**
* In File/Preferences/Additional Boards Manager URLs:, add the following URL, http://arduino.esp8266.com/stable/package_esp8266com_index.json
* In Tools/Boards click on Board Manager and download the Esp8266 library. I used version 2.5 because it was the only library that worked with my module
* Change the Baudrate of the board in the serial monitor and Board Manager. Mine worked ad 115200
* Select generic Esp8266 module and upload the code.
* Once the code is uploaded open the Serial Monitor and check what the board is outputting
* *When flashing the WiFi Module with new code ensure you unplig the VCC power cable and replug it back in. This Should reboot the WiFi Module into Flash mode while clearing its memory*

### Uploading Code to Arduino for LCD 📺
To upload code to the Arduino board ensure you have the following wirings connected:
| Esp8266        | Arduino      |
| ------------- |:-------------:| 
| VCC           | 3.3v          | 
| Ground        | Ground        |   
| Tx            |Tx             | 
| Rx            |Rx             | 
| CHPD(Enable)  |3.3v           | 
| GPIO          |Ground         | 
|               |Reset - Nothing| 

**Arduino IDE setup:**
* Ensure the LCD library is imported
* In Tools/Boards change the board to Arduino Uno 
* Upload the code
* Once the code is uploaded **Switch the Tx and Rx cables** This will allow the Arduino board to receive and transmit data to the LCD screen
