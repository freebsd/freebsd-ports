--- src/locker/timedrevealer.cpp.orig	2026-08-02 19:12:39 UTC
+++ src/locker/timedrevealer.cpp
@@ -18,7 +18,7 @@ WayfireLockerTimedRevealer::WayfireLockerTimedRevealer
     auto hide_callback = [this] ()
     {
         Gtk::RevealerTransitionType type = Gtk::RevealerTransitionType::NONE;
-        switch (hide_animation)
+        switch (hide_animation.value())
         {
           case 1:
             type = Gtk::RevealerTransitionType::CROSSFADE;
