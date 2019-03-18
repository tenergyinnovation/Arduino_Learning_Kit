/***********************************************************************
 * Project      :     Arduino_UNO_External_EEPROM
 * Description  :     ติดต่อกับ External EEPROM         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*         include library            */
/**************************************/ 
#include "Wire.h"

/**************************************/
/*        contant define              */
/**************************************/
#define EEPROM_I2C_ADDRESS 0x50

/**************************************/
/*        re-define function          */
/**************************************/
void writeAddress(int address, byte val);
byte readAddress(int address);


 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_External_EEPROM");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("Facebook     :  https://www.facebook.com/tenergy.innovation");
  Serial.println("Email        :  tenergy.innovation@gmail.com");
  Serial.println("TEL          :  +6689-140-7205");
  Serial.println("************************************************");

//  int address = 0;
//  byte val = 110;
//  
//  writeAddress(address, val); 
//  byte readVal = readAddress(address);
//  
//  Serial.print("The returned value is ");
//  Serial.println(readVal);

}


 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() 
{

  //Write external eeprom
  Serial.print("Writing External EEPROM....");
  for(int i=0; i<10; i++){
      writeAddress(i, i*10); 
      delay(100);
    }
  Serial.println("done");

  Serial.println("Reading External EEPROM....");   
  for(int i=0; i<10; i++){
      Serial.print("Address["); Serial.print(i); Serial.print("] ="); Serial.println(readAddress(i));
      delay(10);
    
    }  
 Serial.println("done");
 
    while(1);

}

 /***********************************************************************
 * FUNCTION:    writeAddress
 * DESCRIPTION: Write Eeprom
 * PARAMETERS:  address, val
 * RETURNED:    nothing
 ***********************************************************************/
void writeAddress(int address, byte val)
{
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  
   
  Wire.write(val);
  Wire.endTransmission();

  delay(5);
}


 /***********************************************************************
 * FUNCTION:    readAddress
 * DESCRIPTION: Read Eeprom
 * PARAMETERS:  address
 * RETURNED:    byte
 ***********************************************************************/
byte readAddress(int address)
{
  byte rData = 0xFF;
  
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();  


  Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);  

  rData =  Wire.read();

  return rData;
}

