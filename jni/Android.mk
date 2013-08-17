LOCAL_PATH := $(call my-dir)__

include $(CLEAR_VARS)

LOCAL_MODULE :=Calculator
LOCAL_SRC_FILES := ../src/add.c\
                    ../src/sub.c\
                    ../src/div.c\
                    ../src/mul.c
                    
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
                   
LOCAL_STATIC_LIBRARIES := ../src/additon.dll\
                    ../src/subtract.dll\
                     ../src/divide.dll\
                     ../src/multiply.dll


include $(BUILD_SHARED_LIBRARY)
