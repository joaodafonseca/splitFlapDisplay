
# USRSRC is location of source files relative to SOURCE_PATH
# default is src in this module
USRSRC=src

# TARGET_FILE sets the file stem of the target. It's typically only specified when building applications.
ifdef TARGET_FILE
TARGET_FILE_NAME = $(TARGET_FILE)
endif

# TARGET_DIR is the externally specified target directory
ifdef TARGET_DIR
TARGET_PATH = $(TARGET_DIR)
endif

# SOURCE_PATH - the root of all sources. Defaults to the module dir
# USRSRC - relative path to SOURCE_PATH for the sources to build

# determine where user sources are, relative to project root
ifdef APP
USER_MAKEFILE ?= $(APP).mk
USRSRC = applications/$(APP)
# when TARGET_FILE is defined on the command line, 
TARGET_FILE_NAME ?= $(notdir $(APP))
TARGET_DIR_NAME ?= $(USRSRC)
endif

ifdef APPDIR
# APPDIR is where the sources are found
# if TARGET_DIR is not defined defaults to $(APPDIR)/target
# if TARGET_FILE_NAME is not defined, defaults to the name of the $(APPDIR)
USRSRC = 
SOURCE_PATH = $(APPDIR)
TARGET_FILE_NAME ?= $(notdir $(APPDIR))
TARGET_DIR_NAME = $(APPDIR)/target
# do not use $(BUILD_PATH) since the TARGET_DIR specifies fully where the output should go
TARGET_PATH ?= $(TARGET_DIR_NAME)
BUILD_PATH = $(TARGET_PATH)/obj
endif


ifdef TEST
USRSRC = tests/$(TEST)
INCLUDE_PLATFORM?=1
TARGET_FILE_NAME ?= $(notdir $(TEST))
TARGET_DIR_NAME ?= $(USRSRC)
include $(MODULE_PATH)/tests/tests.mk
-include $(MODULE_PATH)/$(USRSRC)/test.mk
endif

USRSRC_SLASH = $(and $(USRSRC),$(USRSRC)/)
USER_MAKEFILE ?= build.mk
usrmakefile = $(wildcard $(SOURCE_PATH)/$(USRSRC_SLASH)$(USER_MAKEFILE))
ifeq ("$(usrmakefile)","")
INCLUDE_DIRS += $(SOURCE_PATH)/$(USRSRC)  # add user sources to include path
# add C and CPP files - if USRSRC is not empty, then add a slash
CPPSRC += $(call target_files,$(USRSRC_SLASH),*.cpp)
CSRC += $(call target_files,$(USRSRC_SLASH),*.c)    
else
include $(usrmakefile)
endif

INCLUDE_DIRS += $(MODULE_PATH)/libraries

 INCLUDE_DIRS += ../spark-flashee-eeprom/firmware
 CPPSRC += ../spark-flashee-eeprom/firmware/flashee-eeprom.cpp
 CPPSRC += ../spark-flashee-eeprom/firmware/ff.cpp

CFLAGS += -DSPARK_PLATFORM_NET=$(PLATFORM_NET)

