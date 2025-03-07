#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the I2C LCD (Address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// GPIO Pins for SDA and SCL
#define SDA_PIN 27
#define SCL_PIN 26

// GPIO Pins for Buttons
#define BUTTON_FORWARD 32
#define BUTTON_BACKWARD 33
#define BUTTON_REPEAT 34

// Array of Braille characters (example mappings)
const char *braille[] = {
  "⠁", "⠃", "⠉", "⠙", "⠑", "⠋", "⠛", "⠓", "⠊", "⠚",  // A-J
  "⠅", "⠇", "⠍", "⠝", "⠕", "⠏", "⠟", "⠗", "⠎", "⠞",  // K-T
  "⠥", "⠧", "⠭", "⠽", "⠵",                                // U-Z
  "⠼⠁", "⠼⠃", "⠼⠉", "⠼⠙", "⠼⠑", "⠼⠋", "⠼⠛", "⠼⠓", "⠼⠊", "⠼⠚" // 0-9
};

const char *labels[] = {
  "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
  "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
  "U", "V", "X", "Y", "Z", 
  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

int currentIndex = 0; // Tracks the current character index
int arraySize = sizeof(braille) / sizeof(braille[0]);

void setup() {
  // Initialize I2C LCD with custom SDA and SCL
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.begin();
  lcd.backlight();

  // Initialize buttons
  pinMode(BUTTON_FORWARD, INPUT_PULLUP);
  pinMode(BUTTON_BACKWARD, INPUT_PULLUP);
  pinMode(BUTTON_REPEAT, INPUT_PULLUP);

  // Display the first character
  displayCharacter();
}

void loop() {
  // Forward Button
  if (digitalRead(BUTTON_FORWARD) == LOW) {
    delay(200); // Debounce
    currentIndex = (currentIndex + 1) % arraySize; // Move forward
    displayCharacter();
  }

  // Backward Button
  if (digitalRead(BUTTON_BACKWARD) == LOW) {
    delay(200); // Debounce
    currentIndex = (currentIndex - 1 + arraySize) % arraySize; // Move backward
    displayCharacter();
  }

  // Repeat Button
  if (digitalRead(BUTTON_REPEAT) == LOW) {
    delay(200); // Debounce
    displayCharacter(); // Re-display the current character
  }
}

void displayCharacter() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Char: ");
  lcd.print(labels[currentIndex]);
  lcd.setCursor(0, 1);
  lcd.print("Braille: ");
  lcd.print(braille[currentIndex]);
}
