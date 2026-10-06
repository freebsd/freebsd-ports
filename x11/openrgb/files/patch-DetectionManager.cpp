Revert upstream commit 248668ea

FreeBSD's hidapi always report 0 for usage_page and usage.

--- DetectionManager.cpp.orig	2026-10-05 10:37:33 UTC
+++ DetectionManager.cpp
@@ -109,10 +109,12 @@ bool BasicHIDBlock::compare(hid_device_info* info)
          || (vid == info->vendor_id))
         && ((pid        == HID_PID_ANY)
          || (pid == info->product_id))
+#if !defined(__FreeBSD__)
         && ((usage_page == HID_USAGE_PAGE_ANY)
          || (usage_page == info->usage_page))
         && ((usage      == HID_USAGE_ANY)
          || (usage      == info->usage))
+#endif
         && ((interface  == HID_INTERFACE_ANY)
          || (interface  == info->interface_number))
         && ((bus        == HID_BUS_ANY)
