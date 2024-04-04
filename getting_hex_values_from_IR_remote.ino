#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t kRecvPin = D5;  // Pin connected to the IR receiver
const int ledPin= D2;
const int ledPin2= D1;


IRrecv irrecv(kRecvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the IR receiver
  pinMode (ledPin,OUTPUT);
  pinMode (ledPin2,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the hexadecimal representation of the received IR code
    Serial.print("Received 0x");
    Serial.println(results.value, HEX);
// turning on LED1
    if (results.value == 0xFFA25DUL) 
    { // Note the UL suffix for unsigned long
    digitalWrite(ledPin, HIGH);
    }
    else if (results.value == 0xFF629DUL)
    { // Note the UL suffix for unsigned long
    digitalWrite(ledPin, LOW);
    }
// turning on LED2
    if (results.value == 0xFFE21DUL) 
    { // Note the UL suffix for unsigned long
    digitalWrite(ledPin2, HIGH);
    }
    else if (results.value == 0xFF629DUL)
    { // Note the UL suffix for unsigned long
    digitalWrite(ledPin2, LOW);
    }


    irrecv.resume();  // Receive the next IR code
  }
}
