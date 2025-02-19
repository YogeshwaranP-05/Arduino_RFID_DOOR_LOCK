
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

// Define RC522 pins
#define RST_PIN 9
#define SS_PIN 10

// Relay pin
#define RELAY_PIN 8

// Initialize MFRC522 instance
MFRC522 rfid(SS_PIN, RST_PIN);

// Initialize LCD (address 0x27 may vary)
LiquidCrystal_I2C lcd(0x27, 16, 2);


// Authorized UID (replace with your tag's UID)
byte authorizedUID[] = {0x69, 0xA9, 0x81, 0x5A};

// Door status
bool doorLocked = true;

void setup() {
  // Initialize SPI and RC522
  SPI.begin();
  rfid.PCD_Init();

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Set up relay pin
  pinMode(RELAY_PIN, OUTPUT);

  // Display startup message
  lcd.setCursor(0, 0);
  lcd.print("RFID Door Lock");
  delay(2000);
  lcd.clear();
  lockDoor(); // Start with door locked
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

  // Display scanned UID
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning...");
  delay(2000);

  // Compare scanned UID with authorized UID
  if (isAuthorized(rfid.uid.uidByte, rfid.uid.size)) {
    lcd.setCursor(0, 1);
    lcd.print("Access Granted!");
    delay(2000);
    unlockDoor(); // Lock or unlock the door
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Access Denied!");
    delay(2000);
    lockDoor();
  }

  // Halt communication with the card
  rfid.PICC_HaltA();
}

// Function to check if UID matches authorized UID
bool isAuthorized(byte *uid, byte size) {
  if (size != sizeof(authorizedUID)) {
    return false;
  }

  for (byte i = 0; i < size; i++) {
    if (uid[i] != authorizedUID[i]) {
      return false;
    }
  }
  return true;
}

// Function to lock the door
void lockDoor() {
  digitalWrite(RELAY_PIN, LOW); // Turn OFF relay (lock engaged)
  doorLocked = true;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door Locked");
  delay(2000);
}

// Function to unlock the door
void unlockDoor() {
  digitalWrite(RELAY_PIN, HIGH); // Turn ON relay (unlock door)
  doorLocked = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door Unlocked");
  delay(10000); // Keep door unlocked for 5 seconds
  lockDoor();  // Auto-lock after 5 seconds
}
