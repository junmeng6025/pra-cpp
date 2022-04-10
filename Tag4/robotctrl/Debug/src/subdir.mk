################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InterfaceSIM.cpp \
../src/KeyboardCtrl.cpp \
../src/PIDCtrl.cpp \
../src/main.cpp 

OBJS += \
./src/InterfaceSIM.o \
./src/KeyboardCtrl.o \
./src/PIDCtrl.o \
./src/main.o 

CPP_DEPS += \
./src/InterfaceSIM.d \
./src/KeyboardCtrl.d \
./src/PIDCtrl.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../ncurses.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


