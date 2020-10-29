
//https://techtutorialsx.com/2018/03/17/esp32-arduino-getting-weather-data-from-api/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//Network information__________________
const char* ssid = "";
const char* password = "";

//API information__________________________
const String endpoint = "";
const String key = "";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Baud Rate of ESP8266
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");


}

void loop() {

  // put your main code here, to run repeatedly:
  if ((WiFi.status() == WL_CONNECTED)) {//Check the current connection status
    HTTPClient http;

    //Weather____________________________________________________________________________________________________________________________________________
    http.begin(endpoint + key); //Send request to url with API key
    int httpCode = http.GET(); //Make actual request
    if (httpCode > 0) { //Check for the returning code
      String payload = http.getString();
      //Serial.println(httpCode);
      //Serial.println(payload);

      //Parsing JSON____________________________________________________________________________________
      //Visit https://arduinojson.org/v5/assistant/ for a parsing assistant that breaks down the code_____________
      const size_t capacity = JSON_ARRAY_SIZE(2) + 2 * JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(14) + 480;
      DynamicJsonBuffer jsonBuffer(capacity);

      JsonObject& root = jsonBuffer.parseObject(http.getString());

      float coord_lon = root["coord"]["lon"]; // -75.7
      float coord_lat = root["coord"]["lat"]; // 45.41

      JsonObject& weather_0 = root["weather"][0];
      int weather_0_id = weather_0["id"]; // 501
      const char* weather_0_main = weather_0["main"]; // "Rain"
      const char* weather_0_description = weather_0["description"]; // "moderate rain"
      const char* weather_0_icon = weather_0["icon"]; // "10d"

      JsonObject& weather_1 = root["weather"][1];
      int weather_1_id = weather_1["id"]; // 701
      const char* weather_1_main = weather_1["main"]; // "Mist"
      const char* weather_1_description = weather_1["description"]; // "mist"
      const char* weather_1_icon = weather_1["icon"]; // "50d"

      const char* base = root["base"]; // "stations"

      JsonObject& main = root["main"];
      float main_temp = main["temp"]; // 21.01
      float main_feels_like = main["feels_like"]; // 22.89
      float main_temp_min = main["temp_min"]; // 20.56
      float main_temp_max = main["temp_max"]; // 21.11
      int main_pressure = main["pressure"]; // 1010
      int main_humidity = main["humidity"]; // 94

      int visibility = root["visibility"]; // 6437

      float wind_speed = root["wind"]["speed"]; // 2.6
      int wind_deg = root["wind"]["deg"]; // 100

      float rain_1h = root["rain"]["1h"]; // 2.04

      int clouds_all = root["clouds"]["all"]; // 90

      long dt = root["dt"]; // 1596573806

      JsonObject& sys = root["sys"];
      int sys_type = sys["type"]; // 1
      int sys_id = sys["id"]; // 872
      const char* sys_country = sys["country"]; // "Country"
      long sys_sunrise = sys["sunrise"]; // 1596534663
      long sys_sunset = sys["sunset"]; // 1596587196

      int timezone = root["timezone"]; // -14400
      long id = root["id"]; // 6094817
      const char* name = root["name"]; // "City"
      int cod = root["cod"]; // 200

      Serial.print(String(weather_0_main));
      Serial.print(String(","));
      Serial.print(String(main_temp));
      Serial.print(String(","));
      Serial.print(String(main_temp_max));
      Serial.print(String(","));
      Serial.print(String(main_temp_min));


      digitalWrite(LED_BUILTIN, LOW); //Turn on LED on ESP8266 when Updating
      delay(2000);
      digitalWrite(LED_BUILTIN, HIGH); //Turn off LED on ESP8266
    }
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); //Free the resources
  }
  delay(15000);
}
