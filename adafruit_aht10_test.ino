#define BLYNK_TEMPLATE_ID "TMPL2J5-oR7QU"
#define BLYNK_TEMPLATE_NAME "temperature sensor system"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

#include <Adafruit_AHT10.h>
#define WIFI_SSID "GEARBOX STAFF"
#define WIFI_PASSWORD "Member@Gearbox"
#define AUTH_TOKEN "ybO4884QhsUc6kxvFmspN1W5Tcutam7M"
Adafruit_AHT10 aht;
char auth[] = AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;
void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit AHT10 demo!");
  Blynk.begin(auth, ssid, pass);
  Wire.begin();

  if (! aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);

    
  }
  Serial.println("AHT10 found");
}

void loop() {
  Blynk.run();
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Blynk.virtualWrite(V0, temp);
  //Blynk.virtualWrite(V6, humidity);
  
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  delay(500);
}