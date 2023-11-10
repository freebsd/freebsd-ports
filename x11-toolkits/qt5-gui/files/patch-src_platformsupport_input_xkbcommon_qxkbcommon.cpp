--- src/platformsupport/input/xkbcommon/qxkbcommon.cpp.orig	2023-09-06 08:28:54 UTC
+++ src/platformsupport/input/xkbcommon/qxkbcommon.cpp
@@ -274,10 +274,6 @@ static constexpr const auto KeyTbl = qMakeArray(
         Xkb2Qt<XKB_KEY_dead_small_schwa,        Qt::Key_Dead_Small_Schwa>,
         Xkb2Qt<XKB_KEY_dead_capital_schwa,      Qt::Key_Dead_Capital_Schwa>,
         Xkb2Qt<XKB_KEY_dead_greek,              Qt::Key_Dead_Greek>,
-        Xkb2Qt<XKB_KEY_dead_lowline,            Qt::Key_Dead_Lowline>,
-        Xkb2Qt<XKB_KEY_dead_aboveverticalline,  Qt::Key_Dead_Aboveverticalline>,
-        Xkb2Qt<XKB_KEY_dead_belowverticalline,  Qt::Key_Dead_Belowverticalline>,
-        Xkb2Qt<XKB_KEY_dead_longsolidusoverlay, Qt::Key_Dead_Longsolidusoverlay>,
 
         // Special keys from X.org - This include multimedia keys,
         // wireless/bluetooth/uwb keys, special launcher keys, etc.
