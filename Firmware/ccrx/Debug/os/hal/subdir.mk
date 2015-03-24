################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/hal/ext.c \
../os/hal/ext_lld_isr.c \
../os/hal/hal.c \
../os/hal/nvic.c \
../os/hal/rtc.c \
../os/hal/stm32_dma.c \
../os/hal/vectors.c 

CPP_SRCS += \
../os/hal/hal_lld.cpp 

OBJS += \
./os/hal/ext.o \
./os/hal/ext_lld_isr.o \
./os/hal/hal.o \
./os/hal/hal_lld.o \
./os/hal/nvic.o \
./os/hal/rtc.o \
./os/hal/stm32_dma.o \
./os/hal/vectors.o 

C_DEPS += \
./os/hal/ext.d \
./os/hal/ext_lld_isr.d \
./os/hal/hal.d \
./os/hal/nvic.d \
./os/hal/rtc.d \
./os/hal/stm32_dma.d \
./os/hal/vectors.d 

CPP_DEPS += \
./os/hal/hal_lld.d 


# Each subdirectory must supply rules for building sources it contributes
os/hal/%.o: ../os/hal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/hal/ARMCMx -I../os/kernel/include -I../kl_lib -I../inc -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/hal/%.o: ../os/hal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/hal/ARMCMx -I../os/kernel/include -I../kl_lib -I../inc -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


