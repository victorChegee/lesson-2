#define BLYNK_TEMPLATE_ID "TMPL2ex_gLzhC"
#define BLYNK_TEMPLATE_NAME "gas level monitoring system"
#define AUTH_TOKEN "NegjamWoaX15ECLn9dZHKwVxm8MC3GHA"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

#define MQ2 34
#define GREEN 16
#define RED 17
#define WIFI_SSID "GEARBOX MEMBERS"
#define WIFI_PASSWORD "Members@Gearbox"

BlynkTimer timer;

char auth[] = AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

int sensorValue = 0;
boolean state = false;

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(MQ2, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  timer.setInterval(1000L, sendUptime);
}

void sendUptime()
{
  
  sensorValue = analogRead(MQ2);
  Blynk.virtualWrite(V0, sensorValue);
  Serial.println(sensorValue);

  if (sensorValue > 300)
  {
    BlynkWifi Blynk(_blynkTransport);("Gas Detected!");
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }

  else
  { 
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}