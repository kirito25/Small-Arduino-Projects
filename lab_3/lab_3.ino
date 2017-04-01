#include <EEPROM.h>

void setup() {
  Serial.begin(9600);

  // Part 1
  unsigned int i = 0;
  for (; i < 130; i++) {
    Serial.print("Address: ");
    Serial.print(i, HEX);
    Serial.print(" Value: ");
    Serial.println(EEPROM.read(i), DEC);
  }

  Serial.println();
  Serial.println();
  
  // Part 2
  i = 0;
  unsigned int previous = 0;
  for (char val = 0; val <= 126; val++) {
    EEPROM.write(i, val);
    if (val != EEPROM.read(i)) {
      Serial.println("There was a problem");
      exit(0);
    }
    previous = EEPROM.read(i) ^ previous;
    i++; 
  }
  
  unsigned char result = ~previous;
  if (result != EEPROM.read(127)) {
    EEPROM.write(127, result);
    Serial.println("EEPROM has been reinitialized");
  }
  else { Serial.println("EEPROM checksum is OK"); }
}

void loop() {
  // put your main code here, to run repeatedly:

}
