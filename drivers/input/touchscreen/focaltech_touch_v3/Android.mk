DLKM_DIR := motorola/kernel/modules
LOCAL_PATH := $(call my-dir)

ifeq ($(call is-board-platform-in-list,taro kalama parrot), true)

ifneq ($(FOCALTECH_TOUCH_IC_NAME),)
	KBUILD_OPTIONS += CONFIG_INPUT_FOCALTECH_V3_MMI_IC_NAME=$(FOCALTECH_TOUCH_IC_NAME)
else
	KBUILD_OPTIONS += CONFIG_INPUT_FOCALTECH_V3_MMI_IC_NAME=ft3681
endif

ifeq ($(BOARD_USES_DOUBLE_TAP),true)
	KBUILD_OPTIONS += CONFIG_INPUT_FOCALTECH_V3_MMI_ENABLE_DOUBLE_TAP=y
ifeq ($(FTS_DOUBLE_TAP_CONTROL),true)
	KBUILD_OPTIONS += CONFIG_FTS_DOUBLE_TAP_CONTROL=y
endif
endif

ifneq ($(BOARD_USES_TOUCH_PALM),)
	KBUILD_OPTIONS += CONFIG_INPUT_FOCALTECH_V3_MMI_ENABLE_PALM=y
endif

ifneq ($(BOARD_USES_PEN_NOTIFIER),)
	KBUILD_OPTIONS += CONFIG_INPUT_FOCALTECH_V3_MMI_PEN_NOTIFIER=y
endif

ifneq ($(findstring touchscreen_mmi.ko,$(BOARD_VENDOR_KERNEL_MODULES)),)
    KBUILD_OPTIONS += CONFIG_INPUT_TOUCHSCREEN_MMI=y
endif

ifeq ($(DRM_PANEL_EVENT_NOTIFICATIONS),true)
	KBUILD_OPTIONS += CONFIG_DRM_PANEL_EVENT_NOTIFICATIONS=y
endif

ifeq ($(FTS_NOISE_TEST_P2P),true)
	KBUILD_OPTIONS += CONFIG_FTS_NOISE_TEST_P2P=y
endif

ifeq ($(FTS_COMPATIBLE_WITH_GKI),true)
	KBUILD_OPTIONS += CONFIG_FTS_COMPATIBLE_WITH_GKI=y
endif

ifeq ($(FTS_SUPPORT_HIGH_RESOLUTION),true)
	KBUILD_OPTIONS += CONFIG_FTS_SUPPORT_HIGH_RESOLUTION=y
endif

ifeq ($(FTS_VDD_GPIO_CONTROL),true)
	KBUILD_OPTIONS += CONFIG_FTS_VDD_GPIO_CONTROL=y
endif

ifeq ($(TOUCHSCREEN_LAST_TIME),true)
	KBUILD_OPTIONS += CONFIG_FTS_LAST_TIME=y
endif

else
ifneq ($(FOCALTECH_TOUCH_IC_NAME),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_V3_MMI_IC_NAME=$(FOCALTECH_TOUCH_IC_NAME)
else
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_V3_MMI_IC_NAME=ft3681
endif

ifeq ($(BOARD_USES_DOUBLE_TAP),true)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_V3_MMI_ENABLE_DOUBLE_TAP=y
endif

ifeq ($(FTS_DOUBLE_TAP_CONTROL),true)
	KERNEL_CFLAGS += CONFIG_FTS_DOUBLE_TAP_CONTROL=y
endif

ifneq ($(BOARD_USES_TOUCH_PALM),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_V3_MMI_ENABLE_PALM=y
endif

ifneq ($(BOARD_USES_PEN_NOTIFIER),)
	KERNEL_CFLAGS += CONFIG_INPUT_FOCALTECH_V3_MMI_PEN_NOTIFIER=y
endif

ifeq ($(FTS_SUPPORT_HIGH_RESOLUTION),true)
	KERNEL_CFLAGS += CONFIG_FTS_SUPPORT_HIGH_RESOLUTION=y
endif

ifeq ($(FTS_VDD_GPIO_CONTROL),true)
	KERNEL_CFLAGS += CONFIG_FTS_VDD_GPIO_CONTROL=y
endif

ifneq ($(findstring touchscreen_mmi.ko,$(BOARD_VENDOR_KERNEL_MODULES)),)
    KERNEL_CFLAGS += CONFIG_INPUT_TOUCHSCREEN_MMI=y
endif

ifeq ($(DRM_PANEL_NOTIFICATIONS),true)
	KERNEL_CFLAGS += CONFIG_DRM_PANEL_NOTIFICATIONS=y
endif

ifeq ($(TOUCHSCREEN_LAST_TIME),true)
	KERNEL_CFLAGS += CONFIG_FTS_LAST_TIME=y
endif

endif

include $(CLEAR_VARS)
LOCAL_MODULE := focaltech_v3.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
LOCAL_ADDITIONAL_DEPENDENCIES += $(KERNEL_MODULES_OUT)/mmi_info.ko
ifneq ($(findstring touchscreen_mmi.ko,$(BOARD_VENDOR_KERNEL_MODULES)),)
	LOCAL_ADDITIONAL_DEPENDENCIES += $(KERNEL_MODULES_OUT)/touchscreen_mmi.ko
endif

KBUILD_OPTIONS_GKI += GKI_OBJ_MODULE_DIR=gki
KBUILD_OPTIONS_GKI += MODULE_KERNEL_VERSION=$(TARGET_KERNEL_VERSION)
include $(DLKM_DIR)/AndroidKernelModule.mk
