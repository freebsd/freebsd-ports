--- xzoom.c.orig	Wed May 29 18:40:51 1996
+++ xzoom.c	Sat Jan 15 00:00:00 2000
@@ -12,13 +12,20 @@
    exact location where the source code can be obtained.
 
 Changelist:
-Author			Description
-------			-----------
-Itai Nahshon	Version 0.1, Nov. 21 1995
-Itai Nahshon    Version 0.2, Apr. 17 1996
-		include <sys/types.h>
-		Use memmove() instead of memcopy()
-		Optional macro to replace call to usleep().
+Author                    Description
+------                    -----------
+Itai Nahshon              Version 0.1, Nov. 21 1995
+Itai Nahshon              Version 0.2, Apr. 17 1996
+                          include <sys/types.h>
+                          Use memmove() instead of memcopy()
+                          Optional macro to replace call to usleep().
+Markus F.X.J. Oberhumer   Version 0.4, Feb. 18 1998
+                          split into 2 files (scale.h)
+                          added support for 15, 16, 24 and 32 bpp displays
+                          added a grid (press key 'g')
+                          optimized scaling routines
+                          use memcpy() instead of memmove() ;-)
+                          some other minor changes/fixes
 */
 
 #include <stdio.h>
@@ -87,8 +94,12 @@
 int xzoom_flag = False;			/* next mag change only to magx */
 int yzoom_flag = False;			/* next mag change only to magy */
 
+int gridx = False;
+int gridy = False;
+
 int width[2] = { 0, WIDTH };
 int height[2] = { 0, HEIGHT };
+unsigned depth = 0;
 
 #ifdef XSHM
 XShmSegmentInfo shminfo[2];			/* Segment info.  */
@@ -106,6 +117,7 @@
 void
 timeout_func(int signum) {
 	set_title = True;
+	signum = signum;          /* UNUSED */
 }
 
 #ifdef FRAME
@@ -116,9 +128,6 @@
 void
 allocate_images(void) {
 	int i;
-#ifndef XSHM
-	char *data;
-#endif
 
 	for(i = 0; i < 2; i++) {
 
@@ -137,7 +146,7 @@
 		shminfo[i].shmid = shmget(IPC_PRIVATE,
 			(unsigned int)(ximage[i]->bytes_per_line * ximage[i]->height),
 			IPC_CREAT | 0777);
-		
+
 		if(shminfo[i].shmid < 0) {
 			perror("shmget");
 			exit(-1);
@@ -163,20 +172,21 @@
 
 		shmctl(shminfo[i].shmid, IPC_RMID, 0);
 #else
-		data = malloc(width[i] * height[i]);
+		char *data;
+		data = malloc(BitmapUnit(dpy) / 8 * width[i] * height[i]);
 
 		ximage[i] = XCreateImage(dpy,
 			DefaultVisualOfScreen(scr),
 			DefaultDepthOfScreen(scr),
 			ZPixmap, 0, data,
-			width[i], height[i], 8, width[i]);
+			width[i], height[i], 32, 0);
 
 		if(ximage[i] == NULL) {
 			perror("XCreateImage");
 			exit(-1);
 		}
 
-#endif XSHM
+#endif /* XSHM */
 	}
 	created_images = True;
 }
@@ -185,6 +195,9 @@
 destroy_images(void) {
 	int i;
 
+	if (!created_images)
+		return;
+
 	for(i = 0; i < 2; i++) {
 #ifdef XSHM
 		XShmDetach(dpy, &shminfo[i]);	/* ask X11 to detach shared segment */
@@ -195,6 +208,8 @@
 		ximage[i]->data = NULL;			/* remove refrence to that address */
 		XDestroyImage(ximage[i]);		/* and destroy image */
 	}
+
+	created_images = False;
 }
 
 void
@@ -230,8 +245,7 @@
 void
 resize(int new_width, int new_height) {
 
-	if(created_images)
-		destroy_images();		/* we can get rid of these */
+	destroy_images();		/* we can get rid of these */
 
 	/* find new dimensions for source */
 
@@ -244,9 +258,13 @@
 		height[SRC] = (new_height+magy-1) / magy;
 	}
 
+	if(width[SRC] < 1)
+		width[SRC] = 1;
 	if(width[SRC] > WidthOfScreen(scr))
 		width[SRC] = WidthOfScreen(scr);
 
+	if(height[SRC] < 1)
+		height[SRC] = 1;
 	if(height[SRC] > HeightOfScreen(scr))
 		height[SRC] = HeightOfScreen(scr);
 
@@ -270,12 +288,34 @@
 		height[DST] = new_height;
 }
 
+
+void scale8(void)
+{
+#define T unsigned char
+#include "scale.h"
+#undef T
+}
+
+
+void scale16(void)
+{
+#define T unsigned short
+#include "scale.h"
+#undef T
+}
+
+
+void scale32(void)
+{
+#define T unsigned int
+#include "scale.h"
+#undef T
+}
+
+
 int
 main(int argc, char **argv) {
 	XSetWindowAttributes xswa;
-	int i, j, k;
-	char c;
-	char *p1, *p2;
 	XEvent event;
 	int buttonpressed = False;
 	int unmapped = True;
@@ -286,8 +326,9 @@
 	int source_geom_mask = NoValue,
 	    dest_geom_mask = NoValue,
 	    copy_from_src_mask;
-	int xpos = 0, ypos = 0; 
+	int xpos = 0, ypos = 0;
 
+	atexit(destroy_images);
 	progname = strrchr(argv[0], '/');
 	if(progname)
 		++progname;
@@ -312,7 +353,7 @@
 
 			if(magx <= 0)
 				Usage();
-			
+
 
 			magy = argc > 1 ? atoi(argv[1]) : -1;
 
@@ -340,7 +381,7 @@
 			flipxy = True;
 			continue;
 		}
-		
+
 		if(!strcmp(argv[0], "-source")) {
 			++argv; --argc;
 
@@ -438,23 +479,24 @@
 
 	scr = DefaultScreenOfDisplay(dpy);
 
-	if(DefaultDepthOfScreen(scr) != 8) {
-		fprintf(stderr, "%s: can work only with 8 bits/pixel\n", progname);
+	depth = DefaultDepthOfScreen(scr);
+	if (depth < 8) {
+		fprintf(stderr, "%s: need at least 8 bits/pixel\n", progname);
 		exit(1);
 	}
 
 	if(source_geom_mask & XNegative)
 		xgrab += WidthOfScreen(scr);
-	
+
 	if(source_geom_mask & YNegative)
 		ygrab += HeightOfScreen(scr);
 
 	if(dest_geom_mask & XNegative)
 		xpos += WidthOfScreen(scr);
-	
+
 	if(source_geom_mask & YNegative)
 		ypos += HeightOfScreen(scr);
-	
+
 	/* printf("=%dx%d+%d+%d\n", width[DST], height[DST], xpos, ypos); */
 
 	xswa.event_mask = ButtonPressMask|ButtonReleaseMask|ButtonMotionMask;
@@ -463,17 +505,17 @@
 	xswa.background_pixel = BlackPixelOfScreen(scr);
 
 	win = XCreateWindow(dpy, RootWindowOfScreen(scr),
-	    xpos, ypos, width[DST], height[DST], 0, 
+	    xpos, ypos, width[DST], height[DST], 0,
 	    DefaultDepthOfScreen(scr), InputOutput,
 	    DefaultVisualOfScreen(scr),
 	    CWEventMask | CWBackPixel, &xswa);
 
-	XChangeProperty(dpy, win, XA_WM_ICON_NAME, XA_STRING, 8, 
+	XChangeProperty(dpy, win, XA_WM_ICON_NAME, XA_STRING, 8,
 			PropModeReplace,
 			(unsigned char *)progname, strlen(progname));
 
 	/*
-	XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8, 
+	XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8,
 			PropModeReplace,
 			(unsigned char *)progname, strlen(progname));
 	*/
@@ -512,7 +554,7 @@
 	{
 		static char bitmap_data[] = { 0 };
 		static XColor col = { 0 };
-		Pixmap curs = XCreatePixmapFromBitmapData(dpy, 
+		Pixmap curs = XCreatePixmapFromBitmapData(dpy,
 			RootWindowOfScreen(scr), bitmap_data, 1, 1, 0, 0, 1);
 
 		when_button = XCreatePixmapCursor(dpy, curs, curs, &col, &col, 0, 0);
@@ -567,6 +609,7 @@
 
 				case '+':
 				case '=':
+				case XK_KP_Add:
 					if(!yzoom_flag) ++magx;
 					if(!xzoom_flag) ++magy;
 					xzoom_flag = yzoom_flag = False;
@@ -575,6 +618,7 @@
 					break;
 
 				case '-':
+				case XK_KP_Subtract:
 					if(!yzoom_flag) --magx;
 					if(!xzoom_flag) --magy;
 					xzoom_flag = yzoom_flag = False;
@@ -585,6 +629,7 @@
 					break;
 
 				case XK_Left:
+				case XK_KP_Left:
 					if(flipxy)
 						if(flipx)
 							ygrab += scroll;
@@ -598,6 +643,7 @@
 					break;
 
 				case XK_Right:
+				case XK_KP_Right:
 					if(flipxy)
 						if(flipx)
 							ygrab -= scroll;
@@ -611,6 +657,7 @@
 					break;
 
 				case XK_Up:
+				case XK_KP_Up:
 					if(flipxy)
 						if(flipy)
 							xgrab -= scroll;
@@ -624,6 +671,7 @@
 					break;
 
 				case XK_Down:
+				case XK_KP_Down:
 					if(flipxy)
 						if(flipy)
 							xgrab += scroll;
@@ -666,12 +714,17 @@
 					xzoom_flag = False;
 					break;
 
+				case 'g':
+					gridx = !gridx;
+					gridy = !gridy;
+					break;
+
 				case 'd':
 					if(++delay_index >= NDELAYS)
 						delay_index = 0;
 					delay = delays[delay_index];
 					sprintf(title, "delay = %d ms", delay/1000);
-					XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8, 
+					XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8,
 						PropModeReplace,
 						(unsigned char *)title, strlen(title));
 					signal(SIGALRM, timeout_func);
@@ -717,6 +770,7 @@
 #endif
 				}
 				break;
+
 			}
 
 			/* trying XShmGetImage when part of the rect is
@@ -736,6 +790,7 @@
 
 			if(ygrab > HeightOfScreen(scr)-height[SRC])
 				ygrab = HeightOfScreen(scr)-height[SRC];
+
 		}
 
 #ifdef XSHM
@@ -753,63 +808,12 @@
 		}
 #endif
 
-		/* copy scaled lines from src to dst */
-		for(j = flipxy?width[SRC]:height[SRC]; --j >= 0; ) {
-			/* p1 point to begining of scanline j*magy in DST */
-			p1 = &ximage[DST]->data[ximage[DST]->xoffset +
-					j*magy*ximage[DST]->bytes_per_line ];
-			/* p2 point to begining of scanline j in SRC */
-			/* if flipy then line height[SRC]-1-j */
-			p2 = &ximage[SRC]->data[ximage[SRC]->xoffset +
-					(flipy?(height[SRC]-1-j):j)*ximage[SRC]->bytes_per_line ];
-
-			if(flipxy) {
-				int p2step = ximage[SRC]->bytes_per_line;
-				p2 = &ximage[SRC]->data[ximage[SRC]->xoffset + (flipy?j:(width[SRC]-1-j))];
-
-				if(flipx) {
-					p2 += p2step * (height[SRC]-1);
-					p2step = -p2step;
-				}
-
-				for(i = height[SRC]; --i >= 0;) {
-					c = *p1++ = *p2;
-					p2 += p2step;
-					for(k = magx; --k > 0; )
-						*p1++ = c;
-				}	
-			}
-			else if(flipx) {
-				p2 += width[SRC];
-				for(i = width[SRC]; --i >= 0;) {
-					c = *p1++ = *--p2;
-					for(k = magx; --k > 0; )
-						*p1++ = c;
-				}	
-			}
-			else {
-				for(i = width[SRC]; --i >= 0;) {
-					c = *p1++ = *p2++;
-					for(k = magx; --k > 0; )
-						*p1++ = c;
-				}	
-			}
-
-			/* p1 point to begining of scanline j*magy in DST */
-			p1 = &ximage[DST]->data[ximage[DST]->xoffset +
-										  j*magy*ximage[DST]->bytes_per_line ];
-			/* p2 points to begining of next line */
-			p2 = p1 + ximage[DST]->bytes_per_line;
-			/* duplicate that line as needed */
-			for(k = magy; --k > 0; ) {
-#ifdef BCOPY
-				bcopy(p1, p2, width[DST]);
-#else
-				memmove(p2, p1, width[DST]);
-#endif
-				p2 += ximage[DST]->bytes_per_line;
-			}
-		}
+		if (depth == 8)
+			scale8();
+		else if (depth <= 8*sizeof(short))
+			scale16();
+		else if (depth <= 8*sizeof(int))
+			scale32();
 
 #ifdef XSHM
 		XShmPutImage(dpy, win, gc, ximage[DST], 0, 0, 0, 0, width[DST], height[DST], False);
@@ -825,7 +829,7 @@
 						flipx?"-":"", magx,
 						flipxy?" <=>":";",
 						flipy?"-":"", magy);
-			XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8, 
+			XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8,
 				PropModeReplace,
 				(unsigned char *)title, strlen(title));
 			set_title = False;
