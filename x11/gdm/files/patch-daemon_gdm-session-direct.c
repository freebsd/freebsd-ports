--- daemon/gdm-session-direct.c.orig	2009-12-02 15:15:33.000000000 +0100
+++ daemon/gdm-session-direct.c	2009-12-02 15:15:41.000000000 +0100
@@ -608,6 +608,7 @@
     char **devices;
     int n_devices;
     char *layout;
+    char *variant;
     char *result;
 
     result = NULL;
@@ -635,8 +636,26 @@
                                                         "input.xkb.layout",
                                                         NULL);
         }
-	result = g_strdup (layout);
+
+	variant = libhal_device_get_property_string (ctx,
+						     devices[0],
+						     "input.x11_options.XkbVariant",
+						     NULL);
+
+	if (!variant) {
+		variant = libhal_device_get_property_string (ctx,
+							     devices[0],
+							     "input.xkb.variant",
+							     NULL);
+	}
+
+	if(layout && variant)
+		result = g_strdup_printf("%s\t%s", layout, variant);
+	else
+		result = g_strdup (layout);
+
 	libhal_free_string (layout);
+	libhal_free_string (variant);
     }
 
     libhal_free_string_array (devices);


