--- scale.h.orig	Sat Jan 15 14:23:58 2000
+++ scale.h	Sat Jan 15 00:00:00 2000
@@ -0,0 +1,102 @@
+/* scale image from SRC to DST - parameterized by type T */
+
+/* get pixel address of point (x,y) in image t */
+#define getP(t,x,y) \
+	(T *) (&ximage[t]->data[(ximage[t]->xoffset+(x))*sizeof(T) + \
+	                        (y)*ximage[t]->bytes_per_line])
+
+{
+	int i, j, k;
+
+	/* copy scaled lines from SRC to DST */
+	j = flipxy ? width[SRC] - 1 : height[SRC] - 1;
+	do {
+		T *p1;
+		T *p2;
+		int p2step;
+		T *p1_save;
+
+		/* p1 point to begining of scanline j*magy in DST */
+		p1 = getP(DST,0,j*magy);
+		p1_save = p1;
+		/* p2 point to begining of scanline j in SRC */
+		/* if flipy then line height[SRC]-1-j */
+		p2 = getP(SRC,0,flipy ? (height[SRC]-1-j) : j);
+
+		if (flipxy)
+		{
+			p2 = getP(SRC,flipy ? j : (width[SRC]-1-j),0);
+			p2step = ximage[SRC]->bytes_per_line / sizeof(T);
+
+			if (flipx)
+			{
+				p2 += p2step * (height[SRC]-1);
+				p2step = -p2step;
+			}
+
+			i = height[SRC];
+			do {
+				T c = *p2; p2 += p2step;
+				k = magx; do *p1++ = c; while (--k > 0);
+			} while (--i > 0);
+		}
+		else if (flipx)
+		{
+			p2 += width[SRC];
+			i = width[SRC];
+			do {
+				T c = *--p2;
+				k = magx; do *p1++ = c; while (--k > 0);
+			} while (--i > 0);
+		}
+		else
+		{
+			i = width[SRC];
+			do {
+				T c = *p2++;
+				k = magx; do *p1++ = c; while (--k > 0);
+			} while (--i > 0);
+		}
+
+		/* draw vertical grid */
+		if (gridy && magx >= 2)
+		{
+			p1 = p1_save - 1;
+			i = magx;
+			k = flipxy ? height[SRC] : width[SRC];
+			do {
+				p1 += i;
+				*p1 ^= ~((T)0);
+			} while (--k > 0);
+		}
+
+		/* duplicate that line as needed */
+		if (magy > 1)
+		{
+			/* p1 point to begining of scanline j*magy in DST */
+			p1 = p1_save;
+			/* p2 points to begining of next line */
+			p2 = p1;
+			p2step = ximage[DST]->bytes_per_line / sizeof(T);
+
+			i = width[DST] * sizeof(T);
+			k = magy - 1;
+			do {
+				p2 += p2step;
+				memcpy(p2, p1, i);
+			} while (--k > 0);
+
+			/* draw horizontal grid */
+			if (gridx && magy >= 2)
+			{
+				k = width[DST];
+				do {
+					*p2++ ^= ~((T)0);
+				} while (--k > 0);
+			}
+		}
+	} while (--j >= 0);
+}
+
+#undef getP
+
