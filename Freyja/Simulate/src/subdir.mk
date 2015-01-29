################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arm.cpp \
../src/AutonomousController.cpp \
../src/Drivetrain.cpp \
../src/Freyja.cpp \
../src/HumanController.cpp \
../src/Lifter.cpp \
../src/Robot.cpp 

OBJS += \
./src/Arm.o \
./src/AutonomousController.o \
./src/Drivetrain.o \
./src/Freyja.o \
./src/HumanController.o \
./src/Lifter.o \
./src/Robot.o 

CPP_DEPS += \
./src/Arm.d \
./src/AutonomousController.d \
./src/Drivetrain.d \
./src/Freyja.d \
./src/HumanController.d \
./src/Lifter.d \
./src/Robot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Freddy\git\Freyja\Freyja/src" -IC:\Users\Freddy/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


