/*
	DHT12.cpp - l'objet capteur DHT12
    DaK oct 2017
    classe minimale à compléter
*/

#include "Arduino.h"
#include "Wire.h"
#include "DHT12.h"


DHT12::DHT12(){}

int DHT12::read( int *deciTCelsius, int *deciHumidity){
	  byte data, chksum=0;
    int _deciTCelsius, _deciHumidity;
    
    // adresser le composant i2c
    Wire.beginTransmission(DHT12_I2C_ADDR); 
	  Wire.write(DHT12_I2C_REG_START_ADDR);   // pointer son premier registre 
	  if (Wire.endTransmission()!=0) return DH12_erreur_Absent;
    
    // lire les 5 octets de données dans le composant
	  Wire.requestFrom(DHT12_I2C_ADDR, DHT12_DATA_SIZE); // lire DHT12_DATA_SIZE octets à partir du registre courant (le premier)
    chksum += data = Wire.read(); // humidité en %
        _deciHumidity = data*10;
    chksum += data = Wire.read(); // les dixièmes de %
        _deciHumidity += data;
    chksum += data = Wire.read(); // température en celsius
        _deciTCelsius = data*10;
    chksum += data = Wire.read(); // les dixièmes de celsius + le signe
        _deciTCelsius += (data&0x7F);
        // traitement du signe
        if( data&0x80 ) _deciTCelsius = 0 - (_deciTCelsius); // température négative
    data = Wire.read(); // le 5ième octer est un checksum
    if( data != chksum ) return DH12_erreur_Checsum;
    if( Wire.available()!=0 ) return DH12_erreur_bus; // on ne devrait pouvoir lire que 5 registres
    
    // Déterminer si les valeurs lues sont dans les plages de mesure (voir datasheet)
    // température °C [-20..60]; humidité relative % [20%..95%]
    if( _deciHumidity > DHT12_MAX_HUMI) _deciHumidity = DHT12_MAX_HUMI;
    if( _deciHumidity < DHT12_MIN_HUMI) _deciHumidity = DHT12_MIN_HUMI;
    if( _deciTCelsius > DHT12_MAX_TEMP) _deciTCelsius = DHT12_MAX_TEMP;
    if( _deciTCelsius < DHT12_MIN_TEMP) _deciTCelsius = DHT12_MIN_TEMP;
    
    // tout est ok => retour au demandeur
    *deciTCelsius = _deciTCelsius;
    *deciHumidity = _deciHumidity;
	  return 0;
}

