################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/IO_Expander/src/ioExpander.c 

OBJS += \
./Drivers/IO_Expander/src/ioExpander.o 

C_DEPS += \
./Drivers/IO_Expander/src/ioExpander.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/IO_Expander/src/%.o Drivers/IO_Expander/src/%.su Drivers/IO_Expander/src/%.cyclo: ../Drivers/IO_Expander/src/%.c Drivers/IO_Expander/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/core/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/platform/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/IO_Expander/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Bluetooth/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Motor/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-IO_Expander-2f-src

clean-Drivers-2f-IO_Expander-2f-src:
	-$(RM) ./Drivers/IO_Expander/src/ioExpander.cyclo ./Drivers/IO_Expander/src/ioExpander.d ./Drivers/IO_Expander/src/ioExpander.o ./Drivers/IO_Expander/src/ioExpander.su

.PHONY: clean-Drivers-2f-IO_Expander-2f-src

