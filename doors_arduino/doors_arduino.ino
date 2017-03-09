// Include BLE files.
#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <LiquidCrystal.h>

// Define output pin
#define LED_PIN 2

LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void setup()
{
  // Enable serial debug.
  Serial.begin(9600);
  Serial.println("Arduino EasyBLE example started");
  Serial.println("Serial rate set to 9600");

  // Enable output.
  pinMode(LED_PIN, OUTPUT);

  // Turn off LED.
  digitalWrite(LED_PIN, LOW);

  // Initialize BLE library.
  ble_begin();

  // Set a custom BLE name.
  char name = 'b';
  //ble_set_name(&name);

  Serial.println("ble_begin done!");
  lcd.begin(16, 1);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

// This function is called continuously, after setup() completes.
void loop()
{
  // If there's any input...
  while (ble_available())
  {
    // Read input.
    int c = ble_read();
    Serial.println("Got input:");
    if (c != 0)
    {
      // Non-zero input means "turn on LED".
      Serial.println("Led: on");
      digitalWrite(LED_PIN, HIGH);
      // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("LOCKED");
    }
    else
    {
      // Input value zero means "turn off LED".
      Serial.println("Led: off");
      digitalWrite(LED_PIN, LOW);
      // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("UNLOCKED");
    }
  }

  // Process BLE events.
  ble_do_events();
}
