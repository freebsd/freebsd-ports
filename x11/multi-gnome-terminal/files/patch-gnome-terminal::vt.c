--- gnome-terminal/vt.c.orig	Sun Apr 20 23:49:06 2003
+++ gnome-terminal/vt.c	Sun Aug 22 20:20:23 2004
@@ -782,6 +782,7 @@
       vt_up(vt);    
       break;
     default:
+      ;
     }
 
 }
@@ -806,6 +807,7 @@
       vt_down(vt);
       break;
     default:
+      ;
     }
 }
 
@@ -870,6 +872,7 @@
 	}
       break; 
     default:
+      ; 
     }
 }
 
@@ -956,6 +959,7 @@
 	} 
       break;
     default:
+      ;
     }
     /*vt->cursorx = (vt->cursorx-1) & (~7);*/
 }
@@ -980,6 +984,7 @@
 	} 
      break; 
     default:
+     ; 
     } 
 }
 
@@ -2073,9 +2078,11 @@
 */	      
 	break;
 	default:
+	;
 	}
       break;
 	default:
+      ;
     } 
   /* do nothing!*/
 }
