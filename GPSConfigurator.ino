#include <SoftwareSerial.h>
#include <SPI.h>
#include <RH_RF95.h>

RH_RF95 rf95;
static const int RXPin = 3, TXPin = 4;
static const uint32_t GPSBaud = 9600;
SoftwareSerial nss(RXPin, TXPin);
byte navmode = 99;
 
void setup() {
 
  // Start up serial ports
  nss.begin(GPSBaud);
  Serial.begin(19200); // used for debug ouput
  delay(2000); // Give the GPS time to come boot

  // LoRa Setup
  while (!Serial) ; // Wait for serial port to be available
    if (!rf95.init())
      Serial.println("Init sender failed");
    else
      Serial.println("Init sender succeeded");

  rf95.setFrequency(433.00);
  //rf95.setFrequency(868.00);
  rf95.setModemConfig(RH_RF95::Bw31_25Cr48Sf512);
  //rf95.setModemConfig(RH_RF95::Bw125Cr48Sf4096);
  //rf95.setTxPower(13, false);

  uint8_t data[] = "Sender started";
  rf95.send(data, sizeof(data));  
  rf95.waitPacketSent();
 
  // Lower the baud rate to 9600 from 38.4k
  /*Serial.print("Setting uBlox port mode: ");
  uint8_t setPort[] = {0xB5, 0x62, 0x06, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00, 0x00, 0xD0, 0x08, 0x00, 0x00, 0x80, 0x25, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9E, 0x95};
  sendUBX(setPort, sizeof(setPort)/sizeof(uint8_t));*/
 
  // Switch baud rates on the software serial
  /*Serial.println("Switching to 9600b GPS serial");
  nss.begin(9600);
  delay(1000);*/
 
  // Set the navigation mode (Airborne, 1G)
  /*Serial.print("Setting uBlox nav mode: ");
  uint8_t setNav[] = {0xB5, 0x62, 0x06, 0x24, 0x24, 0x00, 0xFF, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00, 0x05, 0x00, 0xFA, 0x00, 0xFA, 0x00, 0x64, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xDC};
  sendUBX(setNav, sizeof(setNav)/sizeof(uint8_t));
  getUBX_ACK(setNav);*/
 
 
  // Switch off GLL
  /*Serial.print("Switching off NMEA GLL: ");
  uint8_t setGLL[] = { 0xB5, 0x62, 0x06, 0x01, 0x08, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x2B };
  sendUBX(setGLL, sizeof(setGLL)/sizeof(uint8_t));
  getUBX_ACK(setGLL);*/
 
  // Switch off GSA
  /*Serial.print("Switching off NMEA GSA: ");
  uint8_t setGSA[] = { 0xB5, 0x62, 0x06, 0x01, 0x08, 0x00, 0xF0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x32 };
  sendUBX(setGSA, sizeof(setGSA)/sizeof(uint8_t));
  getUBX_ACK(setGSA);*/
 
  // Switch off GSV
  /*Serial.print("Switching off NMEA GSV: ");
  uint8_t setGSV[] = { 0xB5, 0x62, 0x06, 0x01, 0x08, 0x00, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x39 };
  sendUBX(setGSV, sizeof(setGSV)/sizeof(uint8_t));
  getUBX_ACK(setGSV);*/
 
  // Switch off RMC
  /*Serial.print("Switching off NMEA RMC: ");
  uint8_t setRMC[] = { 0xB5, 0x62, 0x06, 0x01, 0x08, 0x00, 0xF0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x40 };
  sendUBX(setRMC, sizeof(setRMC)/sizeof(uint8_t));
  getUBX_ACK(setRMC);*/

  Serial.print("Switching off all NMEA packets: ");
  uint8_t setALLOff[] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x24,  //(GxGGA)
                         0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x2B,  //(GxGLL)
                         0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x32,  //(GxGSA)
                         0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x39,  //(GxGSV)
                         0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x04,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x40,  //(GxRMC)
                         0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x05,0x00,0x00,0x00,0x00,0x00,0x01,0x05,0x47}; //(GxVTG)
  sendUBX(setALLOff, sizeof(setALLOff)/sizeof(uint8_t));
  getUBX_ACK(setALLOff);

  // Enable NMEAs
  Serial.print("Switching on all NMEA packets: ");
  uint8_t setALLOn[] = {0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x00,0x01,0xFB,0x10,  //(GxGGA)
                        0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x01,0x01,0xFC,0x12,  //(GxGLL)
                        0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x02,0x01,0xFD,0x14,  //(GxGSA)
                        0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x03,0x01,0xFE,0x16,  //(GxGSV)
                        0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x04,0x01,0xFF,0x18,  //(GxRMC)
                        0xB5,0x62,0x06,0x01,0x03,0x00,0xF0,0x05,0x01,0x00,0x1A}; //(GxVTG)
  sendUBX(setALLOn, sizeof(setALLOn)/sizeof(uint8_t));
  getUBX_ACK(setALLOn);

  // Disable UBX
  Serial.print("Switching off UBX: ");
  uint8_t setUBXOff[] = {0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0xDC, //NAV-PVT off
                        0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0xB9,  //NAV-POSLLH off
                        0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0xC0}; //NAV-STATUS off
  sendUBX(setUBXOff, sizeof(setUBXOff)/sizeof(uint8_t));
  getUBX_ACK(setUBXOff);

  // Enable UBX
  //Serial.print("Switching on UBX: ");
  uint8_t setUBXOn[] = {0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x07,0x00,0x01,0x00,0x00,0x00,0x00,0x18,0xE1,   //NAV-PVT on
                         0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x13,0xBE,  //NAV-POSLLH on
                         0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x14,0xC5}; //NAV-STATUS on
  //sendUBX(setUBXOn, sizeof(setUBXOn)/sizeof(uint8_t));
  //getUBX_ACK(setUBXOn);

  // RATE
  Serial.print("Set data rate: ");
  //uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0x64,0x00,0x01,0x00,0x01,0x00,0x7A,0x12}; //(10Hz)
  //uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0xC8,0x00,0x01,0x00,0x01,0x00,0xDE,0x6A};  //(5Hz)
  uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0xE8,0x03,0x01,0x00,0x01,0x00,0x01,0x39}; //(1Hz)
  sendUBX(setRate, sizeof(setRate)/sizeof(uint8_t));
  getUBX_ACK(setRate);

}

#define GPS_BUFFERSIZE 83
byte recvBuffer[GPS_BUFFERSIZE];
boolean GPS_checksum_calc = false;
byte recvIdx;
char c;

void loop() {
  static unsigned long lastSendTime = 0;
  unsigned long now = millis();
  
  while(nss.available() > 0 && now - lastSendTime > 1000){
    c = nss.read();
    if (c == '$'){
      GPS_checksum_calc = false;
      recvIdx = 0;
      recvBuffer[recvIdx++] = c;
      
    } else if(c == '\r' || c == '\n' || c == '\r\n'){
      recvBuffer[recvIdx++] = 0;
      if(GPS_checksum_calc){

      float data1=3.14159f;
      rf95.send((uint8_t*)&data1, sizeof(data1));
      
      //uint8_t data[] = "Sender started";
      //rf95.send(data, sizeof(data));  
      rf95.waitPacketSent();

      /*rf95.send((uint8_t *)&recvBuffer, sizeof(recvBuffer));
      rf95.waitPacketSent();
      lastSendTime = now;*/
      
      String myString = String((char *)recvBuffer);
      Serial.println(myString);
      
    }
      continue;
      
    }else{
      if (recvIdx < (GPS_BUFFERSIZE - 1)){
        if(c == '*'){
          GPS_checksum_calc = true;
        }
        recvBuffer[recvIdx++] = c;
      } else {
        recvIdx = 0;   // Buffer overflow : restart
        nss.flush();
        Serial.println("Buffer overflow!");
      }
    }
  }  
}
 
// Send a byte array of UBX protocol to the GPS
void sendUBX(uint8_t *MSG, uint8_t len) {
  for(int i=0; i<len; i++) {
    nss.write(MSG[i]);
    Serial.print(MSG[i], HEX);
  }
  Serial.println();
} 
 
// Calculate expected UBX ACK packet and parse UBX response from GPS
boolean getUBX_ACK(uint8_t *MSG) {
  uint8_t b;
  uint8_t ackByteID = 0;
  uint8_t ackPacket[10];
  unsigned long startTime = millis();
  Serial.print(" * Reading ACK response: ");
 
  // Construct the expected ACK packet    
  ackPacket[0] = 0xB5;  // header
  ackPacket[1] = 0x62;  // header
  ackPacket[2] = 0x05;  // class
  ackPacket[3] = 0x01;  // id
  ackPacket[4] = 0x02;  // length
  ackPacket[5] = 0x00;
  ackPacket[6] = MSG[2];  // ACK class
  ackPacket[7] = MSG[3];  // ACK id
  ackPacket[8] = 0;   // CK_A
  ackPacket[9] = 0;   // CK_B
 
  // Calculate the checksums
  for (uint8_t i=2; i<8; i++) {
    ackPacket[8] = ackPacket[8] + ackPacket[i];
    ackPacket[9] = ackPacket[9] + ackPacket[8];
  }
 
  while (1) {
 
    // Test for success
    if (ackByteID > 9) {
        // All packets in order!
        Serial.println(" (SUCCESS!)");
        return true;
    }
 
    // Timeout if no valid response in 3 seconds
    if (millis() - startTime > 3000) { 
      Serial.println(" (FAILED!)");
      return false;
    }
 
    // Make sure data is available to read
    if (nss.available()) {
      b = nss.read();
 
      // Check that bytes arrive in sequence as per expected ACK packet
      if (b == ackPacket[ackByteID]) { 
        ackByteID++;
        Serial.print(b, HEX);
      } else {
        ackByteID = 0;  // Reset and look again, invalid order
      }
    }
  }
}
 
//Function to poll the NAV5 status of a Ublox GPS module (5/6)
//Sends a UBX command (requires the function sendUBX()) and waits 3 seconds
// for a reply from the module. The then isolates the byte which contains 
// the information regarding the NAV5 mode,
// 0 = Pedestrian mode (default, will not work above 12km)
// 6 = Airborne 1G (works up to 50km altitude)
//Adapted by jcoxon from getUBX_ACK() from the example code on UKHAS wiki
// http://wiki.ukhas.org.uk/guides:falcom_fsa03
boolean checkNAV(){
  uint8_t b, bytePos = 0;
  uint8_t getNAV5[] = { 0xB5, 0x62, 0x06, 0x24, 0x00, 0x00, 0x2A, 0x84 }; //Poll NAV5 status
 
  nss.flush();
  unsigned long startTime = millis();
  sendUBX(getNAV5, sizeof(getNAV5)/sizeof(uint8_t));
 
  while (1) {
    // Make sure data is available to read
    if (nss.available()) {
      b = nss.read();
 
      if(bytePos == 8){
        navmode = b;
        return true;
      }
 
      bytePos++;
    }
    // Timeout if no valid response in 3 seconds
    if (millis() - startTime > 3000) {
      navmode = 0;
      return false;
    }
  }
}
