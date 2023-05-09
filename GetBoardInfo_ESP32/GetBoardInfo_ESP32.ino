  // Model Strings
  const char* ModelStrings[] PROGMEM = {"", "ESP32"};

  // Add Feature String
  void AddFeatureString(String &S, const String F) {
    if (S.length() != 0) S.concat(", ");
    S.concat(F);
  }

  void setup() {
    // Get Chip Information
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    // Start Serial Communication
    Serial.begin(115200);
    while (!Serial);
    delay(1000);
    Serial.println("\r\n***** Chip Information *****");

    // Model
    Serial.printf("Model: %s\r\n", ModelStrings[chip_info.model]);

    // Features
    String Features = "";
    if (chip_info.features & CHIP_FEATURE_EMB_FLASH) AddFeatureString(Features, "Embedded Flash");
    if (chip_info.features & CHIP_FEATURE_WIFI_BGN ) AddFeatureString(Features, "Wifi-BGN"      );
    if (chip_info.features & CHIP_FEATURE_BLE      ) AddFeatureString(Features, "BLE"           );
    if (chip_info.features & CHIP_FEATURE_BT       ) AddFeatureString(Features, "Bluetooth"     );
    Serial.println("Features: " + Features);

    // Cores
    Serial.printf("Cores: %d\r\n", chip_info.cores);

    // Revision
    Serial.printf("Revision: %d\r\n", chip_info.revision);

    // MAC Address
    String MACString = "";
    uint64_t chipid = ESP.getEfuseMac(); 
    for (int i=0; i<6; i++) {
      if (i > 0) MACString.concat(":");
      uint8_t Octet = chipid >> (i * 8);
      if (Octet > 16) MACString.concat("0");
      MACString.concat(String(Octet, HEX));
    }
    Serial.println("MAC Address: " + MACString);

    // Flash Size
    uint32_t FlashSize = ESP.getFlashChipSize();
    String ValueString = "";
    do {
      String temp = String(FlashSize);
      if (FlashSize >= 1000) {
        temp = "00" + temp;
        ValueString = "," + temp.substring(temp.length() - 3, temp.length()) + ValueString;
      } else {
        ValueString = temp + ValueString;
      }  
      FlashSize /= 1000;
    } while (FlashSize > 0);
    Serial.println("Flash Size: " + ValueString);
  }

void loop() {
  // put your main code here, to run repeatedly:

}
