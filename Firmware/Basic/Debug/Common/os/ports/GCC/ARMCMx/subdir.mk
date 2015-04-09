################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/chcore.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/chcore_v7m.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/crt0.c 

OBJS += \
./Common/os/ports/GCC/ARMCMx/chcore.o \
./Common/os/ports/GCC/ARMCMx/chcore_v7m.o \
./Common/os/ports/GCC/ARMCMx/crt0.o 

C_DEPS += \
./Common/os/ports/GCC/ARMCMx/chcore.d \
./Common/os/ports/GCC/ARMCMx/chcore_v7m.d \
./Common/os/ports/GCC/ARMCMx/crt0.d 


# Each subdirectory must supply rules for building sources it contributes
Common/os/ports/GCC/ARMCMx/chcore.o: C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/chcore.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/ports/GCC/ARMCMx/chcore_v7m.o: C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/chcore_v7m.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/ports/GCC/ARMCMx/crt0.o: C:/Development/Workspace/ccproject/Firmware/Common/os/ports/GCC/ARMCMx/crt0.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


