--- src/kernel/qfontdatabase_x11.cpp	2004-03-04 17:53:01.000000000 +0100
+++ src/kernel/qfontdatabase_x11.cpp	2004-03-04 17:47:59.000000000 +0100
@@ -1508,6 +1516,24 @@
 	XftResult res;
 	XftPattern *result =
 	    XftFontMatch( QPaintDevice::x11AppDisplay(), fp->screen, pattern, &res );
+#ifdef QT_XFT2
+	if (script == QFont::Latin) {
+	    // since we added the Euro char on top, check we actually got the family
+	    // we requested. If we didn't get it correctly, remove the Euro from the pattern
+	    // and try again.
+	    FcChar8 *f;
+	    res = FcPatternGetString(result, FC_FAMILY, 0, &f);
+	    if (res == FcResultMatch && QString::fromUtf8((char *)f) != family->rawName) {
+		qDebug("trying without Euro");
+		FcPatternDel(pattern, FC_CHARSET);
+		FcCharSet *cs = FcCharSetCreate();
+		QChar sample = sampleCharacter(script);
+		FcCharSetAddChar(cs, sample.unicode());
+		FcPatternAddCharSet(pattern, FC_CHARSET, cs);
+		result = XftFontMatch( QPaintDevice::x11AppDisplay(), fp->screen, pattern, &res );
+	    }
+	}
+#endif
 	XftPatternDestroy(pattern);
 
 	// We pass a duplicate to XftFontOpenPattern because either xft font
