--- src/workspace.c.orig	Tue Jan  8 22:45:33 2002
+++ src/workspace.c	Thu Jan 22 01:47:49 2004
@@ -574,10 +574,12 @@ wWorkspaceForceChange(WScreen *scr, int 
                               &foo, &foo, &foo, &foo, &mask)) {
 		tmp = wWindowFor(win);
 	    }
-	    if (!tmp && wPreferences.focus_mode == WKF_SLOPPY) {
-		wSetFocusTo(scr, foc);
-	    } else {
-		wSetFocusTo(scr, tmp);
+	    if (!tmp) {                                                         
+		if (wPreferences.focus_mode == WKF_SLOPPY) {                    
+		    wSetFocusTo(scr, foc);                                      
+		} else {                                                        
+		    wSetFocusTo(scr, tmp);                                      
+		}                                                               
 	    }
 	}
     }
