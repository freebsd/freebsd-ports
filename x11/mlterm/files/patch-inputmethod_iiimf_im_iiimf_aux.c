--- inputmethod/iiimf/im_iiimf_aux.c.orig	2010-07-17 17:47:04.000000000 +0900
+++ inputmethod/iiimf/im_iiimf_aux.c	2010-07-17 17:49:47.000000000 +0900
@@ -1134,7 +1134,7 @@
 		return  NULL ;
 	}
 
-	return  ((x_window_t *)aux->iiimf->im.listener->self)->display ;
+	return  ((x_window_t *)aux->iiimf->im.listener->self)->disp->display ;
 }
 
 static Window
@@ -1458,7 +1458,7 @@
 		return  -1 ;
 	}
 
-	return  ((x_window_t *)aux->iiimf->im.listener->self)->screen ;
+	return  ((x_window_t *)aux->iiimf->im.listener->self)->disp->screen ;
 }
 
 static int
@@ -1491,7 +1491,7 @@
 	point->x = (x > SHRT_MAX) ? SHRT_MAX : x ;
 	point->y = (y > SHRT_MAX) ? SHRT_MAX : y ;
 
-	return  ((x_window_t *)aux->iiimf->im.listener->self)->screen ;
+	return  ((x_window_t *)aux->iiimf->im.listener->self)->disp->screen ;
 }
 
 static int
