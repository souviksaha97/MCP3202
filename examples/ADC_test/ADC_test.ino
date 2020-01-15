#include <MCP3202.h>

//D13 - CK
//D12 - DOUT
//D11 - DIN
//D10 - CS

// You can also refer to this website!
// Thanks to baturman for making this schematic.
// https://easyeda.com/baturman/arduino-uno-r3-mcp3202-wiring-diagram

/**
 *  This code shall return the voltage value in terms of a decimal value.
 *  4096 means the voltage is equal to Vdd, while 0 means voltage is Vss.
 */


int Vdd = 5; //change according to your Vdd value.

MCP3202 adc = MCP3202(10); //Parameter passed is the CS pin number. Change according to requirement.

float channel1 = 0;
float channel2 = 0;
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
  
  //To print voltage value, uncomment these lines
  
  //float voltage1 = (channel1*Vdd)/4096.0;
  //float voltage2 = (channel2*Vdd)/4096.0;
  //Serial.print(voltage1);
  //Serial.print("\t");
  //Serial.println(voltage2);
  
  delay(100);
}
