HEADERS_FOLDERS=-I ./headers -I ./headers/builtins -I ./headers/SoftPosit
BUILD_FOLDER=build
SOURCE_FOLDER=source

CC=gcc
CPP=g++
CFLAGS=-c -Wall ${HEADERS_FOLDERS} 
LDFLAGS=

SOURCES=\
	source/Float32.cpp \
	source/Float64.cpp \
	source/SoftFloat32.cpp \
	source/SoftFloat64.cpp \
	source/SoftPosit32.cpp \
	source/SoftPosit16.cpp \
	source/SoftPosit8.cpp \
	source/builtins/negsf2.cpp \
	source/builtins/addsf3.cpp \
	source/builtins/subsf3.cpp \
	source/builtins/mulsf3.cpp \
	source/builtins/divsf3.cpp \
	source/builtins/comparesf2.cpp \
	source/builtins/negdf2.cpp \
	source/builtins/adddf3.cpp \
	source/builtins/subdf3.cpp \
	source/builtins/muldf3.cpp \
	source/builtins/divdf3.cpp \
	source/builtins/comparedf2.cpp
SOURCES_C=\
	source/SoftPosit/p32_add.c \
	source/SoftPosit/p32_div.c \
	source/SoftPosit/p32_mul.c \
	source/SoftPosit/p32_sub.c \
	source/SoftPosit/p32_lt.c \
	source/SoftPosit/p32_mulAdd.c \
	source/SoftPosit/s_mulAddP32.c \
	source/SoftPosit/s_addMagsP32.c \
	source/SoftPosit/s_subMagsP32.c \
	source/SoftPosit/c_convertDecToPosit32.c \
	source/SoftPosit/c_convertPosit32ToDec.c \
	source/SoftPosit/p16_add.c \
	source/SoftPosit/p16_div.c \
	source/SoftPosit/p16_mul.c \
	source/SoftPosit/p16_sub.c \
	source/SoftPosit/p16_lt.c \
	source/SoftPosit/p16_mulAdd.c \
	source/SoftPosit/s_mulAddP16.c \
	source/SoftPosit/s_addMagsP16.c \
	source/SoftPosit/s_subMagsP16.c \
	source/SoftPosit/c_convertDecToPosit16.c \
	source/SoftPosit/c_convertPosit16ToDec.c \
	source/SoftPosit/p8_add.c \
	source/SoftPosit/p8_div.c \
	source/SoftPosit/p8_mul.c \
	source/SoftPosit/p8_sub.c \
	source/SoftPosit/p8_lt.c \
	source/SoftPosit/p8_mulAdd.c \
	source/SoftPosit/s_mulAddP8.c \
	source/SoftPosit/s_addMagsP8.c \
	source/SoftPosit/s_subMagsP8.c \
	source/SoftPosit/c_convertDecToPosit8.c \
	source/SoftPosit/c_convertPosit8ToDec.c \
	source/SoftPosit/quire32_fdp_add.c \
	source/SoftPosit/quire32_fdp_sub.c \
	source/SoftPosit/c_convertQuire32ToPosit32.c \
	source/SoftPosit/quire16_fdp_add.c \
	source/SoftPosit/quire16_fdp_sub.c \
	source/SoftPosit/c_convertQuire16ToPosit16.c \
	source/SoftPosit/quire8_fdp_add.c \
	source/SoftPosit/quire8_fdp_sub.c \
	source/SoftPosit/c_convertQuire8ToPosit8.c

OBJECTS=$(SOURCES:.cpp=.o) $(SOURCES_C:.c=.o)
TARGETS=muller neuro

#targets($@): prerequisites($<)
#        <commands>

all: $(SOURCES_CPP) $(SOURCES_C) $(TARGETS)

muller: $(OBJECTS)
	$(CPP) $(LDFLAGS) source/muller.cpp $(OBJECTS) -lm -o $@  ${HEADERS_FOLDERS}

neuro: $(OBJECTS)
	$(CPP) $(LDFLAGS) source/neuro.cpp $(OBJECTS) -lm -o $@  ${HEADERS_FOLDERS}

.cpp.o:
	$(CPP) $(CFLAGS) $< -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf $(TARGETS) $(OBJECTS)