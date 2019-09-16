/*Ghettostation
Active messages : 
    NAV-POSLLH Geodetic Position Solution, PAGE 66 of datasheet
    NAV-VELNED Velocity Solution in NED, PAGE 71 of datasheet
    NAV-STATUS Receiver Navigation Status
      or 
    NAV-SOL Navigation Solution Information*/
 
 
 // Set the navigation mode (Airborne, 1G)
  /*Serial.print("Setting uBlox nav mode: ");
  uint8_t setNav[] = {0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x06,0x03,0x00,0x00,0x00,
                      0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,
                      0x2C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                      0x00,0x00,0x00,0x16,0xDC
                      };
  sendUBX(setNav, sizeof(setNav)/sizeof(uint8_t));
  getUBX_ACK(setNav);*/ 

  // Disable UBX
  //Serial.print("Switching off UBX: ");
  /*uint8_t setUBXOff[] = {0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x07,0x00,0x12,0x50,  //NAV-PVT off
                         0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x02,0x00,0x0D,0x46,  //NAV-POSLLH off
                         0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x03,0x00,0x0E,0x48,  //NAV-STATUS off
                         0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x04,0x00,0x0F,0x4A};*/ //NAV-DOP off
  //sendUBX(setUBXOff, sizeof(setUBXOff)/sizeof(uint8_t));
  //getUBX_ACK(setUBXOff);

  // Enable UBX
  //Serial.print("Switching on UBX: ");
  /*uint8_t setUBXOn[] = {//0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x07,0x01,0x13,0x51, //NAV-PVT on
                        //0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x02,0x01,0x0E,0x47, //NAV-POSLLH on
                        //0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x03,0x01,0x0F,0x49, //NAV-STATUS on
                        //0xB5,0x62,0x06,0x01,0x03,0x00,0x01,0x04,0x01,0x10,0x4B  //NAV-DOP on
                        };*/
  //sendUBX(setUBXOn, sizeof(setUBXOn)/sizeof(uint8_t));
  //getUBX_ACK(setUBXOn);

// Function to poll the NAV5 status of a Ublox GPS module (5/6)
// Sends a UBX command (requires the function sendUBX()) and waits 3 seconds
// for a reply from the module. The then isolates the byte which contains 
// the information regarding the NAV5 mode,
// 0 = Pedestrian mode (default, will not work above 12km)
// 6 = Airborne 1G (works up to 50km altitude)
// Adapted by jcoxon from getUBX_ACK() from the example code on UKHAS wiki
// http://wiki.ukhas.org.uk/guides:falcom_fsa03
/*boolean checkNAV(){
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
}*/
  
