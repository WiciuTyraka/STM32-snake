################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/font.c \
../src/lcd.c \
../src/main.c \
../src/snake.c \
../src/stm32f1xx_it.c \
../src/syscalls.c \
../src/system_stm32f1xx.c 

OBJS += \
./src/font.o \
./src/lcd.o \
./src/main.o \
./src/snake.o \
./src/stm32f1xx_it.o \
./src/syscalls.o \
./src/system_stm32f1xx.o 

C_DEPS += \
./src/font.d \
./src/lcd.d \
./src/main.d \
./src/snake.d \
./src/stm32f1xx_it.d \
./src/syscalls.d \
./src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -I"C:/Users/Samsung/Documents/stm32/helloSTM32/HAL_Driver/Inc/Legacy" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/Utilities/STM32F1xx_Nucleo" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/inc" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/CMSIS/device" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/CMSIS/core" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


