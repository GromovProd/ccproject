################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kl_lib/kl_sprintf.c 

CPP_SRCS += \
../kl_lib/clocking_L1xx.cpp \
../kl_lib/cmd_uart.cpp \
../kl_lib/kl_lib_L15x.cpp 

OBJS += \
./kl_lib/clocking_L1xx.o \
./kl_lib/cmd_uart.o \
./kl_lib/kl_lib_L15x.o \
./kl_lib/kl_sprintf.o 

C_DEPS += \
./kl_lib/kl_sprintf.d 

CPP_DEPS += \
./kl_lib/clocking_L1xx.d \
./kl_lib/cmd_uart.d \
./kl_lib/kl_lib_L15x.d 


# Each subdirectory must supply rules for building sources it contributes
kl_lib/%.o: ../kl_lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/hal/ARMCMx -I../os/kernel/include -I../kl_lib -I../inc -std=gnu++0x -fabi-version=0 -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

kl_lib/%.o: ../kl_lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/hal/ARMCMx -I../os/kernel/include -I../kl_lib -I../inc -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


