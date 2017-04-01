#include <avr/pgmspace.h>

const char array1[] PROGMEM = {"Array 1"};
const char array2[] = {"Array 2"};
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  //Part 1
  Serial.print("FLASHEND: ");
  Serial.println(FLASHEND, HEX);
  Serial.print("RAMEND: ");
  Serial.println(RAMEND, HEX);
  Serial.print("E2END: ");
  Serial.println(E2END, HEX);
  //end of Part 1
  //Part 2
  //Create pointer of a function
  void (* pointer)() = &test;
  //called function using pointer
  (*pointer)();
  Serial.print("(int) &test: ");
  Serial.println((int) &test, HEX);
  Serial.print("(int) &pointer: ");
  Serial.println((int) &pointer, HEX);
  Serial.print("int value at pointer in RAM: ");
  Serial.println((int) (*((int *) pointer)), HEX);
  Serial.print("int value at pointer in program memory: ");
  Serial.println((int) pgm_read_word(pointer), HEX);
  // End of Part 2
  // Part 3
  const char array3[] = {"Array 3"};
  char * array4 = (char *) malloc(strlen("Array 4") + 1);
  strcpy(array4, "Array 4");

  Serial.println("Printing Array1: ");
  for (int i = 0; i < strlen(array1); i++) {
    Serial.print((char) pgm_read_byte(&array1[i]));
  }
  Serial.println();
  Serial.println("Address of Array1 : ");
  Serial.println((int) &array1[0], HEX);
  
  Serial.println("Address of Array2 : ");
  Serial.println((int) &array2[0], HEX);
  
  Serial.println("Address of Array3 : ");
  Serial.println((int) &array3[0], HEX);
  
  Serial.println("Address of Array4 : ");
  Serial.println((int) &array4[0], HEX);
}

void loop() { }

void test() {
  Serial.println("Function was called");
}

