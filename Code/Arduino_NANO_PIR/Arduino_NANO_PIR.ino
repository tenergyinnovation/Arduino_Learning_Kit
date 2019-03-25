/***********************************************************************
 * Project      :     Arduino_NANO_PIR
 * Description  :     Motion Sensor Test           
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*         GPIO Define                */
/**************************************/  
#define inputPin     14

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup(){
  pinMode(inputPin,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_NANO_PIR");                 
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
void loop(){
  int value= digitalRead(inputPin);

  if (value == HIGH)
  {
    Serial.println("High");
  }

  else
  {
    Serial.println("LOW");
  }
  delay(300);
}
