################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/TOF/core/src/vl53lx_api.c \
../Drivers/TOF/core/src/vl53lx_api_calibration.c \
../Drivers/TOF/core/src/vl53lx_api_core.c \
../Drivers/TOF/core/src/vl53lx_api_debug.c \
../Drivers/TOF/core/src/vl53lx_api_preset_modes.c \
../Drivers/TOF/core/src/vl53lx_core.c \
../Drivers/TOF/core/src/vl53lx_core_support.c \
../Drivers/TOF/core/src/vl53lx_dmax.c \
../Drivers/TOF/core/src/vl53lx_hist_algos_gen3.c \
../Drivers/TOF/core/src/vl53lx_hist_algos_gen4.c \
../Drivers/TOF/core/src/vl53lx_hist_char.c \
../Drivers/TOF/core/src/vl53lx_hist_core.c \
../Drivers/TOF/core/src/vl53lx_hist_funcs.c \
../Drivers/TOF/core/src/vl53lx_nvm.c \
../Drivers/TOF/core/src/vl53lx_nvm_debug.c \
../Drivers/TOF/core/src/vl53lx_register_funcs.c \
../Drivers/TOF/core/src/vl53lx_sigma_estimate.c \
../Drivers/TOF/core/src/vl53lx_silicon_core.c \
../Drivers/TOF/core/src/vl53lx_wait.c \
../Drivers/TOF/core/src/vl53lx_xtalk.c 

OBJS += \
./Drivers/TOF/core/src/vl53lx_api.o \
./Drivers/TOF/core/src/vl53lx_api_calibration.o \
./Drivers/TOF/core/src/vl53lx_api_core.o \
./Drivers/TOF/core/src/vl53lx_api_debug.o \
./Drivers/TOF/core/src/vl53lx_api_preset_modes.o \
./Drivers/TOF/core/src/vl53lx_core.o \
./Drivers/TOF/core/src/vl53lx_core_support.o \
./Drivers/TOF/core/src/vl53lx_dmax.o \
./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.o \
./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.o \
./Drivers/TOF/core/src/vl53lx_hist_char.o \
./Drivers/TOF/core/src/vl53lx_hist_core.o \
./Drivers/TOF/core/src/vl53lx_hist_funcs.o \
./Drivers/TOF/core/src/vl53lx_nvm.o \
./Drivers/TOF/core/src/vl53lx_nvm_debug.o \
./Drivers/TOF/core/src/vl53lx_register_funcs.o \
./Drivers/TOF/core/src/vl53lx_sigma_estimate.o \
./Drivers/TOF/core/src/vl53lx_silicon_core.o \
./Drivers/TOF/core/src/vl53lx_wait.o \
./Drivers/TOF/core/src/vl53lx_xtalk.o 

C_DEPS += \
./Drivers/TOF/core/src/vl53lx_api.d \
./Drivers/TOF/core/src/vl53lx_api_calibration.d \
./Drivers/TOF/core/src/vl53lx_api_core.d \
./Drivers/TOF/core/src/vl53lx_api_debug.d \
./Drivers/TOF/core/src/vl53lx_api_preset_modes.d \
./Drivers/TOF/core/src/vl53lx_core.d \
./Drivers/TOF/core/src/vl53lx_core_support.d \
./Drivers/TOF/core/src/vl53lx_dmax.d \
./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.d \
./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.d \
./Drivers/TOF/core/src/vl53lx_hist_char.d \
./Drivers/TOF/core/src/vl53lx_hist_core.d \
./Drivers/TOF/core/src/vl53lx_hist_funcs.d \
./Drivers/TOF/core/src/vl53lx_nvm.d \
./Drivers/TOF/core/src/vl53lx_nvm_debug.d \
./Drivers/TOF/core/src/vl53lx_register_funcs.d \
./Drivers/TOF/core/src/vl53lx_sigma_estimate.d \
./Drivers/TOF/core/src/vl53lx_silicon_core.d \
./Drivers/TOF/core/src/vl53lx_wait.d \
./Drivers/TOF/core/src/vl53lx_xtalk.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/TOF/core/src/%.o Drivers/TOF/core/src/%.su Drivers/TOF/core/src/%.cyclo: ../Drivers/TOF/core/src/%.c Drivers/TOF/core/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/core/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/TOF/platform/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/IO_Expander/inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Bluetooth/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Motor/Inc" -I"C:/Users/catreggionpo/switchdrive/STM32CubeIDE_WS_STM32F401RE/Roboterauto_BAsic/Drivers/Display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-TOF-2f-core-2f-src

clean-Drivers-2f-TOF-2f-core-2f-src:
	-$(RM) ./Drivers/TOF/core/src/vl53lx_api.cyclo ./Drivers/TOF/core/src/vl53lx_api.d ./Drivers/TOF/core/src/vl53lx_api.o ./Drivers/TOF/core/src/vl53lx_api.su ./Drivers/TOF/core/src/vl53lx_api_calibration.cyclo ./Drivers/TOF/core/src/vl53lx_api_calibration.d ./Drivers/TOF/core/src/vl53lx_api_calibration.o ./Drivers/TOF/core/src/vl53lx_api_calibration.su ./Drivers/TOF/core/src/vl53lx_api_core.cyclo ./Drivers/TOF/core/src/vl53lx_api_core.d ./Drivers/TOF/core/src/vl53lx_api_core.o ./Drivers/TOF/core/src/vl53lx_api_core.su ./Drivers/TOF/core/src/vl53lx_api_debug.cyclo ./Drivers/TOF/core/src/vl53lx_api_debug.d ./Drivers/TOF/core/src/vl53lx_api_debug.o ./Drivers/TOF/core/src/vl53lx_api_debug.su ./Drivers/TOF/core/src/vl53lx_api_preset_modes.cyclo ./Drivers/TOF/core/src/vl53lx_api_preset_modes.d ./Drivers/TOF/core/src/vl53lx_api_preset_modes.o ./Drivers/TOF/core/src/vl53lx_api_preset_modes.su ./Drivers/TOF/core/src/vl53lx_core.cyclo ./Drivers/TOF/core/src/vl53lx_core.d ./Drivers/TOF/core/src/vl53lx_core.o ./Drivers/TOF/core/src/vl53lx_core.su ./Drivers/TOF/core/src/vl53lx_core_support.cyclo ./Drivers/TOF/core/src/vl53lx_core_support.d ./Drivers/TOF/core/src/vl53lx_core_support.o ./Drivers/TOF/core/src/vl53lx_core_support.su ./Drivers/TOF/core/src/vl53lx_dmax.cyclo ./Drivers/TOF/core/src/vl53lx_dmax.d ./Drivers/TOF/core/src/vl53lx_dmax.o ./Drivers/TOF/core/src/vl53lx_dmax.su ./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.cyclo ./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.d ./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.o ./Drivers/TOF/core/src/vl53lx_hist_algos_gen3.su ./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.cyclo ./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.d ./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.o ./Drivers/TOF/core/src/vl53lx_hist_algos_gen4.su ./Drivers/TOF/core/src/vl53lx_hist_char.cyclo ./Drivers/TOF/core/src/vl53lx_hist_char.d ./Drivers/TOF/core/src/vl53lx_hist_char.o ./Drivers/TOF/core/src/vl53lx_hist_char.su ./Drivers/TOF/core/src/vl53lx_hist_core.cyclo ./Drivers/TOF/core/src/vl53lx_hist_core.d ./Drivers/TOF/core/src/vl53lx_hist_core.o ./Drivers/TOF/core/src/vl53lx_hist_core.su ./Drivers/TOF/core/src/vl53lx_hist_funcs.cyclo ./Drivers/TOF/core/src/vl53lx_hist_funcs.d ./Drivers/TOF/core/src/vl53lx_hist_funcs.o ./Drivers/TOF/core/src/vl53lx_hist_funcs.su ./Drivers/TOF/core/src/vl53lx_nvm.cyclo ./Drivers/TOF/core/src/vl53lx_nvm.d ./Drivers/TOF/core/src/vl53lx_nvm.o ./Drivers/TOF/core/src/vl53lx_nvm.su ./Drivers/TOF/core/src/vl53lx_nvm_debug.cyclo ./Drivers/TOF/core/src/vl53lx_nvm_debug.d ./Drivers/TOF/core/src/vl53lx_nvm_debug.o ./Drivers/TOF/core/src/vl53lx_nvm_debug.su ./Drivers/TOF/core/src/vl53lx_register_funcs.cyclo ./Drivers/TOF/core/src/vl53lx_register_funcs.d ./Drivers/TOF/core/src/vl53lx_register_funcs.o ./Drivers/TOF/core/src/vl53lx_register_funcs.su ./Drivers/TOF/core/src/vl53lx_sigma_estimate.cyclo ./Drivers/TOF/core/src/vl53lx_sigma_estimate.d ./Drivers/TOF/core/src/vl53lx_sigma_estimate.o ./Drivers/TOF/core/src/vl53lx_sigma_estimate.su ./Drivers/TOF/core/src/vl53lx_silicon_core.cyclo ./Drivers/TOF/core/src/vl53lx_silicon_core.d ./Drivers/TOF/core/src/vl53lx_silicon_core.o ./Drivers/TOF/core/src/vl53lx_silicon_core.su ./Drivers/TOF/core/src/vl53lx_wait.cyclo ./Drivers/TOF/core/src/vl53lx_wait.d ./Drivers/TOF/core/src/vl53lx_wait.o ./Drivers/TOF/core/src/vl53lx_wait.su ./Drivers/TOF/core/src/vl53lx_xtalk.cyclo ./Drivers/TOF/core/src/vl53lx_xtalk.d ./Drivers/TOF/core/src/vl53lx_xtalk.o ./Drivers/TOF/core/src/vl53lx_xtalk.su

.PHONY: clean-Drivers-2f-TOF-2f-core-2f-src

