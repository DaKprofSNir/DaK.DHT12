//Test librairie DHT12 

#include "DHT12.h"
#include <Wire.h>     //The DHT12 uses I2C comunication.
DHT12 dht12;          

// DUE : Serial est le "programming port USB" près l'alim et passe via un Atmega16U2 comme le UNO
// M0  : remplacer Serial par SerialUSB

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test du DHT12 : ");
}

void loop() {
    int deciTemperature = 0;
    int deciHumidite = 0;
    int erreur = dht12.read( &deciTemperature, &deciHumidite );
    Serial.print("Temperature °C : "); Serial.println( (float)deciTemperature /10.0 );
    Serial.print("Humidite     % : "); Serial.println( (float)deciHumidite / 10.0 );
    if( erreur != DH12_OK ) 
    Serial.print("        erreur : "); Serial.println(erreur);
    
    delay(5000);
}
