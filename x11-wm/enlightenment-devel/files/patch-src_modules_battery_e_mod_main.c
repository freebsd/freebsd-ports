--- src/modules/battery/e_mod_main.c.orig	Sat Nov  5 11:39:55 2005
+++ src/modules/battery/e_mod_main.c	Sat Nov  5 12:29:02 2005
@@ -687,9 +687,11 @@
       case CHECK_ACPI:
 	ret = _battery_bsd_acpi_check(ef);
 	break;
+# ifdef __i386__
       case CHECK_APM:
 	ret = _battery_bsd_apm_check(ef);
 	break;
+#endif
       default:
 	break;
      }
@@ -1433,6 +1435,7 @@
    return stat;
 }
 
+# ifdef __i386__
 static Status *
 _battery_bsd_apm_check(Battery *ef)
 {
@@ -1525,6 +1528,7 @@
    
    return stat;
 }
+#endif
 #endif
 
 #ifdef HAVE_CFBASE_H
