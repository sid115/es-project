################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lookup_table.c \
../Core/Src/main.c \
../Core/Src/maze.c \
../Core/Src/numbers.c \
../Core/Src/prng.c \
../Core/Src/ram_usage.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/ws2812_SPI.c 

OBJS += \
./Core/Src/lookup_table.o \
./Core/Src/main.o \
./Core/Src/maze.o \
./Core/Src/numbers.o \
./Core/Src/prng.o \
./Core/Src/ram_usage.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/ws2812_SPI.o 

C_DEPS += \
./Core/Src/lookup_table.d \
./Core/Src/main.d \
./Core/Src/maze.d \
./Core/Src/numbers.d \
./Core/Src/prng.d \
./Core/Src/ram_usage.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/ws2812_SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/lookup_table.cyclo ./Core/Src/lookup_table.d ./Core/Src/lookup_table.o ./Core/Src/lookup_table.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/maze.cyclo ./Core/Src/maze.d ./Core/Src/maze.o ./Core/Src/maze.su ./Core/Src/numbers.cyclo ./Core/Src/numbers.d ./Core/Src/numbers.o ./Core/Src/numbers.su ./Core/Src/prng.cyclo ./Core/Src/prng.d ./Core/Src/prng.o ./Core/Src/prng.su ./Core/Src/ram_usage.cyclo ./Core/Src/ram_usage.d ./Core/Src/ram_usage.o ./Core/Src/ram_usage.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/ws2812_SPI.cyclo ./Core/Src/ws2812_SPI.d ./Core/Src/ws2812_SPI.o ./Core/Src/ws2812_SPI.su

.PHONY: clean-Core-2f-Src

