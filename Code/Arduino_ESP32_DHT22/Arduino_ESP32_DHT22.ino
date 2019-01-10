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
#include "DHTesp.h"

/**************************************/
/*        object define               */
/**************************************/
DHTesp dht;

/**************************************/
/*       Global variable define       */
/**************************************/
float temp;
float humi;



/**************************************/
/*           GPIO define              */
/**************************************/
/** Pin number for DHT11 data pin */
int dhtPin = 23;

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_ESP32_DHT22");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************\r\n");


  Serial.print("Info: DHT22 initial....");
  dht.setup(dhtPin, DHTesp::DHT22);  //เปลี่ยน DHT11 หรือ DHT22 ได้ที่นี่
  Serial.println("done");  
}


/***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
        TempAndHumidity newValues = dht.getTempAndHumidity();

        temp = newValues.temperature;
        humi = newValues.humidity;
        
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




