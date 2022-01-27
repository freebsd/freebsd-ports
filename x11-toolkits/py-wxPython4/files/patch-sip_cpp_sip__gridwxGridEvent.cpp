--- sip/cpp/sip_gridwxGridEvent.cpp.orig	2022-01-27 22:07:16 UTC
+++ sip/cpp/sip_gridwxGridEvent.cpp
@@ -32,8 +32,8 @@ class sipwxGridEvent : public  ::wxGridEvent (public)
      * this class.
      */
 protected:
-    int GetRow() SIP_OVERRIDE;
-    int GetCol() SIP_OVERRIDE;
+    int GetRow();
+    int GetCol();
      ::wxEvent* Clone() const SIP_OVERRIDE;
      ::wxEventCategory GetEventCategory() const SIP_OVERRIDE;
 
