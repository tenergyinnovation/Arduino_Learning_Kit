/***********************************************************************
 * Project      :     Arduino_UNO_RTC_ds3231
 * Description  :     ติดต่อกับไอซีฐานเวลา ds3231            
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * website      :     http://www.tenergyinnovation.co.th
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/

/**************************************/
/*         include library            */
/**************************************/ 
// Date, Time and Alarm functions using a DS3231 RTC connected via I2C and Wire lib
#include "Wire.h"
#include "SPI.h"  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"

/**************************************/
/*        object define               */
/**************************************/
RTC_DS3231 RTC;

/**************************************/
/*       Global variable define       */
/**************************************/
String tempString="";

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup () {

  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_RTC_ds3231");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__)); //Auto adjust time with PC

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  DateTime now = RTC.now();
  /* ตั้งเวลา ในตัวอย่างนี้ เซตค่าเป็นเวลา 23:09 ถ้าถึงเวลานี้จะให้ทำงานที่ฟังก์ชัน 
    RTC.setAlarm1Simple(23, 9);
   if (RTC.checkIfAlarm(1)) {
   Serial.println("Alarm Triggered");
   }*/
  RTC.setAlarm1Simple(15, 10);

  RTC.turnOnAlarm(1);

  if (RTC.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }

  Serial.print("Start lcd initial ....");                   
  Serial.println("...Done");

}


 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop () {

  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);

  if (RTC.checkIfAlarm(1)) {
    Serial.println("Alarm Triggered");
  }

  Serial.println();
  Serial.print("Tempeature = ");
  Serial.print(RTC.getTemperature()); // คำสั่งดึงอุณหภูมิออกมาแสดง
  Serial.println(" C");
  Serial.println();
  
  delay(1000);


  



  
}
