/***********************************************************************
 * Project      :     Arduino_ESP32_RS485
 * Description  :     RS485 modbus test           
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     6 Dec 2018
 * Revision     :     1.0
 * Rev1.0       :     Original
 * Facebook     :     https://www.facebook.com/tenergy.innovation
 * WWW          :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@tenergyinnovation.co.th
 * TEL          :     +6689-140-7205
 ***********************************************************************/

/**************************************/
/*         include library            */
/**************************************/ 
#include <String.h>



/**************************************/
/*           GPIO define              */
/**************************************/
#define RS485_PIN_DIR 27
#define RXD2 25
#define TXD2 26




/**************************************/
/*        object define               */
/**************************************/





/**************************************/
/*        word define               */
/**************************************/
HardwareSerial rs485(1);

#define RS485_WRITE     1
#define RS485_READ      0

/**************************************/
/*        define function define      */
/**************************************/



/**************************************/
/*        global variable             */
/**************************************/


 
 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup() {
  Serial.begin(115200);
  rs485.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_ESP32_RS485");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  6 Dec 2018");
  Serial.println("Facebook     :  https://www.facebook.com/tenergy.innovation");
  Serial.println("WWW          :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@tenergyinnovation.co.th");
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
    
    
    Serial.printf("Hello world\r\n");
    digitalWrite(RS485_PIN_DIR,RS485_WRITE);
    rs485.printf("Hello world");
    
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



