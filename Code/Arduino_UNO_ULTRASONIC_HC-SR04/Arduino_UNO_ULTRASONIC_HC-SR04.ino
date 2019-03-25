/***********************************************************************
 * Project      :     Arduino_UNO_ULTRASONIC_HC-SR04
 * Description  :     Ultrasonic sensor test           
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*           GPIO define              */
/**************************************/
#define ULTRA_TRIG_PIN      8
#define ULTRA_ECHO_PIN      7

 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  // put your setup code here, to run once:
  pinMode(ULTRA_TRIG_PIN, OUTPUT);
  pinMode(ULTRA_ECHO_PIN, INPUT);

 Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_ULTRASONIC_HC-SR04");                 
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
void loop() {
  digitalWrite(ULTRA_TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(ULTRA_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_TRIG_PIN, LOW);
  unsigned int PulseWidth = pulseIn(ULTRA_ECHO_PIN, HIGH);
  unsigned int distance = PulseWidth * 0.0173681;

//  Serial.print("Distance is ");
  Serial.print(distance);
  Serial.println(" cm.");
  delay(100);
}
