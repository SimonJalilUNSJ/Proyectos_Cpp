################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ContenedorFallaDeTomate.cpp \
../FallaDeTomate.cpp \
../Main.cpp \
../YML.cpp \
../metodosProcesamiento.cpp 

OBJS += \
./ContenedorFallaDeTomate.o \
./FallaDeTomate.o \
./Main.o \
./YML.o \
./metodosProcesamiento.o 

CPP_DEPS += \
./ContenedorFallaDeTomate.d \
./FallaDeTomate.d \
./Main.d \
./YML.d \
./metodosProcesamiento.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


