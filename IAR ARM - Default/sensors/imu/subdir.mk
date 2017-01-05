################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sensors/imu/LSM9DS1.c \
../sensors/imu/LSM9DS1_regs.c 

OBJS += \
./sensors/imu/LSM9DS1.o \
./sensors/imu/LSM9DS1_regs.o 

C_DEPS += \
./sensors/imu/LSM9DS1.d \
./sensors/imu/LSM9DS1_regs.d 


# Each subdirectory must supply rules for building sources it contributes
sensors/imu/LSM9DS1.o: ../sensors/imu/LSM9DS1.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --enum_is_int --no_wrap_diagnostics -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\camera" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//hardware/kit/common/drivers" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\kinetic" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/uartdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/spidrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/gpiointerrupt/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\touch" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/spidrv/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\src" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/rtcdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/ustimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/radio/rail_lib/chip/efr32/rf/common/cortex" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/ustimer/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/dmadrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/tempdrv/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\imu" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/uartdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/tempdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/nvm/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/sleep/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/Device/SiliconLabs/EFR32BG1B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/nvm/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\system" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//protocol/bluetooth_2.1/ble_stack/inc/common" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//protocol/bluetooth_2.1/ble_stack/inc/soc" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DSILABS_AF_USE_HWCONF=1' '-DGENERATION_DONE=1' '-D__NO_SYSTEM_INIT=1' '-DEFR32BG1B232F256GM32=1' --diag_suppress pa050 --diag_error pe223 --dependencies=m sensors/imu/LSM9DS1.d
	@echo 'Finished building: $<'
	@echo ' '

sensors/imu/LSM9DS1_regs.o: ../sensors/imu/LSM9DS1_regs.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --enum_is_int --no_wrap_diagnostics -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\camera" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//hardware/kit/common/drivers" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\kinetic" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/uartdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/spidrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/gpiointerrupt/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\touch" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/spidrv/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\src" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/rtcdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/ustimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/radio/rail_lib/chip/efr32/rf/common/cortex" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/ustimer/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/dmadrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/tempdrv/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\sensors\imu" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/uartdrv/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/tempdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/nvm/config" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/sleep/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/Device/SiliconLabs/EFR32BG1B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/nvm/inc" -I"C:\Users\Matthew Fonken\SimplicityStudio\v4_workspace\BLEMod\system" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//protocol/bluetooth_2.1/ble_stack/inc/common" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/stacks/ble/v2.1.1.0//protocol/bluetooth_2.1/ble_stack/inc/soc" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DSILABS_AF_USE_HWCONF=1' '-DGENERATION_DONE=1' '-D__NO_SYSTEM_INIT=1' '-DEFR32BG1B232F256GM32=1' --diag_suppress pa050 --diag_error pe223 --dependencies=m sensors/imu/LSM9DS1_regs.d
	@echo 'Finished building: $<'
	@echo ' '


