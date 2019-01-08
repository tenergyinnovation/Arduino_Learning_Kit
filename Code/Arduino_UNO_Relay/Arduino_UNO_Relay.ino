/***********************************************************************
 * Project      :     Arduino_UNO_Relay
 * Description  :     Relay 2 channel test          
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
/*         GPIO define                */
/**************************************/  
#define RELAY_2   12
#define RELAY_1   13

/**************************************/
/*         constant define            */
/**************************************/  
#define ON    LOW
#define OFF   HIGH

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_Relay");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");
  pinMode(RELAY_1,OUTPUT);
  pinMode(RELAY_2,OUTPUT);

  digitalWrite(RELAY_1,LOW);
  digitalWrite(RELAY_2,LOW);

}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY_1,ON);
  digitalWrite(RELAY_2,OFF);

  delay(1000);
  digitalWrite(RELAY_1,OFF);
  digitalWrite(RELAY_2,ON);

  delay(1000);

}
