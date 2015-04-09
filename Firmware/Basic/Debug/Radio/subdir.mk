################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Radio/cc1101.cpp 

OBJS += \
./Radio/cc1101.o 

CPP_DEPS += \
./Radio/cc1101.d 


# Each subdirectory must supply rules for building sources it contributes
Radio/cc1101.o: C:/Development/Workspace/ccproject/Firmware/Radio/cc1101.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/kl_lib -I../../Common/os/hal/include -I../../Common -I../inc -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -I../../Radio -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


