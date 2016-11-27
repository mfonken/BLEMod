################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sensors/imu.c 

OBJS += \
./sensors/imu.o 

C_DEPS += \
./sensors/imu.d 


# Each subdirectory must supply rules for building sources it contributes
sensors/imu.o: ../sensors/imu.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --enum_is_int --no_wrap_diagnostics -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//hardware/kit/common/bsp" -IC:/Users/Matthew%252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/uartdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/radio/rail_lib_1.3/chip/efr32/rf/common/cortex" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/spidrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/rtcdrv/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\src" -IC:/Users/Matthew%252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod/src -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/ustimer/inc" -IC:/Users/Matthew%25252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod/.externalToolBuilders -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/ble" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/capsense/inc" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/kinetic" -IC:/Users/Matthew%252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod/.externalToolBuilders -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/tempdrv/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/sleep/inc" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/app" -IC:/Users/Matthew%25252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod/src -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/Device/SiliconLabs/EFR32BG1B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/nvm/inc" -IC:/Users/Matthew%25252525252525252525252525252525252520Fonken/SimplicityStudio/v4_workspace/BLEMod -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/common/inc" -I"C:/Users/Matthew Fonken/SimplicityStudio/v4_workspace/BLEMod/system" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/ble_stack/inc/common" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//protocol/bluetooth_2.0/ble_stack/inc/soc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.0.1.0//platform/emlib/inc" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DSILABS_AF_USE_HWCONF=1' '-DGENERATION_DONE=1' '-D__NO_SYSTEM_INIT=1' '-DEFR32BG1B232F256GM32=1' --diag_suppress pa050 --diag_error pe223 --dependencies=m sensors/imu.d
	@echo 'Finished building: $<'
	@echo ' '


