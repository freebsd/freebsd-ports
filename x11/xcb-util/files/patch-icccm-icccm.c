--- icccm/icccm.c.orig	2009-08-24 11:47:36.000000000 +0300
+++ icccm/icccm.c	2009-10-21 21:01:52.000000000 +0300
@@ -627,15 +627,13 @@
 xcb_get_wm_hints_from_reply(xcb_wm_hints_t *hints,
                             xcb_get_property_reply_t *reply)
 {
-  if(!reply)
+  if(!reply || reply->type != WM_HINTS || reply->format != 32)
     return 0;
 
   int length = xcb_get_property_value_length(reply);
   int num_elem = length / (reply->format / 8);
 
-  if (reply->type != WM_HINTS
-      || reply->format != 32
-      || num_elem < XCB_NUM_WM_HINTS_ELEMENTS - 1)
+  if(num_elem < XCB_NUM_WM_HINTS_ELEMENTS - 1)
     return 0;
 
   memcpy(hints, (xcb_size_hints_t *) xcb_get_property_value(reply), length);
