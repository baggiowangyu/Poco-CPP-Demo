#Generated by VisualGDB (http://visualgdb.com)
#DO NOT EDIT THIS FILE MANUALLY UNLESS YOU ABSOLUTELY NEED TO
#USE VISUALGDB PROJECT PROPERTIES DIALOG INSTEAD

BINARYDIR := Debug

#Toolchain
CC := gcc
CXX := g++
LD := $(CXX)
AR := ar
OBJCOPY := objcopy

#Additional flags
PREPROCESSOR_MACROS := DEBUG=1
INCLUDE_DIRS := /usr/local/poco/include
LIBRARY_DIRS := /usr/local/poco/lib
LIBRARY_NAMES := PocoFoundationd
ADDITIONAL_LINKER_INPUTS := 
MACOS_FRAMEWORKS := 
LINUX_PACKAGES := 

CFLAGS := -ggdb -ffunction-sections -O0
CXXFLAGS := -ggdb -ffunction-sections -O0
ASFLAGS := 
LDFLAGS := -Wl,-gc-sections
COMMONFLAGS := 
LINKER_SCRIPT := 

START_GROUP := 
END_GROUP := 

#Additional options detected from testing the toolchain
IS_LINUX_PROJECT := 1
