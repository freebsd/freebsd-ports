--- extconf.rb.orig	Wed Nov 17 20:56:22 2004
+++ extconf.rb	Mon May 30 21:50:18 2005
@@ -32,13 +32,16 @@
 end
 
 
-if /linux/ =~ RUBY_PLATFORM  or /i386-freebsd/ =~ RUBY_PLATFORM
-    CONFIG['CC'] = `wx-config --cxx`
-    CONFIG['LDSHARED'].gsub!("gcc",`wx-config --cxx`.strip)
-    $CFLAGS += " `wx-config --cxxflags`"
-    $LDFLAGS += " `wx-config --libs` -Wl,--version-script,./version-script "
+if /linux/ =~ RUBY_PLATFORM  or /freebsd/ =~ RUBY_PLATFORM
+    CONFIG['CC'] = `wxgtk2-2.4-config --cxx`
+    CONFIG['LDSHARED'].gsub!("gcc",`wxgtk2-2.4-config --cxx`.strip)
+    $CFLAGS += " `wxgtk2-2.4-config --cxxflags`"
+    $LDFLAGS += " `wxgtk2-2.4-config --libs` -Wl,--version-script,./version-script "
     ["htmlprocessor.o", "htmlwindow.o", "htmleasyprinting.o"].each do |str|
         $objs.delete(str)
+    end
+    if ($use_xrc)
+        $LDFLAGS += " -lwx_gtk2_xrc-2.4 "
     end
 
 elsif /mingw32/ =~ RUBY_PLATFORM
