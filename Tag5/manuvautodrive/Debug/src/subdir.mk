################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InterfaceSIM.cpp \
../src/Maneuver.cpp \
../src/PIDCtrl.cpp \
../src/PosEstimation.cpp \
../src/RobotControl.cpp \
../src/main.cpp 

OBJS += \
./src/InterfaceSIM.o \
./src/Maneuver.o \
./src/PIDCtrl.o \
./src/PosEstimation.o \
./src/RobotControl.o \
./src/main.o 

CPP_DEPS += \
./src/InterfaceSIM.d \
./src/Maneuver.d \
./src/PIDCtrl.d \
./src/PosEstimation.d \
./src/RobotControl.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../ncurses.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


