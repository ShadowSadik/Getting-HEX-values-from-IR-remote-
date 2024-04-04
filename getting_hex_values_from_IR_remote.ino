#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t kRecvPin = D5;  // Pin connected to the IR receiver

IRrecv irrecv(kRecvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the hexadecimal representation of the received IR code
    Serial.print("Received 0x");
    Serial.println(results.value, HEX);
    
    irrecv.resume();  // Receive the next IR code
  }
}
