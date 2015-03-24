################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../os/hal/ARMCMx/chcore.c \
../os/hal/ARMCMx/chcore_v7m.c \
../os/hal/ARMCMx/crt0.c 

OBJS += \
./os/hal/ARMCMx/chcore.o \
./os/hal/ARMCMx/chcore_v7m.o \
./os/hal/ARMCMx/crt0.o 

C_DEPS += \
./os/hal/ARMCMx/chcore.d \
./os/hal/ARMCMx/chcore_v7m.d \
./os/hal/ARMCMx/crt0.d 


# Each subdirectory must supply rules for building sources it contributes
os/hal/ARMCMx/%.o: ../os/hal/ARMCMx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../os -I../os/hal -I../os/hal/ARMCMx -I../os/kernel/include -I../kl_lib -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


