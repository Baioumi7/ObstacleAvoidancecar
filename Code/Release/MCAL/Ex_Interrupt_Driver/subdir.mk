################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Ex_Interrupt_Driver/EXTI_program.c 

OBJS += \
./MCAL/Ex_Interrupt_Driver/EXTI_program.o 

C_DEPS += \
./MCAL/Ex_Interrupt_Driver/EXTI_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Ex_Interrupt_Driver/%.o: ../MCAL/Ex_Interrupt_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


