ifneq ($(MTK_EMULATOR_SUPPORT), yes)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
  IPQService.cpp \
  PQService.cpp \
  PQClient.cpp \
  PQAshmemProxy.cpp

ifeq ($(strip $(MTK_PQ_COLOR_MODE)),MDP)
    LOCAL_CFLAGS += -DDISP_COLOR_OFF
else ifeq ($(strip $(MTK_PQ_COLOR_MODE)),OFF)
    LOCAL_CFLAGS += -DDISP_COLOR_OFF
endif

ifeq ($(strip $(MTK_PQ_COLOR_MODE)),MDP)
    LOCAL_CFLAGS += -DMDP_COLOR_ENABLE
else ifeq ($(strip $(MTK_PQ_COLOR_MODE)),DISP_MDP)
    LOCAL_CFLAGS += -DMDP_COLOR_ENABLE
endif

ifeq ($(strip $(MTK_GLOBAL_PQ_SUPPORT)),yes)
    LOCAL_CFLAGS += -DMTK_GLOBAL_PQ_SUPPORT
endif

ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6580))
    LOCAL_CFLAGS += -DCCORR_OFF
endif

ifeq ($(MTK_BLULIGHT_DEFENDER_SUPPORT),yes)
    LOCAL_CFLAGS += -DMTK_BLULIGHT_DEFENDER_SUPPORT
endif

ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6797))
    LOCAL_CFLAGS += -DTDSHP_2_0
endif

ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6797))
    LOCAL_CFLAGS += -DCOLOR_2_1
endif

ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6797))
    LOCAL_CFLAGS += -DRSZ_2_0
endif

ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6797))
    # Dynamic Sharpenss After 6797
    LOCAL_CFLAGS += -DDYN_SHARP_VERSION=1
    LOCAL_CFLAGS += -DDYN_CONTRAST_VERSION=1
else
    # Dynamic Sharpenss Before 6755
    LOCAL_CFLAGS += -DDYN_SHARP_VERSION=0
    LOCAL_CFLAGS += -DDYN_CONTRAST_VERSION=0
endif

LOCAL_C_INCLUDES += \
        $(TOP)/$(MTK_PATH_SOURCE)/hardware/dpframework/include \
        $(TOP)/frameworks/base/include \
        $(TOP)/$(MTK_PATH_PLATFORM)/kernel/drivers/dispsys \
        $(MTK_PATH_PLATFORM)/hardware/pq \
        $(TOP)/$(MTK_PATH_SOURCE)/platform/$(MTK_PLATFORM_DIR)/kernel/drivers/dispsys \
        $(TOP)/$(MTK_PATH_SOURCE)/kernel/drivers/video \
        $(TOP)/$(MTK_PATH_SOURCE)/kernel/include \
        $(TOP)/$(MTK_PATH_SOURCE)/hardware/pq/v2.0/include \
        $(TOP)/$(MTK_PATH_SOURCE)/hardware/pq/v2.0/lib \
        $(TOP)/$(MTK_ROOT)/frameworks-ext/native/include \


LOCAL_SHARED_LIBRARIES := \
    libutils \
    libcutils \
    libdl \
    libbinder \
    libpq_prot \

LOCAL_MODULE:= libpqservice
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk


include $(MTK_SHARED_LIBRARY)

endif