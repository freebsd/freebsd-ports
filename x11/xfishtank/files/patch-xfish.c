--- xfish.c.orig	1992-12-17 21:26:17 UTC
+++ xfish.c
@@ -11,6 +11,8 @@
 
   *	Ported to monocrome by Jonathan Greenblatt (jonnyg@rover.umd.edu)
 
+  *     05/02/1996 Added TrueColor support by TJ Phan (phan@aur.alcatel.com)
+
   TODO:
 
 	Parameter parsing needs to be redone.
@@ -46,13 +48,24 @@
 
 /* constants are based on rand(3C) returning an integer between 0 and 32767 */
 
-#if defined(ultrix) || defined(sun) || defined(linux)
+#if defined(ultrix) || defined(sun)
 #define  RAND_I_1_16   134217728
 #define  RAND_F_1_8    268435455.875
 #define  RAND_I_1_4    536870911
 #define  RAND_I_1_2   1073741823
 #define  RAND_I_3_4   1610612735
 #define  RAND_F_MAX   2147483647.0
+#else     
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <stdlib.h>
+#include <unistd.h>
+
+#define  RAND_I_1_16   (RAND_MAX>>4)
+#define  RAND_F_1_8    ((float)(RAND_MAX>>3))
+#define  RAND_I_1_4    (RAND_MAX>>2)
+#define  RAND_I_1_2    (RAND_MAX>>1)
+#define  RAND_I_3_4    ((RAND_MAX>>2)*3)
+#define  RAND_F_MAX    ((float)RAND_MAX)
 #else
 #define  RAND_I_1_16   2048
 #define  RAND_F_1_8    4096.0
@@ -61,8 +74,8 @@
 #define  RAND_I_3_4   24575
 #define  RAND_F_MAX   32767.0
 #endif
+#endif
 
-
 extern unsigned char *ReadBitmap();
 
 
@@ -850,6 +863,10 @@ putbubble(b, s, c)
  * Find the closest color by allocating it, or picking an already allocated
  * color
  */
+Visual (*visual_info) = NULL;
+int r_mask, g_mask, b_mask;
+int r_shift=0, g_shift=0, b_shift=0;
+int r_bits=0, g_bits=0, b_bits=0;
 void
 FindColor(Dpy, colormap, colr)
 	Display *Dpy;
@@ -862,6 +879,58 @@ FindColor(Dpy, colormap, colr)
 	XColor def_colrs[256];
 	int NumCells;
 
+	if( visual_info == NULL &&  DefaultDepth(Dpy, DefaultScreen(Dpy)) >= 16 )
+	{
+	   visual_info = DefaultVisual(Dpy, DefaultScreen(Dpy));
+	   r_mask = visual_info->red_mask;
+	   while( !(r_mask & 1) )
+	   {
+	      r_mask >>= 1;
+	      r_shift++;
+	   }
+	   while( r_mask & 1 )
+	   {
+	      r_mask >>= 1;
+	      r_bits++;
+	   }
+
+	   g_mask = visual_info->green_mask;
+	   while( !(g_mask & 1) )
+	   {
+	      g_mask >>= 1;
+	      g_shift++;
+	   }
+	   while( g_mask & 1 )
+	   {
+	      g_mask >>= 1;
+	      g_bits++;
+	   }
+
+	   b_mask = visual_info->blue_mask;
+	   while( !(b_mask &1) )
+	   {
+	      b_mask >>= 1;
+	      b_shift++;
+	   }
+	   while( b_mask & 1 )
+	   {
+	      b_mask >>= 1;
+	      b_bits++;
+	   }
+	}
+
+	if( DefaultDepth(Dpy, DefaultScreen(Dpy)) > 8 )
+	{
+	   colr->red >>= 16 - r_bits;
+	   colr->green >>= 16 - g_bits;
+	   colr->blue >>= 16 - b_bits;
+
+	   colr->pixel = ((colr->red << r_shift) & visual_info->red_mask) |
+	      ((colr->green << g_shift) & visual_info->green_mask) |
+	      ((colr->blue << b_shift) & visual_info->blue_mask);
+	   return;
+	}
+
 	if (AllocCnt < climit)
 	{
 		match = XAllocColor(Dpy, colormap, colr);
@@ -982,7 +1051,6 @@ init_colormap()
 	XColor hdef, edef;
 	struct colr_data *cdp;
 	struct colr_data colrs[256];
-	extern char *malloc();
 
 	colormap = XDefaultColormap(Dpy, screen);
 
@@ -1151,6 +1219,7 @@ MakeImage(data, width, height)
 		fprintf(stderr, "Don't know how to format image for display of depth %d\n", depth);
 		exit(1);
 	}
+
 	if (BitmapBitOrder(Dpy) == LSBFirst)
 	{
 		shiftstart = 0;
@@ -1194,7 +1263,8 @@ MakeImage(data, width, height)
 			}
 		}
 	}
-	bytesperline = (width + linepad) * depth / 8;
+
+	bytesperline = (width  * depth / 8 + linepad);
 	newimage = XCreateImage(Dpy, DefaultVisual(Dpy, screen), depth,
 		ZPixmap, 0, (char *)bit_data,
 		(width + linepad), height, 8, bytesperline);
@@ -1218,7 +1288,6 @@ init_pixmap()
 	unsigned char *data;
 	register int i, j, k;
 	int cnt, wcnt;
-	extern char *malloc();
 
 	cnt = 1;
 	cnt += Pcnt;
@@ -1341,9 +1410,14 @@ init_pixmap()
 		free((char *)data);
 	}
 
+	if( DisplayPlanes(Dpy, screen) < 8 )
+	{
+
 		j = rwidth[k] * rheight[k];
 		x1A = (caddrt) malloc(rwidth[k] * rheight[k]);
 		p = (caddrt) xfishRasterA[k];
+
+
 		q = x1A;
 		for (i = 0; i < j; i++)
 		{
@@ -1389,8 +1463,69 @@ init_pixmap()
 		xfishB[k][2] = MakeImage(x1B, rwidth[k], rheight[k]);
 		xfishB[k][1] = MakeImage(x2B, rwidth[k], rheight[k]);
 
+		free((char *)x1A);
+		free((char *)x2A);
+		free((char *)x1B);
+		free((char *)x2B);
+
+	}
+	else
+	{
 		i = DisplayPlanes(Dpy, screen);
 
+		xfishA[k][2] = XGetImage(Dpy, DefaultRootWindow(Dpy), 0, 0, rwidth[k], rheight[k], 0, ZPixmap);
+
+		p = (caddrt) xfishRasterA[k];
+
+		for (j = 0; j < rheight[k]; j++)
+		{
+		   for( i = 0; i < rwidth[k]; i++ )
+		   {
+		      XPutPixel(xfishA[k][2], i, j, cmap[cnt + (int)(*p)]);
+		      p++;
+		   }
+		}
+
+		xfishB[k][2] = XGetImage(Dpy, DefaultRootWindow(Dpy), 0, 0, rwidth[k], rheight[k], 0, ZPixmap);
+
+		p = (caddrt) xfishRasterB[k];
+
+		for (j = 0; j < rheight[k]; j++)
+		{
+		   for( i = 0; i < rwidth[k]; i++ )
+		   {
+		      XPutPixel(xfishB[k][2], i, j, cmap[cnt + (int)(*p)]);
+		      p++;
+		   }
+		}
+
+		xfishA[k][1] = XGetImage(Dpy, DefaultRootWindow(Dpy), 0, 0, rwidth[k], rheight[k], 0, ZPixmap);
+
+		for (j = 0; j < rheight[k]; j++)
+		{
+		   for( i = 0; i < rwidth[k]; i++ )
+		   {
+		      XPutPixel(xfishA[k][1], i, j,
+				XGetPixel(xfishA[k][2], rwidth[k] - i -1, j));
+		   }
+		}
+
+		xfishB[k][1] = XGetImage(Dpy, DefaultRootWindow(Dpy), 0, 0, rwidth[k], rheight[k], 0, ZPixmap);
+
+		for (j = 0; j < rheight[k]; j++)
+		{
+		   for( i = 0; i < rwidth[k]; i++ )
+		   {
+		      XPutPixel(xfishB[k][1], i, j,
+				XGetPixel(xfishB[k][2], rwidth[k] - i - 1, j));
+		   }
+		}
+
+	}
+
+
+		i = DisplayPlanes(Dpy, screen);
+
 		pfishA[k][1] = XCreatePixmap(Dpy, wid,
 			rwidth[k], rheight[k], i);
 		pfishA[k][2] = XCreatePixmap(Dpy, wid,
@@ -1400,11 +1535,6 @@ init_pixmap()
 		pfishB[k][2] = XCreatePixmap(Dpy, wid,
 			rwidth[k], rheight[k], i);
 
-		free((char *)x1A);
-		free((char *)x2A);
-		free((char *)x1B);
-		free((char *)x2B);
-
 		if (pfishA[k][1])
 		{
 			XPutImage(Dpy, pfishA[k][1], gc, xfishA[k][1], 0, 0,
@@ -1465,34 +1595,6 @@ Initialize signal so that SIGUSR1 causes secure mode t
 void 
 init_signals()
 {
-	int ret;
-#ifdef linux
-	signal(SIGUSR1, toggle_secure);
-#else			
-#if defined(MOTOROLA) || defined(SCO)
-    sigset(SIGUSR1, toggle_secure);
-#else
-    struct sigvec vec;
-
-    vec.sv_handler = toggle_secure;
-    vec.sv_mask = 0;
-    vec.sv_onstack = 0;
-
-#ifndef hpux
-    ret = sigvec(SIGUSR1, &vec, &vec);
-	if (ret != 0)
-	{
-		fprintf(stderr, "sigvec call failed\n");
-	}
-	else
-	{
-		fprintf(stderr, "sigvec call OK\n");
-	}
-#else
-    sigvector(SIGUSR1, &vec, &vec);
-#endif
-#endif /* MOTOROLA */
-#endif /* LINUX */
 }
 
 
@@ -1505,7 +1607,6 @@ initialize()
     XWindowAttributes winfo;
     XSetWindowAttributes attr;
     XGCValues   vals;
-    extern char *malloc();
     XSizeHints  xsh;
     XImage *pimage;
     int i, size, cnt;
@@ -1613,13 +1714,12 @@ if ((!DoClipping)||(picname[0] != '\0'))
     xsh.height = height;
     XSetNormalHints(Dpy, wid, &xsh);
 
+    XMapWindow(Dpy, wid);
     if (picname[0] != '\0')
     {
 	XPutImage(Dpy, PicMap, gc, pimage, 0, 0, 0, 0, Pwidth, Pheight);
 	XSetWindowBackgroundPixmap(Dpy, wid, PicMap);
     }
-
-    XMapWindow(Dpy, wid);
 }
 
     binfo = (bubble *) malloc(blimit * sizeof(bubble));
@@ -1965,9 +2065,15 @@ void 
 high_res_sleep(seconds)
     double      seconds;
 {
+#ifndef __FreeBSD__
     int         fds = 0;
+#endif
     struct timeval timeout;
-
+#ifdef __FreeBSD__
+    fd_set fds;
+    FD_ZERO(&fds);
+#endif    
+    
     timeout.tv_sec = seconds;
     timeout.tv_usec = (seconds - timeout.tv_sec) * 1000000.0;
     select(0, &fds, &fds, &fds, &timeout);
