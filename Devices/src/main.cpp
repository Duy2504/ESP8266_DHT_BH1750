#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <BH1750.h>
#include <Wire.h>
#define DHTPIN 0
#define DHTTYPE DHT11
#define LED 2

BH1750 lightMeter(0x23);

DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(115200);
  dht.begin();
  Wire.begin();

  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE))
  {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else
  {
    Serial.println(F("Error initialising BH1750"));
  }
}

void loop()
{
  int h = dht.readHumidity();
  Serial.println(h);
  int t = dht.readTemperature();
  Serial.println(t);
  delay(1000);
  if (lightMeter.measurementReady())
  {
    int lux = lightMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
  }

  delay(1000);
}