################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/UltrasonicSensor_Driver/Ultrasonic_program.c 

OBJS += \
./HAL/UltrasonicSensor_Driver/Ultrasonic_program.o 

C_DEPS += \
./HAL/UltrasonicSensor_Driver/Ultrasonic_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/UltrasonicSensor_Driver/%.o: ../HAL/UltrasonicSensor_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


