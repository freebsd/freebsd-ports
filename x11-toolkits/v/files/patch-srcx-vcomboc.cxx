Regressed by https://gitlab.freedesktop.org/xorg/lib/libxaw/-/commit/197e9d055f3c

vcomboc.cxx:331:2: error: no matching function for call to 'XawListChange'
        XawListChange(_popupList, _workList, _numItems, _maxWidth, True);
        ^~~~~~~~~~~~~
/usr/local/include/X11/Xaw/List.h:167:6: note: candidate function not viable: no known conversion from 'char *[32]' to 'const char **' for 2nd argument
void XawListChange
     ^

--- srcx/vcomboc.cxx.orig	2003-04-04 21:37:00 UTC
+++ srcx/vcomboc.cxx
@@ -328,7 +328,7 @@ static Pixmap down_bitmap = 0;
 #ifndef Athena
 	XmListReplaceItemsPosUnselected(_popupList, (XmString*)_workList, _numItems, 1);
 #else
-	XawListChange(_popupList, _workList, _numItems, _maxWidth, True);
+	XawListChange(_popupList, (_Xconst char**)_workList, _numItems, _maxWidth, True);
 #endif
 	if (val < 0)		// unselect
 	    val = 0;
