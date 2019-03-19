/***********************************************************************
 * Project      :     Arduino_UNO_LED_RGB
 * Description  :     LED RGB Control            
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*        GPIO Define                 */
/**************************************/ 
int redPin= 9;
int greenPin = 10;
int bluePin = 11;

/**************************************/
/*        Pre-Define function         */
/**************************************/ 
void setColor(int redValue, int greenValue, int blueValue);


 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_LED_RGB");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("Facebook     :  https://www.facebook.com/tenergy.innovation");
  Serial.println("Email        :  tenergy.innovation@gmail.com");
  Serial.println("TEL          :  +6689-140-7205");
  Serial.println("************************************************");  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
  setColor(255, 0, 0); // Red Color
  delay(1000);
  setColor(0, 255, 0); // Green Color
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  setColor(255, 255, 255); // White Color
  delay(1000);
  setColor(170, 0, 255); // Purple Color
  delay(1000);
}

 /***********************************************************************
 * FUNCTION:    setColor
 * DESCRIPTION: set color
 * PARAMETERS:  redValue, greenValue, blueValue
 * RETURNED:    nothing
 ************************************************************************/
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
