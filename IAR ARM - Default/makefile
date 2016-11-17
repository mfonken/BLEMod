################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/subdir.mk
-include src/subdir.mk
-include sensors/subdir.mk
-include kinetic/subdir.mk
-include emlib/subdir.mk
-include device/EFR32_B_B/iar/subdir.mk
-include ble/subdir.mk
-include app/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(MSA_UPPER_DEPS)),)
-include $(MSA_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S79_DEPS)),)
-include $(S79_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(MSA_DEPS)),)
-include $(MSA_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S79_UPPER_DEPS)),)
-include $(S79_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: BLEMod.out

# Tool invocations
BLEMod.out: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: IAR Linker for ARM'
	ilinkarm $(OBJS) $(USER_OBJS) -o "BLEMod.out" --config "C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\linker\bleDemo.icf" --no_wrap_diagnostics "C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/lib/binbootloader.o" "C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/lib/stack.a" "C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/lib/binstack.o" --entry __iar_program_start --no_range_reservations --keep __iar_program_start  
	ielftool --srec --verbose "BLEMod.out" "BLEMod.s37"  
	ielftool --ihex --verbose "BLEMod.out" "BLEMod.hex"  
	ielftool --bin --verbose "BLEMod.out" "BLEMod.bin"
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(MSA_UPPER_DEPS)$(EXECUTABLES)$(OBJS)$(ASM_DEPS)$(S79_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(MSA_DEPS)$(C_DEPS)$(S79_UPPER_DEPS) BLEMod.out
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
