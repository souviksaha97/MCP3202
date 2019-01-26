//Release Date: 15-12-2018
//souvikssaha@gmail.com

/*===========================================================================
DAC7611 device library code is placed under the MIT license
Copyright (c) 2018 Souvik Saha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================*/




#include "MCP3202.h"
#include "Arduino.h"
#include "SPI.h"

MCP3202::MCP3202(int CS){
    chipSel = CS;

}

void MCP3202::begin(void)
{
  pinMode(chipSel,OUTPUT);
  digitalWrite(chipSel, HIGH);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE3);
  SPI.begin();
}

unsigned int MCP3202::readChannel(byte thisCh)
{
  unsigned int dataIn = 0;
  unsigned int result = 0;
  digitalWrite(chipSel, LOW);
  uint8_t dataOut = 0b00000001;
  dataIn = SPI.transfer(dataOut);
  dataOut = (thisCh == 0) ? 0b10100000 : 0b11100000;
  dataIn = SPI.transfer(dataOut);
  result = dataIn & 0x0F;
  dataIn = SPI.transfer(0x00);
  result = result << 8;
  result = result | dataIn;
  //input = input << 1;
  digitalWrite(chipSel, HIGH);
  return result;        
}
 

