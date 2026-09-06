#include <Arduino.h> 

uint8_t value; //Declare a variable to hold the binary number. 
 
void setup() { 

DDRD &= 0x0F; // sets resigister D to have the first for bits as input (0000) and the last 4 bits as output (1111) 0x0F = 00001111 
DDRB &= 0xF0; // sets resigister B to have the first for bits as output (1111) and the last 4 bits as input (0000) 0xF0 = 11110000 
PORTD |= 0xF0; // Configure PD4 through PD7 as inputs using internal pull-up resistors (|= is the pullup command) 
Serial.begin(9600);   //Start serial communications. 

} 
void loop() { 
value = PIND;  // Read the entire Port D register. 
value &= 0xF0; // Apply a mask to isolate bits PD7 through PD4. (use &=) 
value = value >> 4;   // Shift the value four positions to the right. 
value = ~value; // Invert the value. (value = ~value) 
value &= 0x0F;  // Apply a mask to keep only four bits. (we did the same thing for DDRD) 
value = ~value; // Invert the value again to apply 2's complement. 
vlue = value + 1; // Add 1 to the value to complete the 2's complement operation. 
value &= 0x0F; 
PORTB = value;  // Display the value on the LEDs. and displays it  
delay(250); // Wait for 250 milliseconds. 

Serial.print("Binary (2's complement) "); // Print the value to the Serial Monitor. 
Serial.print(value,BIN); 
Serial.print("   Decimal "); 
Serial.println(value); 
} 

 

 