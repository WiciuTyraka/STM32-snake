################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f103xb.s 

OBJS += \
./startup/startup_stm32f103xb.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"C:/Users/Samsung/Documents/stm32/helloSTM32/HAL_Driver/Inc/Legacy" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/Utilities/STM32F1xx_Nucleo" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/inc" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/CMSIS/device" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/CMSIS/core" -I"C:/Users/Samsung/Documents/stm32/helloSTM32/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


