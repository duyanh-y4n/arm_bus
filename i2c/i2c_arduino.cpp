/**
 * File            : i2c_arduino.cpp
 * Author          : Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 * Date            : 15.06.2020
 * Last Modified By: Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 */
#ifndef I2C_ARDUINO_C
#define I2C_ARDUINO_C
 
#include<Arduino.h>
#include<Wire.h>
#include"i2c_arduino.h"

void i2c_begin(){
    Wire.begin();
}

uint8_t I2c_read_reg_16(uint8_t devAddr, uint8_t regAddr, uint16_t *data) {
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.endTransmission();
  Wire.requestFrom(devAddr, (uint8_t)2);
  if (Wire.available() < 2) {
    // no response or transmission not completed
    return -1;
  }
  *data = Wire.read() << 8;
  *data = *data + Wire.read();
  delay(10);
  return 0;
}

uint8_t I2c_read_reg_8b(uint8_t devAddr, uint8_t regAddr, uint8_t *data) {
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.endTransmission();
  Wire.requestFrom(devAddr, (uint8_t)1);
  if (Wire.available() < 2) {
    // no response or transmission not completed
    return -1;
  }
  *data = Wire.read();
  // delay(10);
  return 0;
}

void I2c_write_reg_16b(uint8_t devAddr, uint8_t regAddr, uint16_t data) {
  uint8_t temp;
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  temp = data >> 8;
  Wire.write(temp);
  temp = data;
  Wire.write(temp);
  Wire.endTransmission();
  delay(500);
}

void I2c_write_reg_8b(uint8_t devAddr, uint8_t regAddr, uint8_t data) {
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.write(data);
  Wire.endTransmission();
  delay(500);
}

void I2c_write_command(uint8_t devAddr, uint8_t command) {
  Wire.beginTransmission(devAddr);
  Wire.write(command);
  Wire.endTransmission();
}


#endif /* I2C_ARDUINO_C */
