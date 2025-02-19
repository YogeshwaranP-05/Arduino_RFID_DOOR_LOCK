#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>

// Define RC522 RFID module pins
#define RST_PIN 9   // Reset pin
#define SS_PIN 10   // Slave Select pin

// Initialize MFRC522 instance
MFRC522 rfid(SS_PIN, RST_PIN);

// Initialize the I2C LCD (set the I2C address, usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize SPI and RC522 module
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan RFID Card");
  Serial.println("Scan RFID Card");
}

void loop() {
  // Check if a new RFID card is present
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Check if the RFID card can be read
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Clear LCD and display the UID
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Card UID:");
  Serial.print("Card UID: ");

  // Print the UID on the LCD
  lcd.setCursor(0, 1);
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      lcd.print("0"); // Add leading 0 for single-digit hex
      Serial.print("0x0");
    }

    lcd.print(rfid.uid.uidByte[i], HEX); // Print UID byte in HEX format
    Serial.print("0x");
    Serial.print(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      lcd.print(" "); // Add space between bytes
      Serial.print(", ");
    }
    delay(1000);
  }

  // Halt communication with the card
  rfid.PICC_HaltA();

  // Wait for 10 seconds before clearing the LCD
  delay(10000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan RFID Card");
  Serial.println("\n");
  Serial.println("Scan RFID Card");
}

