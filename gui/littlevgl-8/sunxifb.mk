#
# Copyright (C) 2006-2010 OpenWrt.org
# Copyright (C) 2016-2016 tracewong
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

ifeq ($(CONFIG_LVGL8_USE_SUNXIFB_DOUBLE_BUFFER),y)
TARGET_CFLAGS+=-DUSE_SUNXIFB_DOUBLE_BUFFER
endif

ifeq ($(CONFIG_LVGL8_USE_SUNXIFB_CACHE),y)
TARGET_CFLAGS+=-DUSE_SUNXIFB_CACHE
endif

ifeq ($(CONFIG_LVGL8_USE_SUNXIFB_G2D),y)
TARGET_CFLAGS+=-DUSE_SUNXIFB_G2D
TARGET_LDFLAGS+=-luapi
endif

ifeq ($(CONFIG_LVGL8_USE_SUNXIFB_G2D_ROTATE),y)
TARGET_CFLAGS+=-DUSE_SUNXIFB_G2D_ROTATE
endif

ifeq ($(CONFIG_LINUX_5_4),y)
TARGET_CFLAGS+=-DCONF_G2D_VERSION_NEW
endif

ifeq ($(CONFIG_LVGL8_USE_FREETYPE),y)
TARGET_CFLAGS+=-I$(STAGING_DIR)/usr/include/freetype2
TARGET_LDFLAGS+=-lfreetype
endif