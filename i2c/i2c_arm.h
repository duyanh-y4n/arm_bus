/**
 * File            : i2c_arm.h
 * Author          : Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 * Date            : 15.06.2020
 * Last Modified By: Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 */
#ifndef I2C_ARM_H
#define I2C_ARM_H

extern void i2c_begin();

extern uint8_t I2c_read_reg_16(uint8_t devAddr, uint8_t regAddr, uint16_t *data);

extern uint8_t I2c_read_reg_8b(uint8_t devAddr, uint8_t regAddr, uint8_t *data);

extern void I2c_write_reg_16b(uint8_t devAddr, uint8_t regAddr, uint16_t data);

extern void I2c_write_reg_8b(uint8_t devAddr, uint8_t regAddr, uint8_t data);

extern void I2c_write_command(uint8_t devAddr, uint8_t command);

#endif /* I2C_ARM_H */
