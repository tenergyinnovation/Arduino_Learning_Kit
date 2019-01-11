/***********************************************************************
 * Project      :     Arduino_ESP32_ds1820
 * Description  :     อ่านค่าและแสดงผลเซนเซอร์วัดอุณหภูมิ DS1820            
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
/*         include library            */
/**************************************/ 
#include <DallasTemperature.h>


/**************************************/
/*           GPIO define              */
/**************************************/
// Data wire is plugged into GPIO 23 on the ESP32
#define ONE_WIRE_BUS 23

/**************************************/
/*        constant define             */
/**************************************/
#define TEMPERATURE_PRECISION 12 // Lower resolution


/**************************************/
/*       Global variable define       */
/**************************************/
int numberOfDevices; // Number of temperature devices found


/**************************************/
/*        object define             */
/**************************************/
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
//
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address



/**************************************/
/*        re-define function          */
/**************************************/
void printTemperature(DeviceAddress deviceAddress);



 /***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup(void)
{
  // start serial port
  Serial.begin(115200);
  Serial.println("************************************************");
  Serial.println("Project      :  Arduino_ESP32_ds1820");                 
  Serial.println("Author       :  Tenergy Innovation Co., Ltd.");
  Serial.println("Date         :  14 Nov 2018");
  Serial.println("website      :  http://www.tenergyinnovation.co.th");
  Serial.println("Email        :  uten.boonliam@innovation.co.th");
  Serial.println("TEL          :  089-140-7205");
  Serial.println("************************************************");

  // Start up the library
  sensors.begin();
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
  {
    Serial.print("Found device ");
    Serial.print(i, DEC);
    Serial.print(" with address: ");
    printAddress(tempDeviceAddress);
    Serial.println();
    
    Serial.print("Setting resolution to ");
    Serial.println(TEMPERATURE_PRECISION, DEC);
    
    // set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
    sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
    
     Serial.print("Resolution actually set to: ");
    Serial.print(sensors.getResolution(tempDeviceAddress), DEC); 
    Serial.println();
  }else{
    Serial.print("Found ghost device at ");
    Serial.print(i, DEC);
    Serial.print(" but could not detect address. Check power and cabling");
  }
  }
  delay(1000);
  Serial.println("----------------------------");
}



 /***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
      {
        // Output the device ID
        Serial.print("Temperature for device: ");
        Serial.println(i,DEC);
        // It responds almost immediately. Let's print out the data
        printTemperature(tempDeviceAddress); // Use a simple function to print out the data
        delay(3000);
      } 
  //else ghost device! Check your power requirements and cabling
  }

  Serial.println("----------------------------");
}


 /***********************************************************************
 * FUNCTION:    printTemperature
 * DESCRIPTION: function to print the temperature for a device
 * PARAMETERS:  deviceAddress
 * RETURNED:    nothing
 ***********************************************************************/
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.println(tempC);
  Serial.print("Temp F: ");
  Serial.println(DallasTemperature::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
}

 /***********************************************************************
 * FUNCTION:    printAddress
 * DESCRIPTION: function to print a device address
 * PARAMETERS:  deviceAddress
 * RETURNED:    nothing
 ***********************************************************************/
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
