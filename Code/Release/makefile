################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer_Driver/subdir.mk
-include MCAL/SPI_Driver/subdir.mk
-include MCAL/GPIO_Driver/subdir.mk
-include MCAL/Ex_Interrupt_Driver/subdir.mk
-include HAL/UltrasonicSensor_Driver/subdir.mk
-include HAL/LED_Driver/subdir.mk
-include HAL/LCD_Driver/subdir.mk
-include HAL/DCMotor_Driver/subdir.mk
-include HAL/Button_Driver/subdir.mk
-include Application_Layer/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Avoidance_App.lss \

FLASH_IMAGE += \
Avoidance_App.hex \

EEPROM_IMAGE += \
Avoidance_App.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Avoidance_App.elf secondary-outputs

# Tool invocations
Avoidance_App.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Avoidance_App.map -mmcu=atmega32 -o "Avoidance_App.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Avoidance_App.lss: Avoidance_App.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Avoidance_App.elf  >"Avoidance_App.lss"
	@echo 'Finished building: $@'
	@echo ' '

Avoidance_App.hex: Avoidance_App.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Avoidance_App.elf  "Avoidance_App.hex"
	@echo 'Finished building: $@'
	@echo ' '

Avoidance_App.eep: Avoidance_App.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Avoidance_App.elf  "Avoidance_App.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Avoidance_App.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Avoidance_App.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Avoidance_App.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
