################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/incr1.c \
../src/incr2.c \
../src/incr_anonymous.c \
../src/incr_dev_zero.c \
../src/sharedmemory_test.c 

OBJS += \
./src/incr1.o \
./src/incr2.o \
./src/incr_anonymous.o \
./src/incr_dev_zero.o \
./src/sharedmemory_test.o 

C_DEPS += \
./src/incr1.d \
./src/incr2.d \
./src/incr_anonymous.d \
./src/incr_dev_zero.d \
./src/sharedmemory_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


