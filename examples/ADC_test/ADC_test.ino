#include <MCP3202.h>

//D13 - CK
//D12 - DOUT
//D11 - DIN
//D10 - CS

// You can also refer to this website!
// Thanks to baturman for making this schematic.
// https://easyeda.com/baturman/arduino-uno-r3-mcp3202-wiring-diagram

MCP3202 adc = MCP3202(10);

int channel1 = 0;
int channel2 = 0;
void setup() {
  // put your setup code here, to run once:
  adc.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  channel1 = adc.readChannel(0);
  channel2 = adc.readChannel(1);
  Serial.print(channel1);
  Serial.print("\t");
  Serial.println(channel2);
  delay(100);
}
