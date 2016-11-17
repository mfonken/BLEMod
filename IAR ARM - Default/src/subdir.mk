################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/InitDevice.c 

OBJS += \
./src/InitDevice.o 

C_DEPS += \
./src/InitDevice.d 


# Each subdirectory must supply rules for building sources it contributes
src/InitDevice.o: ../src/InitDevice.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --enum_is_int --no_wrap_diagnostics -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\inc" -IC:/Users/Matthew%20Fonken/SimplicityStudio/v4_workspace/BLEMod -IC:/Users/Matthew%20Fonken/SimplicityStudio/v4_workspace/BLEMod/.externalToolBuilders -IC:/Users/Matthew%20Fonken/SimplicityStudio/v4_workspace/BLEMod/src -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/Device/SiliconLabs/EFR32BG1B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/capsense/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/nvm/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/sleep/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/spidrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/tempdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/uartdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/ustimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/radio/rail_lib_1.3/chip/efr32/rf/common/cortex" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/.externalToolBuilders" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/src" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\src" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/ble_stack/inc/common" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/ble_stack/inc/soc" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/app" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/kinetic" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/system" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/ble" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DGENERATION_DONE=1' '-DSILABS_AF_USE_HWCONF=1' '-D__NO_SYSTEM_INIT=1' '-DEFR32BG1B232F256GM32=1' --diag_suppress pa050 --diag_suppress pa050 --diag_error pe223 --diag_error pe223 --dependencies=m src/InitDevice.d
	@echo 'Finished building: $<'
	@echo ' '


