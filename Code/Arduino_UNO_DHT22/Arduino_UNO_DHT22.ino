/***********************************************************************
 * Project      :     Arduino_UNO_DHT22
 * Description  :     อ่านค่าและแสดงผลเซนเซอร์วัดอุณหภูมิและความชื่น DHT22 หรือ DHT11             
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.1
 * Rev1.0       :     Original
 * Rev1.1       :     Improve the code
 * website      :     http://www.tenergyinnovation.co.th
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/

/**************************************/
/*         include library            */
/**************************************/ 
#include <Wire.h>
#include "DHT.h"

/**************************************/
/*           GPIO define              */
/**************************************/

#define DHTPIN        4     // what digital pin we're connected to

/**************************************/
/*        Constant define             */
/**************************************/
//เปลี่ยนเซนเซอร์ DHT22 หรือ DHT11 ที่นี่
#define DHTTYPE       DHT22   
//#define DHTTYPE       DHT11   

/**************************************/
/*        object define             */
/**************************************/
DHT dht(DHTPIN, DHTTYPE);


/**************************************/
/*       Global variable define       */
/**************************************/
float temp;
float humi;

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {


  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_DHT22");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");
 
  Serial.print("\n>>Info: DHT22 Initializing ...");
  dht.begin();
  Serial.println("done.");
  Serial.println("--------------------");
     
}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
       temp = dht.readTemperature();
       humi = dht.readHumidity();


      if (isnan(temp) || isnan(humi) ) {
              Serial.println(">>Info: Failed to read from DHT sensor!");
       }
      else{
        Serial.print("temperature = "); Serial.print(temp,1); Serial.println(" C");
        Serial.print("humidity = "); Serial.print(humi,1); Serial.println(" %");
      }

      Serial.println("--------------------");
      delay(1000);         
}
