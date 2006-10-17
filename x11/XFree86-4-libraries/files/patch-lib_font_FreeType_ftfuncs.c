--- lib/font/FreeType/ftfuncs.c.orig	Wed Apr 14 11:32:43 2004
+++ lib/font/FreeType/ftfuncs.c	Sun Aug 27 14:35:48 2006
@@ -50,10 +50,7 @@ THE SOFTWARE.
 #include FT_TYPE1_TABLES_H
 #include FT_XFREE86_H
 #include FT_BBOX_H
-#include FT_INTERNAL_TRUETYPE_TYPES_H
 #include FT_TRUETYPE_TAGS_H
-#include FT_INTERNAL_SFNT_H
-#include FT_INTERNAL_STREAM_H
 /*
  *  If you want to use FT_Outline_Get_CBox instead of 
  *  FT_Outline_Get_BBox, define here.
@@ -119,6 +116,46 @@ static char *xlfd_props[] = {
 };
 
 
+/* read 2-byte value from a SFNT table */
+static FT_UShort
+sfnt_get_ushort( FT_Face     face,
+                 FT_ULong    table_tag,
+                 FT_ULong    table_offset )
+{
+  FT_Byte    buff[2];
+  FT_ULong   len = sizeof(buff);
+  FT_UShort  result = 0;
+
+  if ( !FT_Load_Sfnt_Table( face, table_tag, table_offset, buff, &len ) );
+    result = (FT_UShort)( (buff[0] << 8) | buff[1] );
+
+  return result;
+}
+
+#define  sfnt_get_short(f,t,o)  ((FT_Short)sfnt_get_ushort((f),(t),(o)))
+
+
+#if 0
+static FT_ULong
+sfnt_get_ulong( FT_Face   face,
+                FT_ULong  table_tag,
+                FT_ULong  table_offset )
+{
+  FT_Byte    buff[4];
+  FT_ULong   len = sizeof(buff);
+  FT_UShort  result = 0;
+
+  if  ( !FT_Load_Sfnt_Table( face, table_tag, table_offset, buff, &len );
+    result = ((FT_ULong)buff[0] << 24) | ((FT_ULong)buff[1] << 16) |
+             ((FT_ULong)buff[2] << 8)  |  (FT_ULong)buff[3];
+
+  return result;
+}
+#endif
+
+
+
+
 static int ftypeInitP = 0;      /* is the engine initialised? */
 static FT_Library ftypeLibrary;
 
@@ -207,6 +244,10 @@ FreeTypeOpenFace(FTFacePtr *facep, char 
         if(maxp && maxp->maxContours == 0)
             face->bitmap = 1;
     }
+
+    face->num_hmetrics = (FT_UInt) sfnt_get_ushort( face->face,
+                                                    TTAG_hhea, 34 );
+
     /* Insert face in hashtable and return it */
     face->next = faceTable[bucket];
     faceTable[bucket] = face;
@@ -458,6 +499,29 @@ FreeTypeOpenInstance(FTInstancePtr *inst
     }
 
     if( FT_IS_SFNT( face->face ) ) {
+#if 1
+        FT_F26Dot6  tt_char_width, tt_char_height, tt_dim_x, tt_dim_y;
+        FT_UInt     nn;
+
+        instance->strike_index=0xFFFFU;
+
+	tt_char_width  = (int)(trans->scale*(1<<6) + 0.5);
+	tt_char_height = (int)(trans->scale*(1<<6) + 0.5);
+
+        tt_dim_x = ( ( tt_char_width  * trans->xres + (36+32*72) ) / 72 ) & -64;
+        tt_dim_y = ( ( tt_char_height * trans->yres + (36+32*72) ) / 72 ) & -64;
+
+        for ( nn = 0; nn < face->face->num_fixed_sizes; nn++ )
+        {
+          FT_Bitmap_Size*  sz = &face->face->available_sizes[nn];
+
+          if ( tt_dim_x == sz->x_ppem && tt_dim_y == sz->y_ppem )
+          {
+            instance->strike_index = nn;
+            break;
+          }
+        }
+#else
 	/* See Set_Char_Sizes() in ttdriver.c */
 	FT_Error err;
 	TT_Face tt_face;
@@ -482,6 +546,7 @@ FreeTypeOpenInstance(FTInstancePtr *inst
 	sfnt   = (SFNT_Service)tt_face->sfnt;
 	err = sfnt->set_sbit_strike(tt_face,tt_x_ppem,tt_y_ppem,&instance->strike_index);
 	if ( err ) instance->strike_index=0xFFFFU;
+#endif
     }
 
     /* maintain a linked list of instances */
@@ -799,31 +864,36 @@ ft_make_up_italic_bitmap( char *raster, 
  * parse the htmx field in TrueType font.
  */
 
-/* from src/truetype/ttgload.c */
 static void
-tt_get_metrics( TT_HoriHeader*  header,
+tt_get_metrics( FT_Face         face,
 		FT_UInt         idx,
+		FT_UInt         num_hmetrics,
 		FT_Short*       bearing,
 		FT_UShort*      advance )
-/*  Copyright 1996-2001, 2002 by                      */
-/*  David Turner, Robert Wilhelm, and Werner Lemberg. */
 {
-    TT_LongMetrics  longs_m;
-    FT_UShort       k = header->number_Of_HMetrics;
+   /* read the metrics directly from the horizontal header, we
+    * parse the SFNT table directly through the standard FreeType API.
+    * this works with any version of the library and doesn't need to
+    * peek at its internals. Maybe a bit less
+    */
+    FT_UInt    count = num_hmetrics;
 
-    if ( k == 0 ) {
-	*bearing = *advance = 0;
-	return;
+    if ( count == 0 )
+    {
+      *advance = 0;
+      *bearing = 0;
     }
+    else if ( idx < count )
+    {
+      FT_ULong  offset = idx*4;
 
-    if ( idx < (FT_UInt)k ) {
-	longs_m  = (TT_LongMetrics )header->long_metrics + idx;
-	*bearing = longs_m->bearing;
-	*advance = longs_m->advance;
+      *advance = sfnt_get_ushort( face, TTAG_hmtx, offset );
+      *bearing = sfnt_get_short ( face, TTAG_hmtx, offset+2 );
     }
-    else {
-	*bearing = ((TT_ShortMetrics*)header->short_metrics)[idx - k];
-	*advance = ((TT_LongMetrics )header->long_metrics)[k - 1].advance;
+    else
+    {
+      *advance = sfnt_get_ushort( face, TTAG_hmtx, (count-1)*4 );
+      *bearing = sfnt_get_short ( face, TTAG_hmtx, (count+idx)*2 );
     }
 }
 
@@ -831,6 +901,7 @@ static int                   
 ft_get_very_lazy_bbox( FT_UInt index,
 		       FT_Face face,
 		       FT_Size size,
+		       FT_UInt  num_hmetrics,
 		       double slant,
 		       FT_Matrix *matrix,
 		       FT_BBox *bbox,
@@ -838,14 +909,13 @@ ft_get_very_lazy_bbox( FT_UInt index,
 		       FT_Long *vertAdvance)
 {
     if ( FT_IS_SFNT( face ) ) {
-	TT_Face   ttface = (TT_Face)face;
 	FT_Size_Metrics *smetrics = &size->metrics;
 	FT_Short  leftBearing = 0;
 	FT_UShort advance = 0;
 	FT_Vector p0, p1, p2, p3;
 
 	/* horizontal */
-	tt_get_metrics(&ttface->horizontal, index,
+	tt_get_metrics( face, num_hmetrics, index,
 		       &leftBearing, &advance);
 
 #if 0
@@ -905,6 +975,27 @@ static FT_Error
 FT_Do_SBit_Metrics( FT_Face ft_face, FT_Size ft_size, FT_ULong strike_index,
 		    FT_UShort glyph_index, FT_Glyph_Metrics *metrics_return )
 {
+#if 1
+    if ( strike_index != 0xFFFFU && ft_face->available_sizes != 0)
+    {
+      FT_Error         error;
+      FT_Bitmap_Size*  sz = &ft_face->available_sizes[strike_index];
+
+      error = FT_Set_Pixel_Sizes( ft_face, sz->x_ppem/64, sz->y_ppem/64 );
+      if ( !error )
+      {
+        error = FT_Load_Glyph( ft_face, glyph_index, FT_LOAD_SBITS_ONLY );
+	if ( !error )
+        {
+          if ( metrics_return != NULL )
+            *metrics_return = ft_face->glyph->metrics;
+
+	  return 0;
+	}
+      }
+    }
+    return -1;
+#elif (FREETYPE_VERSION >= 2001008)
     SFNT_Service       sfnt;
     TT_Face            face;
     FT_Error           error;
@@ -968,6 +1059,7 @@ FT_Do_SBit_Metrics( FT_Face ft_face, FT_
 
   Exit:
       return error;
+#endif
 }
 
 int
@@ -1023,6 +1115,7 @@ FreeTypeRasteriseGlyph(unsigned idx, int
 	    if( bitmap_metrics == NULL ) {
 		if ( instance->ttcap.flags & TTCAP_IS_VERY_LAZY ) {
 		    if( ft_get_very_lazy_bbox( idx, face->face, instance->size, 
+		                               face->num_hmetrics,
 					       instance->ttcap.vl_slant,
 					       &instance->transformation.matrix,
 					       &bbox, &outline_hori_advance, 
@@ -1197,6 +1290,7 @@ FreeTypeRasteriseGlyph(unsigned idx, int
 	if( is_outline == 1 ){
 	    if( correct ){
 		if( ft_get_very_lazy_bbox( idx, face->face, instance->size, 
+		                           face->num_hmetrics,
 					   instance->ttcap.vl_slant,
 					   &instance->transformation.matrix,
 					   &bbox, &outline_hori_advance, 
