/***********************************************************************
 * Project      :     Arduino_NANO_Stepping_Motor
 * Description  :     ทดสอบ stepping motor โดยการป้อนค่า 1, 2 หรือ 0 ทาง serial port            
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.1
 * Rev1.0       :     Original
 * Rev1.1       :     Re-program by revise get value process  from uer
 * website      :     http://www.tenergyinnovation.co.th
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     uten.boonliam@innovation.co.th
 * TEL          :     089-140-7205
 ***********************************************************************/

/**************************************/
/*        GPIO  define               */
/**************************************/ 
#define motorPin1  14// Blue   - 28BYJ48 pin 1
#define motorPin2  12// Pink   - 28BYJ48 pin 2
#define motorPin3  13// Yellow - 28BYJ48 pin 3
#define motorPin4  15// Orange - 28BYJ48 pin 4
#define motorSpeed  20     //constant to set stepper speed

 
/***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {

  //declare the motor pins as outputs

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  Serial.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_ESP32_Stepping_Motor");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************\r\n");

  Serial.println("### Insert value from keyboard ###");
  Serial.println("'0' => Motor stop rotate"); 
  Serial.println("'1' => Motor clockwise"); 
  Serial.println("'2' => Motor counterclockwise");
  Serial.print("Enter :");
  


}

 
 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop(){

    static int _val_int = 0; // ตัวแปลกำหนดการหมุนของมอเตอร์
                             // _val_int = 0 <หยุดมอเตอร์>
                             // _val_int = 1 <หมุนตามเข็มนาฬิกา>
                             // _val_int = 2 <หมุนทวนเข็มนาฬิกา> 

    /* get value from user */
    if(Serial.available()){

      char _val_char = Serial.read();

      if(_val_char == '0'){
        Serial.println(_val_char);
        Serial.println("Info: Motor stop");
        _val_int = 0;
        Serial.print("Enter :");
      }
      else if (_val_char == '1'){
        Serial.println(_val_char);
        Serial.println("Info: Motor clockwise");
        _val_int = 1;
        Serial.print("Enter :");
      }  
      else if(_val_char == '2'){
        Serial.println(_val_char);
        Serial.println("Info: Motor counterclockwise");
        _val_int = 2;
        Serial.print("Enter :");
      }
    }


  

    /* control stepping motor*/
    if (_val_int == 1){
        clockwise();     
    }
    else if (_val_int == 2){
        counterclockwise();    
    }             
    else if (_val_int == 0){
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
    }      
}

 

 
 /***********************************************************************
 * FUNCTION:    counterclockwise
 * DESCRIPTION: counterclockwise
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void counterclockwise (){

  // 1
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);

  // 2
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay (motorSpeed);

  // 3
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);

  // 4
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);

  // 5
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);

  // 6
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay (motorSpeed);

  // 7
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motorSpeed);

  // 8
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motorSpeed);

}

 
 /***********************************************************************
 * FUNCTION:    clockwise
 * DESCRIPTION: clockwise
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void clockwise(){

  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);

  // 2
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay (motorSpeed);

  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);

  // 4
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);

  // 5
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);

  // 6
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delay (motorSpeed);

  // 7
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);

  // 8
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
}
