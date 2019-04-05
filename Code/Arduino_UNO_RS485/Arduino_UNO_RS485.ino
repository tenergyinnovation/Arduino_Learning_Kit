/***********************************************************************
 * Project      :     Arduino_UNO_RS485
 * Description  :     RS485 test           
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14 Nov 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * Email        :     tenergy.innovation@gmail.com
 * TEL          :     +6689-140-7205
 ***********************************************************************/
#include <SoftwareSerial.h>
SoftwareSerial rs485(9, 10); // RX(R), TX(G)


/**************************************/
/*        GPIO Define                 */
/**************************************/  
#define RS485_PIN_DIR 11  //B
#define RXD2 9  //R
#define TXD2 10  G//


#define RS485_WRITE     1
#define RS485_READ      0

/**************************************/
/*        Pre-Define function         */
/**************************************/ 



 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  Serial.begin(9600);
  rs485.begin(9600);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_UNO_RS485");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("Facebook     :  https://www.facebook.com/tenergy.innovation");
  Serial.println("Email        :  tenergy.innovation@gmail.com");
  Serial.println("TEL          :  +6689-140-7205");
  Serial.println("************************************************");
  Serial.print("Info: Intial gpio...");
  pinMode(RS485_PIN_DIR,OUTPUT);
  digitalWrite(RS485_PIN_DIR,RS485_READ);
  Serial.println("done"); 

}


 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop() {
    byte  _incommingByte[60];
    int   _cnt_byte=0;
    
    
    Serial.println("Hello world\r\n");
    digitalWrite(RS485_PIN_DIR,RS485_WRITE);
    rs485.println("Hello world");
    
     delay(10); 
     digitalWrite(RS485_PIN_DIR,RS485_READ);
     
     if(rs485.available()){     //receive data from rs485   
      
            //clear buffer
            for(int i=0; i<sizeof(_incommingByte); i++) _incommingByte[i] = 0x00;
            
            
            //collect byte data 
            _cnt_byte=0; 
            do{
                _incommingByte[_cnt_byte++] = rs485.read();
              }while(rs485.available()>0);
                   
            //debug monitor
            for(int i=0; i < _cnt_byte; i++){
                Serial.print("_incommingByte["); Serial.print(i); Serial.print("] = "); Serial.print(_incommingByte[i],DEC); Serial.print("[0x"); Serial.print(_incommingByte[i],HEX); Serial.println("]");
             }  

 
      }   

       delay(1000);
}


