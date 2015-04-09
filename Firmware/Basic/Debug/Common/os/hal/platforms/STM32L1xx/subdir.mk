################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/ext_lld_isr.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/stm32_dma.c 

CPP_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/hal_lld.cpp 

OBJS += \
./Common/os/hal/platforms/STM32L1xx/ext_lld_isr.o \
./Common/os/hal/platforms/STM32L1xx/hal_lld.o \
./Common/os/hal/platforms/STM32L1xx/stm32_dma.o 

C_DEPS += \
./Common/os/hal/platforms/STM32L1xx/ext_lld_isr.d \
./Common/os/hal/platforms/STM32L1xx/stm32_dma.d 

CPP_DEPS += \
./Common/os/hal/platforms/STM32L1xx/hal_lld.d 


# Each subdirectory must supply rules for building sources it contributes
Common/os/hal/platforms/STM32L1xx/ext_lld_isr.o: C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/ext_lld_isr.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/hal/platforms/STM32L1xx/hal_lld.o: C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/hal_lld.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/kl_lib -I../../Common/os/hal/include -I../../Common -I../inc -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -I../../Radio -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/hal/platforms/STM32L1xx/stm32_dma.o: C:/Development/Workspace/ccproject/Firmware/Common/os/hal/platforms/STM32L1xx/stm32_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


