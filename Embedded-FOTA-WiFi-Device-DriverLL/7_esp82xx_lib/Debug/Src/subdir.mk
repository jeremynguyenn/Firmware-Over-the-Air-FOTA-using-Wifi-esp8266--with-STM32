################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/bsp.c \
../Src/circular_buffer.c \
../Src/esp82xx_driver.c \
../Src/esp82xx_lib.c \
../Src/fpu.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timebase.c 

OBJS += \
./Src/adc.o \
./Src/bsp.o \
./Src/circular_buffer.o \
./Src/esp82xx_driver.o \
./Src/esp82xx_lib.o \
./Src/fpu.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timebase.o 

C_DEPS += \
./Src/adc.d \
./Src/bsp.d \
./Src/circular_buffer.d \
./Src/esp82xx_driver.d \
./Src/esp82xx_lib.d \
./Src/fpu.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timebase.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"C:/Users/user/Documents/Embedded-FOTA-WiFi/7_esp82xx_lib/chip_headers/CMSIS/Include" -I"C:/Users/user/Documents/Embedded-FOTA-WiFi/7_esp82xx_lib/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/bsp.d ./Src/bsp.o ./Src/bsp.su ./Src/circular_buffer.d ./Src/circular_buffer.o ./Src/circular_buffer.su ./Src/esp82xx_driver.d ./Src/esp82xx_driver.o ./Src/esp82xx_driver.su ./Src/esp82xx_lib.d ./Src/esp82xx_lib.o ./Src/esp82xx_lib.su ./Src/fpu.d ./Src/fpu.o ./Src/fpu.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/timebase.d ./Src/timebase.o ./Src/timebase.su

.PHONY: clean-Src

