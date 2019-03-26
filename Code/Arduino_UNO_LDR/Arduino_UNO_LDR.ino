/***********************************************************************
 * Project      :     Arduino_UNO_LDR
 * Description  :     LDR Testing          
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*            GPIO define             */
/**************************************/ 
#define  ldr  A3 //analog pin to which LDR is connected

/**************************************/
/*       Global variable define       */
/**************************************/
int ldr_value = 0; //variable to store LDR values

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup()
{
  Serial.begin(9600); //start te serial monitor
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_LDR");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("Facebook     :  https://www.facebook.com/tenergy.innovation");
  Serial.println("Email        :  tenergy.innovation@gmail.com");
  Serial.println("TEL          :  +6689-140-7205");
  Serial.println("************************************************");
}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop()
{
ldr_value = analogRead(ldr); //reads the LDR values
Serial.println(ldr_value); //prints the LDR values to serial monitor
delay(50); //wait
}
