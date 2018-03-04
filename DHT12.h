/*
	DHT12.h - l'objet capteur DHT12
    DaK oct 2017
    classe minimale à compléter
*/

#ifndef DHT12_h
    #define DHT12_h
    #include "Wire.h"
    
    #define DH12_OK  0
    #define DH12_erreur_Absent  1
    #define DH12_erreur_Checsum 2
    #define DH12_erreur_bus     3
    #define DHT12_I2C_ADDR (0x5C)
    #define DHT12_I2C_REG_START_ADDR (0x0)
    #define DHT12_DATA_SIZE (5)
    #define DHT12_MAX_HUMI (950)
    #define DHT12_MIN_HUMI (200)
    #define DHT12_MAX_TEMP (600)
    #define DHT12_MIN_TEMP (-200)
    
    class DHT12{
        public:
    		DHT12();
    		int read( int *deciTCelsius, int *deciHumidity );
    };
#endif
