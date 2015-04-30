
# defines 
# PLATFORM_NAME - a unique name for the platform, can be used to organise sources
#                 by platform
# PLATFORM_MCU  - an identifier for the MCU family
# STM32_DEVICE  - the specific device being targeted for STM32 platform builds
# PLATFORM_NET  - the network subsystem
# ARCH		- architecture (ARM/GCC)
# PRODUCT_DESC  - text description of the product ID

ifndef PLATFORM_ID
PLATFORM_ID=0
endif

# Determine which is the target device

ARCH=arm

ifeq ("$(PLATFORM_ID)","0")
STM32_DEVICE=STM32F10X_MD
PLATFORM_NAME=core-v1
PLATFORM_MCU=STM32F1xx
PLATFORM_NET=CC3000
PRODUCT_DESC=Spark core
endif

ifeq ("$(PLATFORM_ID)","1")
STM32_DEVICE=STM32F10X_MD
PLATFORM_NAME=core-v1
PLATFORM_MCU=STM32F1xx
PLATFORM_NET=CC3000
PRODUCT_DESC=Teacup Pigtail
endif

ifeq ("$(PLATFORM_ID)","2")
STM32_DEVICE=STM32F10X_HD
PLATFORM_NAME=core-v1
PLATFORM_MCU=STM32F1xx
PLATFORM_NET=CC3000
PRODUCT_DESC=Spark core-HD, 256k flash, 48k ram
endif

ifeq ("$(PLATFORM_ID)","3")
PLATFORM_NAME=gcc
PLATFORM_MCU=gcc
PLATFORM_NET=gcc
ARCH=gcc
PRODUCT_DESC=GCC xcompile
# explicitly exclude platform headers
SPARK_NO_PLATFORM=1
endif

ifeq ("$(PLATFORM_ID)","4")
STM32_DEVICE=STM32F2XX
PLATFORM_NAME=core-v2
PLATFORM_MCU=STM32F2xx
PLATFORM_NET=WICED
PRODUCT_DESC=Spark core-v2/WICED
endif


ifeq ("$(PLATFORM_MCU)","")
$(error PLATFORM_MCU not defined. Check product id $(PLATFORM_ID))
endif

ifeq ("$(PLATFORM_NET)","")
$(error PLATFORM_NET not defined. Check product id $(PLATFORM_ID))
endif

# lower case version of the STM32_DEVICE string for use in filenames
STM32_DEVICE_LC  = $(shell echo $(STM32_DEVICE) | tr A-Z a-z)

ifdef STM32_DEVICE
# needed for conditional compilation of syshealth_hal.h
CFLAGS += -DSTM32_DEVICE
# needed for conditional compilation of some stm32 specific files
CFLAGS += -D$(STM32_DEVICE)
endif

CFLAGS += -DPLATFORM_ID=$(PLATFORM_ID)



