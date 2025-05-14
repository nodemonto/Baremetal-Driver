################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/stm32l4gpio.c 

OBJS += \
./Inc/stm32l4gpio.o 

C_DEPS += \
./Inc/stm32l4gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/Arun/Documents/Baremetal driver/Baremetal_driver_development/driver/inc" -I"C:/Users/Arun/Documents/Baremetal driver/Baremetal_driver_development/driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/stm32l4gpio.cyclo ./Inc/stm32l4gpio.d ./Inc/stm32l4gpio.o ./Inc/stm32l4gpio.su

.PHONY: clean-Inc

