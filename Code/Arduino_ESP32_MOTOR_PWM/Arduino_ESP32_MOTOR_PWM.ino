/***********************************************************************
 * Project      :     Arduino_ESP32_MOTOR_PWM
 * Description  :     ควบคุมความเร็วของมอเตอร์โดยกับปรับ VR1 และ VR2                 
 *                    เพื่อควบคุมความกว้างของ Pulse Width Mod(PWM)
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
/*         include library            */
/**************************************/ 

/**************************************/
/*           GPIO define              */
/**************************************/
#define PWM_PIN_32    32
#define PWM_PIN_33    33
#define ADC35_PIN     34 
#define ADC34_PIN     35 
#define MOTOR_1       PWM_PIN_32
#define MOTOR_2       PWM_PIN_33
#define VR1          ADC34_PIN
#define VR2          ADC35_PIN

/**************************************/
/*        Constant define             */
/**************************************/

/**************************************/
/*       Global variable define       */
/**************************************/ 
uint8_t ledArray[2] = {1, 2}; // two led channels
int vr1_val,vr2_val;

/************************************/
/*       Pre-define function        */
/************************************/

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
  Serial.println("Project      :  Arduino_ESP32_MOTOR_PWM");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");

  ledcAttachPin(MOTOR_1, 1);
  ledcAttachPin(MOTOR_2, 2);
  
  ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
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
  Serial.printf("Info: PWM[motor#1] =  %d[%d%c]       ",vr1_val,vr1_val*100/4095,37);   //37 ascii code = '%'
  Serial.printf("PWM[motor#2] =  %d[%d%c]\r\n",vr2_val,vr2_val*100/4095,37);   //37 ascii code = '%'

  
  ledcWrite(1, (vr1_val/16) );
  ledcWrite(2, (vr2_val/16) );

  delay(100);
 
}
