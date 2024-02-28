################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/TOF/platform/src/TOF_driver.c \
../Drivers/TOF/platform/src/vl53lx_platform.c \
../Drivers/TOF/platform/src/vl53lx_platform_init.c \
../Drivers/TOF/platform/src/vl53lx_platform_ipp.c \
../Drivers/TOF/platform/src/vl53lx_platform_log.c 

OBJS += \
./Drivers/TOF/platform/src/TOF_driver.o \
./Drivers/TOF/platform/src/vl53lx_platform.o \
./Drivers/TOF/platform/src/vl53lx_platform_init.o \
./Drivers/TOF/platform/src/vl53lx_platform_ipp.o \
./Drivers/TOF/platform/src/vl53lx_platform_log.o 

C_DEPS += \
./Drivers/TOF/platform/src/TOF_driver.d \
./Drivers/TOF/platform/src/vl53lx_platform.d \
./Drivers/TOF/platform/src/vl53lx_platform_init.d \
./Drivers/TOF/platform/src/vl53lx_platform_ipp.d \
./Drivers/TOF/platform/src/vl53lx_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/TOF/platform/src/%.o Drivers/TOF/platform/src/%.su Drivers/TOF/platform/src/%.cyclo: ../Drivers/TOF/platform/src/%.c Drivers/TOF/platform/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/core/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/platform/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/IO_Expander/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Bluetooth/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Motor/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-TOF-2f-platform-2f-src

clean-Drivers-2f-TOF-2f-platform-2f-src:
	-$(RM) ./Drivers/TOF/platform/src/TOF_driver.cyclo ./Drivers/TOF/platform/src/TOF_driver.d ./Drivers/TOF/platform/src/TOF_driver.o ./Drivers/TOF/platform/src/TOF_driver.su ./Drivers/TOF/platform/src/vl53lx_platform.cyclo ./Drivers/TOF/platform/src/vl53lx_platform.d ./Drivers/TOF/platform/src/vl53lx_platform.o ./Drivers/TOF/platform/src/vl53lx_platform.su ./Drivers/TOF/platform/src/vl53lx_platform_init.cyclo ./Drivers/TOF/platform/src/vl53lx_platform_init.d ./Drivers/TOF/platform/src/vl53lx_platform_init.o ./Drivers/TOF/platform/src/vl53lx_platform_init.su ./Drivers/TOF/platform/src/vl53lx_platform_ipp.cyclo ./Drivers/TOF/platform/src/vl53lx_platform_ipp.d ./Drivers/TOF/platform/src/vl53lx_platform_ipp.o ./Drivers/TOF/platform/src/vl53lx_platform_ipp.su ./Drivers/TOF/platform/src/vl53lx_platform_log.cyclo ./Drivers/TOF/platform/src/vl53lx_platform_log.d ./Drivers/TOF/platform/src/vl53lx_platform_log.o ./Drivers/TOF/platform/src/vl53lx_platform_log.su

.PHONY: clean-Drivers-2f-TOF-2f-platform-2f-src

