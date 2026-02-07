--- ./src/js/jsBSD.cxx.orig	2014-07-21 15:11:30.000000000 +0200
+++ ./src/js/jsBSD.cxx	2014-07-21 15:11:30.000000000 +0200
@@ -99,6 +99,8 @@
   // on every read of a USB device
   int              cache_buttons ;
   float            cache_axes [ _JS_MAX_AXES ] ;
+  float            axes_minimum [ _JS_MAX_AXES ] ;
+  float            axes_maximum [ _JS_MAX_AXES ] ;
 };
 
 // Idents lower than USB_IDENT_OFFSET are for analog joysticks.
@@ -196,9 +198,12 @@
          case HUG_Z:
          case HUG_RZ:
          case HUG_SLIDER:
+         case HUG_DIAL:
            if (*num_axes < _JS_MAX_AXES)
            {
              os->axes_usage[*num_axes] = usage;
+             os->axes_minimum[*num_axes] = h.logical_minimum;
+             os->axes_maximum[*num_axes] = h.logical_maximum;
              (*num_axes)++;
            }
            break;
@@ -324,9 +329,6 @@
 
   for ( int i = 0 ; i < _JS_MAX_AXES ; i++ )
   {
-	// We really should get this from the HID, but that data seems
-	// to be quite unreliable for analog-to-USB converters. Punt for
-	// now.
     if ( os->axes_usage [ i ] == HUG_HAT_SWITCH )
     {
       max       [ i ] = 1.0f ;
@@ -335,9 +337,9 @@
     }
     else
     {
-      max       [ i ] = 255.0f ;
-      center    [ i ] = 127.0f ;
-      min       [ i ] = 0.0f ;
+      max       [ i ] = os->axes_maximum [ i ];
+      min       [ i ] = os->axes_minimum [ i ];
+      center    [ i ] = (max [ i ] + min [ i ]) / 2.0 ;
     }
     dead_band [ i ] = 0.0f ;
     saturate  [ i ] = 1.0f ;
