################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
thermostatController.lss \

FLASH_IMAGE += \
thermostatController.hex \

EEPROM_IMAGE += \
thermostatController.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: thermostatController.elf secondary-outputs

# Tool invocations
thermostatController.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,thermostatController.map -mmcu=atmega328p -o "thermostatController.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

thermostatController.lss: thermostatController.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S thermostatController.elf  >"thermostatController.lss"
	@echo 'Finished building: $@'
	@echo ' '

thermostatController.hex: thermostatController.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex thermostatController.elf  "thermostatController.hex"
	@echo 'Finished building: $@'
	@echo ' '

thermostatController.eep: thermostatController.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex thermostatController.elf  "thermostatController.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: thermostatController.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p thermostatController.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) thermostatController.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
