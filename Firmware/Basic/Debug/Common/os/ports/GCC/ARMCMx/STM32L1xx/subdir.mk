################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/STM32L1xx/vectors.c 

OBJS += \
./Common/os/ports/GCC/ARMCMx/STM32L1xx/vectors.o 

C_DEPS += \
./Common/os/ports/GCC/ARMCMx/STM32L1xx/vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Common/os/ports/GCC/ARMCMx/STM32L1xx/vectors.o: C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/STM32L1xx/vectors.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


