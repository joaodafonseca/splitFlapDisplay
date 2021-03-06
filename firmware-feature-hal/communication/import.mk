COMMUNICATION_MODULE_PATH ?= ../communication

ifdef PRODUCT_ID
COMMUNICATION_TARGET_DIR = $(BUILD_TARGET_PLATFORM)-prod-$(PRODUCT_ID)
else
COMMUNICATION_TARGET_DIR = $(BUILD_TARGET_PLATFORM)
endif

COMMUNICATION_LIB_DIR = $(BUILD_PATH_BASE)/communication/$(COMMUNICATION_TARGET_DIR)
COMMUNICATION_LIB_DEP = $(COMMUNICATION_LIB_DIR)/libcommunication.a

PRODUCT_ID ?= 65535
PRODUCT_FIRMWARE_VERSION ?= 65535

CFLAGS += -DPRODUCT_ID=$(PRODUCT_ID)
CFLAGS += -DPRODUCT_FIRMWARE_VERSION=$(PRODUCT_FIRMWARE_VERSION)

include $(call rwildcard,$(COMMUNICATION_MODULE_PATH)/,include.mk)
