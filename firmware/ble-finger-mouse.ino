/*********************************************************************
 This is an example for our nRF52 based Bluefruit LE modules

 Pick one up today in the adafruit shop!

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/
#include <bluefruit.h>
#include "SparkFunLIS3DH.h"
#include "Wire.h"

BLEDis bledis;
BLEHidAdafruit blehid;

const int buttonPin = 0;     // the number of the pushbutton pin
const int ledPin =  1;      // the number of the LED pin
#define MOVE_STEP      10
#define MOVE_THRD_X    0.5 //0~1.0
#define MOVE_THRD_Y    0.4 //0~1.0

#define MOVE_MULT    17
LIS3DH myIMU; //Default constructor is I2C, addr 0x19.

int buttonState = 0;         // variable for reading the pushbutton status
bool buttonFlag =false;
double moveX=0;
double moveY=0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Bluefruit.begin();
  // HID Device can have a min connection interval of 9*1.25 = 11.25 ms
  Bluefruit.Periph.setConnInterval(9, 16); // min = 9*1.25=11.25 ms, max = 16*1.25=20ms
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values

  // Configure and Start Device Information Service
  bledis.setManufacturer("LIGHTCAFE LAB");
  bledis.setModel("ModsRing nRF52840");
  bledis.begin();

  // BLE HID
  blehid.begin();

  // Set up and start advertising
  startAdv();

  myIMU.begin();
}

void startAdv(void)
{  
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_MOUSE);
  
  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for 'Name' in the advertising packet
  Bluefruit.Advertising.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html   
   */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}

void loop() 
{    
  delay(5);
  
  moveY=myIMU.readFloatAccelY();
  if(moveY<-MOVE_THRD_Y){
    //up
    moveY=moveY*MOVE_MULT;
  }
  if(moveY>MOVE_THRD_Y){
    //down
    moveY=moveY*MOVE_MULT;
  }
  moveX=myIMU.readFloatAccelX();
  if(moveX<-MOVE_THRD_X){
    //left
    moveX=moveX*MOVE_MULT;
  }
  if(moveX>MOVE_THRD_X){
    //right
    moveX=moveX*MOVE_MULT;
  }
  blehid.mouseMove(moveX, -moveY);

}
