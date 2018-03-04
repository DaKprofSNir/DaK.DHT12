//Test librairie DHT12 


#include "DHT12.h"
#include <Wire.h>     //The DHT12 uses I2C comunication.
DHT12 dht12;          //Preset scale CELSIUS and ID 0x5c.

//TODO tester valeurs T° négatives -> ok

// DUE : Serial est le "programming port USB" près l'alim et passe via un Atmega16U2 comme le UNO

int i = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test du DHT12 : ");
}

void loop() {
    int deciTemperature = 0;
    int deciHumidite = 0;
    int erreur = dht12.read( &deciTemperature, &deciHumidite );
    Serial.println(i++);
    Serial.print("Temperature x 10 : "); Serial.println(deciTemperature);
    Serial.print("%Humidite   x 10 : "); Serial.println(deciHumidite);
    Serial.print("          erreur : "); Serial.println(erreur);
  delay(5000);
}
