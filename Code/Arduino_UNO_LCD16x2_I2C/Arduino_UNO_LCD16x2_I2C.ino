/***********************************************************************
 * Project      :     Arduino_UNO_LCD16x2_I2C
 * Description  :     LCD 6x2 I2C Test        
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
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


/**************************************/
/*        object define              */
/**************************************/
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd1(0x27, 16, 2);
//LiquidCrystal_I2C lcd1(0x38, 20, 4);  //proteus simulate
//LiquidCrystal_I2C lcd1(0x3F, 20, 4);

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup()
{
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_LCD16x2_I2C");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");
  lcd1.begin();                      
  lcd1.backlight();
  lcd1.clear();
  lcd1.setCursor(0,0);
  lcd1.print("*   Tenergy    *");
  lcd1.setCursor(0,1);
  lcd1.print("*  Innovation  *");

}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop()
{
  lcd1.backlight();
  Serial.println("Display On");
  delay(1000);
  lcd1.noBacklight();
  Serial.println("Display Off");
  delay(1000);
}
