/*
 * Copyright 2018 - 2022 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USB_DEVICE_CONFIG_H__
#define __USB_DEVICE_CONFIG_H__

#include <zephyr/devicetree.h>
#include "usb.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/
/* EHCI instance count */
#ifdef CONFIG_USB_DC_NXP_EHCI
#define USB_DEVICE_CONFIG_EHCI (1U)
/* How many the DTD are supported. */
#define USB_DEVICE_CONFIG_EHCI_MAX_DTD (16U)
#endif /* CONFIG_USB_DC_NXP_EHCI */

#ifdef CONFIG_USB_DC_NXP_LPCIP3511

#ifdef USBHSD_BASE_ADDRS
#define USB_DEVICE_CONFIG_LPCIP3511HS (1U)
#else
#define USB_DEVICE_CONFIG_LPCIP3511HS (0U)
#endif

#ifdef USB_BASE_ADDRS
#define USB_DEVICE_CONFIG_LPCIP3511FS (1U)
#else
#define USB_DEVICE_CONFIG_LPCIP3511FS (0U)
#endif

#endif /* CONFIG_USB_DC_NXP_LPCIP3511 */

/* Whether device is self power. 1U supported, 0U not supported */
#define USB_DEVICE_CONFIG_SELF_POWER (1U)

#define NUM_INSTS DT_NUM_INST_STATUS_OKAY(nxp_ehci) + DT_NUM_INST_STATUS_OKAY(nxp_lpcip3511)
BUILD_ASSERT(NUM_INSTS <= 1, "Only one USB device supported");
#if DT_HAS_COMPAT_STATUS_OKAY(nxp_lpcip3511)
#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT nxp_lpcip3511
#elif DT_HAS_COMPAT_STATUS_OKAY(nxp_ehci)
#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT nxp_ehci
#endif

/* Number of endpoints supported */
#define USB_DEVICE_CONFIG_ENDPOINTS (DT_INST_PROP(0, num_bidir_endpoints))

/* Start of Frame (SOF) Notifications are required by the zephyr usb audio driver */
#ifdef CONFIG_USB_DEVICE_AUDIO
#define USB_DEVICE_CONFIG_SOF_NOTIFICATIONS (1U)
#endif /* CONFIG_USB_DEVICE_AUDIO */

#endif /* __USB_DEVICE_CONFIG_H__ */
