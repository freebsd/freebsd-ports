--- medcut.c.orig	2013-08-09 11:59:28 UTC
+++ medcut.c
@@ -40,10 +40,8 @@
 int NCells;
 struct color_rec *Tptr;
 
-
 void
-InitMinMax(boxnum)
-int boxnum;
+InitMinMax(int boxnum)
 {
     C_boxes[boxnum].min_pix[RED] = 256;
     C_boxes[boxnum].max_pix[RED] = 0;
@@ -55,8 +53,7 @@
 
 
 struct color_rec *
-AddHash(red, green, blue)
-int red, green, blue;
+AddHash(int red, int green, int blue)
 {
     int lum;
 
@@ -78,9 +75,7 @@
 
 
 void
-AddColor(cptr, boxnum)
-struct color_rec *cptr;
-int boxnum;
+AddColor(struct color_rec *cptr, int boxnum)
 {
     struct color_rec *ptr;
 
@@ -107,9 +102,7 @@
 
 
 void
-CountColors(data, colrs)
-unsigned char *data;
-struct colr_data *colrs;
+CountColors(unsigned char *data, struct colr_data *colrs)
 {
     unsigned char *dptr;
     register int i, j;
@@ -142,8 +135,7 @@
 
 
 int
-FindTarget(tptr)
-int *tptr;
+FindTarget(int *tptr)
 {
     int range, i, indx;
 
@@ -175,8 +167,7 @@
 
 
 void
-SplitBox(boxnum, color_indx)
-int boxnum, color_indx;
+SplitBox(int boxnum,int color_indx)
 {
     struct color_rec *low, *high;
     struct color_rec *data;
@@ -245,8 +236,7 @@
 
 
 void
-SplitColors(e_cnt)
-int e_cnt;
+SplitColors(int e_cnt)
 {
     if (ColorCnt < e_cnt) {
 	int i;
@@ -279,8 +269,7 @@
  * Colors passed in 0-65535, internally are 0-255
  */
 void
-ConvertColor(rp, gp, bp)
-int *rp, *gp, *bp;
+ConvertColor(int *rp, int *gp, int *bp)
 {
     struct color_rec *cptr;
     register struct color_rec *hash_ptr;
@@ -321,9 +310,7 @@
 
 
 void
-ConvertData(data, colrs)
-unsigned char *data;
-struct colr_data *colrs;
+ConvertData( unsigned char *data, struct colr_data *colrs)
 {
     unsigned char *dptr;
     register int i, j;
@@ -349,9 +336,7 @@
 
 
 void
-PrintColormap(e_cnt, colrs)
-int e_cnt;
-struct colr_data *colrs;
+PrintColormap( int e_cnt, struct colr_data *colrs)
 {
     int i;
 
@@ -382,11 +367,7 @@
 
 
 void
-MedianCut(data, w, h, colrs, start_cnt, end_cnt)
-unsigned char *data;
-int *w, *h;
-struct colr_data *colrs;
-int start_cnt, end_cnt;
+MedianCut(unsigned char *data, int *w, int *h, struct colr_data *colrs, int start_cnt, int end_cnt)
 {
     int i;
 
@@ -440,10 +421,7 @@
  * 0-255.
  */
 void
-MedianCount(data, w, h, colrs)
-unsigned char *data;
-int w, h;
-struct colr_data *colrs;
+MedianCount( unsigned char *data, int w, int h, struct colr_data *colrs)
 {
     unsigned char *dptr;
     register int i, j;
@@ -472,8 +450,7 @@
 
 
 void
-MedianSplit(end_cnt)
-int end_cnt;
+MedianSplit(int end_cnt)
 {
     C_boxes[0].count = ColorCnt;
     SplitColors(end_cnt);
@@ -481,10 +458,7 @@
 
 
 void
-MedianConvert(data, w, h, colrs)
-unsigned char *data;
-int w, h;
-struct colr_data *colrs;
+MedianConvert(unsigned char *data, int w, int h, struct colr_data *colrs)
 {
     Width = w;
     Height = h;
@@ -493,9 +467,7 @@
 
 
 void
-MedianMerge(colrs, end_cnt)
-struct colr_data *colrs;
-int end_cnt;
+MedianMerge(struct colr_data *colrs, int end_cnt)
 {
     int i;
 
