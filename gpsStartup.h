// Lower the baud rate to 9600 from 38.4k
  /*Serial.print("Setting uBlox port mode: ");
  uint8_t setPort[] = {0xB5, 0x62, 0x06, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00, 0x00,
                       0xD0, 0x08, 0x00, 0x00, 0x80, 0x25, 0x00, 0x00, 0x03, 0x00,
                       0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9E, 0x95};
  sendUBX(setPort, sizeof(setPort)/sizeof(uint8_t));*/

  // RATE
  /*Serial.print("Set data rate: ");
  //uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0x64,0x00,0x01,0x00,0x01,0x00,0x7A,0x12}; //(10Hz)
  //uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0xC8,0x00,0x01,0x00,0x01,0x00,0xDE,0x6A};  //(5Hz)
  uint8_t setRate[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0xE8,0x03,0x01,0x00,0x01,0x00,0x01,0x39}; //(1Hz)
  sendUBX(setRate, sizeof(setRate)/sizeof(uint8_t));
  getUBX_ACK(setRate);*/
