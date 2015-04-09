################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chcond.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chdebug.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chdynamic.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chevents.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chheap.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chlists.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmboxes.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmemcore.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmempools.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmsg.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmtx.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chqueues.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chregistry.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chschd.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chsem.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chsys.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chthreads.c \
C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chvt.c 

OBJS += \
./Common/os/kernel/src/chcond.o \
./Common/os/kernel/src/chdebug.o \
./Common/os/kernel/src/chdynamic.o \
./Common/os/kernel/src/chevents.o \
./Common/os/kernel/src/chheap.o \
./Common/os/kernel/src/chlists.o \
./Common/os/kernel/src/chmboxes.o \
./Common/os/kernel/src/chmemcore.o \
./Common/os/kernel/src/chmempools.o \
./Common/os/kernel/src/chmsg.o \
./Common/os/kernel/src/chmtx.o \
./Common/os/kernel/src/chqueues.o \
./Common/os/kernel/src/chregistry.o \
./Common/os/kernel/src/chschd.o \
./Common/os/kernel/src/chsem.o \
./Common/os/kernel/src/chsys.o \
./Common/os/kernel/src/chthreads.o \
./Common/os/kernel/src/chvt.o 

C_DEPS += \
./Common/os/kernel/src/chcond.d \
./Common/os/kernel/src/chdebug.d \
./Common/os/kernel/src/chdynamic.d \
./Common/os/kernel/src/chevents.d \
./Common/os/kernel/src/chheap.d \
./Common/os/kernel/src/chlists.d \
./Common/os/kernel/src/chmboxes.d \
./Common/os/kernel/src/chmemcore.d \
./Common/os/kernel/src/chmempools.d \
./Common/os/kernel/src/chmsg.d \
./Common/os/kernel/src/chmtx.d \
./Common/os/kernel/src/chqueues.d \
./Common/os/kernel/src/chregistry.d \
./Common/os/kernel/src/chschd.d \
./Common/os/kernel/src/chsem.d \
./Common/os/kernel/src/chsys.d \
./Common/os/kernel/src/chthreads.d \
./Common/os/kernel/src/chvt.d 


# Each subdirectory must supply rules for building sources it contributes
Common/os/kernel/src/chcond.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chcond.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chdebug.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chdebug.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chdynamic.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chdynamic.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chevents.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chevents.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chheap.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chheap.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chlists.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chlists.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chmboxes.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmboxes.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chmemcore.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmemcore.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chmempools.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmempools.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chmsg.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmsg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chmtx.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chmtx.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chqueues.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chqueues.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chregistry.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chregistry.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chschd.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chschd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chsem.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chsem.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chsys.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chsys.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chthreads.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chthreads.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/os/kernel/src/chvt.o: C:/Development/Workspace/ccproject/Firmware/Common/os/kernel/src/chvt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -ffunction-sections -fdata-sections -Wall  -g -I../../Common/os -I../../Common/os/kernel/include -I../../Common/os/hal/include -I../../Common/os/hal/platforms/STM32L1xx -I../../Common/os/ports/common/ARMCMx/CMSIS/include -I../../Common/os/ports/GCC/ARMCMx -I../../Common/os/ports/GCC/ARMCMx/STM32L1xx -I../../Common/os/ports/common/ARMCMx -I../../Common/os/hal/platforms/STM32 -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


