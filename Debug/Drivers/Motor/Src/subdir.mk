################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Motor/Src/motorDriver.c 

OBJS += \
./Drivers/Motor/Src/motorDriver.o 

C_DEPS += \
./Drivers/Motor/Src/motorDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Motor/Src/%.o Drivers/Motor/Src/%.su Drivers/Motor/Src/%.cyclo: ../Drivers/Motor/Src/%.c Drivers/Motor/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/core/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/platform/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/IO_Expander/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Bluetooth/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Motor/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Motor-2f-Src

clean-Drivers-2f-Motor-2f-Src:
	-$(RM) ./Drivers/Motor/Src/motorDriver.cyclo ./Drivers/Motor/Src/motorDriver.d ./Drivers/Motor/Src/motorDriver.o ./Drivers/Motor/Src/motorDriver.su

.PHONY: clean-Drivers-2f-Motor-2f-Src

