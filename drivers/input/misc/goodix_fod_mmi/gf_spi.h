/*
 * driver definition for sensor driver
 * Copyright (C) 2016 Goodix
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __GF_SPI_H
#define __GF_SPI_H

#include <linux/types.h>
#include <linux/notifier.h>
/**********************************************************/
enum FP_MODE {
	GF_IMAGE_MODE = 0,
	GF_KEY_MODE,
	GF_SLEEP_MODE,
	GF_FF_MODE,
	GF_DEBUG_MODE = 0x56
};

#define SUPPORT_NAV_EVENT

#if defined(SUPPORT_NAV_EVENT)
#define GF_NAV_INPUT_UP			KEY_UP
#define GF_NAV_INPUT_DOWN		KEY_DOWN
#define GF_NAV_INPUT_LEFT		KEY_LEFT
#define GF_NAV_INPUT_RIGHT		KEY_RIGHT
#define GF_NAV_INPUT_CLICK		KEY_VOLUMEDOWN
#define GF_NAV_INPUT_DOUBLE_CLICK	KEY_VOLUMEUP
#define GF_NAV_INPUT_LONG_PRESS		KEY_SEARCH
#define GF_NAV_INPUT_HEAVY		KEY_CHAT
#endif

#define GF_KEY_INPUT_HOME		KEY_HOME
#define GF_KEY_INPUT_MENU		KEY_MENU
#define GF_KEY_INPUT_BACK		KEY_BACK
#define GF_KEY_INPUT_POWER		KEY_POWER
#define GF_KEY_INPUT_CAMERA		KEY_CAMERA

#if defined(SUPPORT_NAV_EVENT)
typedef enum gf_nav_event {
	GF_NAV_NONE = 0,
	GF_NAV_FINGER_UP,
	GF_NAV_FINGER_DOWN,
	GF_NAV_UP,
	GF_NAV_DOWN,
	GF_NAV_LEFT,
	GF_NAV_RIGHT,
	GF_NAV_CLICK,
	GF_NAV_HEAVY,
	GF_NAV_LONG_PRESS,
	GF_NAV_DOUBLE_CLICK,
} gf_nav_event_t;
#endif

typedef enum gf_key_event {
	GF_KEY_NONE = 0,
	GF_KEY_HOME,
	GF_KEY_POWER,
	GF_KEY_MENU,
	GF_KEY_BACK,
	GF_KEY_CAMERA,
} gf_key_event_t;

struct gf_key {
	enum gf_key_event key;
	uint32_t value;   /* key down = 1, key up = 0 */
};

struct gf_key_map {
	unsigned int type;
	unsigned int code;
};

struct gf_ioc_chip_info {
	unsigned char vendor_id;
	unsigned char mode;
	unsigned char operation;
	unsigned char reserved[5];
};

enum GF_IOC_COUNT {
	GF_IOC_INIT_COUNT = 0,
	GF_IOC_EXIT_COUNT,	// 1
	GF_IOC_RESET_COUNT,	// 2
	GF_IOC_ENABLE_IRQ_COUNT,	// 3
	GF_IOC_DISABLE_IRQ_COUNT,	// 4
	GF_IOC_ENABLE_SPI_CLK_COUNT,	// 5
	GF_IOC_DISABLE_SPI_CLK_COUNT,	// 6
	GF_IOC_ENABLE_POWER_COUNT,	// 7
	GF_IOC_DISABLE_POWER_COUNT,	// 8
	GF_IOC_INPUT_KEY_EVENT_COUNT,	// 9
	GF_IOC_ENTER_SLEEP_MODE_COUNT,	// 10
	GF_IOC_GET_FW_INFO_COUNT,	// 11
	GF_IOC_REMOVE_COUNT,	// 12
	GF_IOC_CHIP_INFO_COUNT,	// 13
#if defined(SUPPORT_NAV_EVENT)
	GF_IOC_NAV_EVENT_COUNT,	// 14
#else
	GF_IOC_14,	// 14
#endif
	GF_IOC_ENABLE_DEV_COUNT,	// 15
	GF_IOC_MAXNR,
};

#define GF_IOC_MAGIC    'g'
#define GF_IOC_INIT             _IOR(GF_IOC_MAGIC, GF_IOC_INIT_COUNT, uint8_t)
#define GF_IOC_EXIT             _IO(GF_IOC_MAGIC, GF_IOC_EXIT_COUNT)
#define GF_IOC_RESET            _IO(GF_IOC_MAGIC, GF_IOC_RESET_COUNT)
#define GF_IOC_ENABLE_IRQ       _IO(GF_IOC_MAGIC, GF_IOC_ENABLE_IRQ_COUNT)
#define GF_IOC_DISABLE_IRQ      _IO(GF_IOC_MAGIC, GF_IOC_DISABLE_IRQ_COUNT)
#define GF_IOC_ENABLE_SPI_CLK   _IOW(GF_IOC_MAGIC, GF_IOC_ENABLE_SPI_CLK_COUNT, uint32_t)
#define GF_IOC_DISABLE_SPI_CLK  _IO(GF_IOC_MAGIC, GF_IOC_DISABLE_SPI_CLK_COUNT)
#define GF_IOC_ENABLE_POWER     _IO(GF_IOC_MAGIC, GF_IOC_ENABLE_POWER_COUNT)
#define GF_IOC_DISABLE_POWER    _IO(GF_IOC_MAGIC, GF_IOC_DISABLE_POWER_COUNT)
#define GF_IOC_INPUT_KEY_EVENT  _IOW(GF_IOC_MAGIC, GF_IOC_INPUT_KEY_EVENT_COUNT, struct gf_key)
#define GF_IOC_ENTER_SLEEP_MODE _IO(GF_IOC_MAGIC, GF_IOC_ENTER_SLEEP_MODE_COUNT)
#define GF_IOC_GET_FW_INFO      _IOR(GF_IOC_MAGIC, GF_IOC_GET_FW_INFO_COUNT, uint8_t)
#define GF_IOC_REMOVE           _IO(GF_IOC_MAGIC, GF_IOC_REMOVE_COUNT)
#define GF_IOC_CHIP_INFO        _IOW(GF_IOC_MAGIC, GF_IOC_CHIP_INFO_COUNT, struct gf_ioc_chip_info)
#if defined(SUPPORT_NAV_EVENT)
#define GF_IOC_NAV_EVENT	_IOW(GF_IOC_MAGIC, GF_IOC_NAV_EVENT_COUNT, gf_nav_event_t)
#endif
#define GF_IOC_ENABLE_DEV   _IOW(GF_IOC_MAGIC, GF_IOC_ENABLE_DEV_COUNT, uint8_t)

/*#define AP_CONTROL_CLK       1*/
#define  USE_PLATFORM_BUS     1
/*#define  USE_SPI_BUS	1*/
/* #define GF_FASYNC    1*/	/*If support fasync mechanism.*/
#define GF_NETLINK_ENABLE 1
#define GF_NET_EVENT_IRQ 1
#define GF_NET_EVENT_FB_BLACK 2
#define GF_NET_EVENT_FB_UNBLACK 3
#define NETLINK_TEST 25

struct gf_dev {
	dev_t devt;
	struct list_head device_entry;
#if defined(USE_SPI_BUS)
	struct spi_device *spi;
#elif defined(USE_PLATFORM_BUS)
	struct platform_device *spi;
#endif
	struct clk *core_clk;
	struct clk *iface_clk;

	struct input_dev *input;
	/* buffer is NULL unless this device is open (users > 0) */
	unsigned int users;
	signed int irq_gpio;
	signed int reset_gpio;
	signed int pwr_gpio;
	unsigned int  rgltr_ctrl_support; //whether regulator control is supported
	struct regulator *pwr_supply;
	int pwr_voltage_range[2];
	int pwr_load[1];
	int irq;
	int irq_enabled;
	int clk_enabled;
	int power_enabled;
#ifdef GF_FASYNC
	struct fasync_struct *async;
#endif
	struct notifier_block notifier;
	char fb_black;
#if defined(CONFIG_GOODIX_DRM_PANEL_NOTIFICATIONS)
	struct drm_panel *active_panel;
#endif
};

int gf_parse_dts(struct gf_dev *gf_dev);
void gf_cleanup(struct gf_dev *gf_dev);

int gf_power_on(struct gf_dev *gf_dev);
int gf_power_off(struct gf_dev *gf_dev);

int gf_hw_reset(struct gf_dev *gf_dev, unsigned int delay_ms);
int gf_irq_num(struct gf_dev *gf_dev);

int sendnlmsg(char *msg);
int netlink_init(void);
void netlink_exit(void);
#endif /*__GF_SPI_H*/
