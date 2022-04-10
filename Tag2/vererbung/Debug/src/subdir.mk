################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Person.cpp \
../src/Student.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Person.d \
./src/Student.d \
./src/main.d 

OBJS += \
./src/Person.o \
./src/Student.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Person.d ./src/Person.o ./src/Student.d ./src/Student.o ./src/main.d ./src/main.o

.PHONY: clean-src

