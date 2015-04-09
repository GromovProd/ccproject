################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/kl_sprintf.c 

CPP_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/clocking_L1xx.cpp \
C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/cmd_uart.cpp \
C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/kl_lib_L15x.cpp 

OBJS += \
./Common/kl_lib/clocking_L1xx.o \
./Common/kl_lib/cmd_uart.o \
./Common/kl_lib/kl_lib_L15x.o \
./Common/kl_lib/kl_sprintf.o 

C_DEPS += \
./Common/kl_lib/kl_sprintf.d 

CPP_DEPS += \
./Common/kl_lib/clocking_L1xx.d \
./Common/kl_lib/cmd_uart.d \
./Common/kl_lib/kl_lib_L15x.d 


# Each subdirectory must supply rules for building sources it contributes
Common/kl_lib/clocking_L1xx.o: C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/clocking_L1xx.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/kl_lib -I../../Common/os/hal/include -I../../Common -I../inc -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -I../../Radio -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/kl_lib/cmd_uart.o: C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/cmd_uart.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/kl_lib -I../../Common/os/hal/include -I../../Common -I../inc -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -I../../Radio -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/kl_lib/kl_lib_L15x.o: C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/kl_lib_L15x.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/kl_lib -I../../Common/os/hal/include -I../../Common -I../inc -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -I../../Radio -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/kl_lib/kl_sprintf.o: C:/Development/Workspace/ccproject/Firmware/Common/kl_lib/kl_sprintf.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


