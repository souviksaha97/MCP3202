#include <MCP3202.h>
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
  channel1 = readChannel(0);
  channel2 = readChannel(1);
  Serial.print(channel1);
  Serial.print("\t");
  Serial.println(channel2);
  delay(100);
}
