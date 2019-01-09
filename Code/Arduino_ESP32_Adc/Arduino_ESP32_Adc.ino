/***********************************************************************
 * Project      :     Arduino_ESP8266_Adc
 * Description  :     ทดสอบการอ่านค่า Adc จาก VR1, VR2  และ VR3                
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.1
 * Rev1.0       :     Original
 * Rev1.1       :     Edit define pin and some variable
 * website      :     http://www.tenergyinnovation.co.th
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/

/**************************************/
/*           GPIO define              */
/**************************************/
#define ADC39_PIN     39
#define ADC34_PIN     34
#define ADC35_PIN     35
#define VR1           ADC35_PIN
#define VR2           ADC34_PIN
#define VR3           ADC39_PIN



/**************************************/
/*       Global variable define       */
/**************************************/
int vr1_val,vr2_val,vr3_val;


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
  Serial.println("Project      :  Arduino_ESP32_Adc");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");

}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {

  vr1_val = analogRead(VR1);
  vr2_val = analogRead(VR2);
  vr3_val = analogRead(VR3);

  Serial.print("VR1 = "); Serial.println(vr1_val);
  Serial.print("VR2 = "); Serial.println(vr2_val);
  Serial.print("VR3 = "); Serial.println(vr3_val);
  Serial.println("---------------");

  delay(300);

}
