--- statusbar.c
+++ statusbar.c
@@ -166,7 +166,7 @@ uicb_togglebar(Display *disp,
                const char *arg __attribute__ ((unused)))
 {
     if(awesomeconf->statusbar.position == BarOff)
-        awesomeconf->statusbar.position = (awesomeconf->statusbar.position == BarOff) ? BarTop : awesomeconf->statusbar_default_position;
+        awesomeconf->statusbar.position = (awesomeconf->statusbar_default_position == BarOff) ? BarTop : awesomeconf->statusbar_default_position;
     else
         awesomeconf->statusbar.position = BarOff;
     updatebarpos(disp, awesomeconf->statusbar);
