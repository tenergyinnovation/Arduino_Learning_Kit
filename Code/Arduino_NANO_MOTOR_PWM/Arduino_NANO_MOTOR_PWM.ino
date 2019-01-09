/***********************************************************************
 * Project      :     Arduino_NANO_MOTOR_PWM
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
#include <Arduino.h>
 
/**************************************/
/*           GPIO define              */
/**************************************/
#define PWM_PIN_5    5
#define PWM_PIN_6    6
#define MOTOR_1     PWM_PIN_5
#define MOTOR_2     PWM_PIN_6 
#define ADC0_PIN      A6 
#define ADC1_PIN      A7 
#define VR1           ADC0_PIN
#define VR2           ADC1_PIN


/**************************************/
/*       Global variable define       */
/**************************************/
int vr1_val = 0;           // variable to store the value read
int vr2_val = 0;           // variable to store the value read


  /***********************************************************************
 * FUNCTION:    setPwmFrequency
 * DESCRIPTION: setup Pulse width mode frequency
 * PARAMETERS:  pin, divisor
 * RETURNED:    nothing
 ***********************************************************************/
// Set pin 6's PWM frequency to 62500 Hz (62500/1 = 62500)
// Note that the base frequency for pins 5 and 6 is 62500 Hz
//setPwmFrequency(6, 1);
void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_NANO_MOTOR_PWM");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");

  /* setup Pulse width mode frequency */
  setPwmFrequency(MOTOR_1,8);
  setPwmFrequency(MOTOR_2,8);
  
  analogWrite(MOTOR_1,0);
  analogWrite(MOTOR_2,0);

}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  int _pwm_motor1;
  int _pwm_motor2;
  int _percent;

  vr1_val = analogRead(VR1);     // read the input pin
  vr2_val = analogRead(VR2);     // read the input pin
  _pwm_motor1 = vr1_val/4;
  _pwm_motor2 = vr2_val/4;
  
  Serial.print("\n\rInfo: PWM[motor#1] = ");
  Serial.print(_pwm_motor1);
  Serial.print("[");
  _percent = (_pwm_motor1*100)/256;
  Serial.print(_percent);
  Serial.print("%]");
  //---------
  Serial.print("         PWM[motor#2] = ");
  Serial.print(_pwm_motor2);
  Serial.print("[");
  _percent = (_pwm_motor2*100)/256;
  Serial.print(_percent);
  Serial.println("%]");

  
  analogWrite(MOTOR_1,_pwm_motor1);
  analogWrite(MOTOR_2,_pwm_motor2);
  
  delay(100);

}
