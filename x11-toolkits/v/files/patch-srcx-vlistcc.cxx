Regressed by https://gitlab.freedesktop.org/xorg/lib/libxaw/-/commit/197e9d055f3c

vlistc.cxx:344:2: error: no matching function for call to 'XawListChange'
        XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
vlistc.cxx:374:6: error: no matching function for call to 'XawListChange'
            XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
            ^~~~~~~~~~~~~
vlistc.cxx:405:6: error: no matching function for call to 'XawListChange'
            XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
            ^~~~~~~~~~~~~
vlistc.cxx:484:5: error: no matching function for call to 'XawListChange'
    XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
    ^~~~~~~~~~~~~
/usr/local/include/X11/Xaw/List.h:167:6: note: candidate function not viable: no known conversion from 'char *[33]' to 'const char **' for 2nd argument
void XawListChange
     ^

--- srcx/vlistc.cxx.orig	2003-04-04 21:37:00 UTC
+++ srcx/vlistc.cxx
@@ -341,7 +341,7 @@ extern "C"
 		NULL);
 #else
 	// turn them all off!
-	XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
+	XawListChange(wCmd, (_Xconst char**)_workList, _listRows, _maxWidth, True);
 	SetScroll(_ScrlShown, _ScrlTop);
 #endif
 	SetCmdVal(val,Value);
@@ -371,7 +371,7 @@ extern "C"
 #ifndef Athena
 	    XmListDeselectAllItems(wCmd);
 #else
-	    XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
+	    XawListChange(wCmd, (_Xconst char**)_workList, _listRows, _maxWidth, True);
 #endif
 	    return;
 	  }
@@ -402,7 +402,7 @@ extern "C"
 
 	if (newSel >= 0 && newSel < _listRows)
 	  {
-	    XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
+	    XawListChange(wCmd, (_Xconst char**)_workList, _listRows, _maxWidth, True);
 	    XawListHighlight(wCmd, newSel);
 	  }
 	else			// have to scroll
@@ -481,7 +481,7 @@ extern "C"
 	_workList[ix] = _fullList[ix + _workMapsTo];
       }
 
-    XawListChange(wCmd, _workList, _listRows, _maxWidth, True);
+    XawListChange(wCmd, (_Xconst char**)_workList, _listRows, _maxWidth, True);
 
     // See if the currently selected item is on the list, and rehighlight
     int newSel = _curSelection - _workMapsTo;
@@ -676,7 +676,7 @@ extern "C"
 //============================>>> CScollProcCB <<<=============================
   void CScrollProcCB(Widget w, XtPointer This, XtPointer position)
   {
-    int pos = (int)position;
+    intptr_t pos = (intptr_t)position;
     ((vListCmd*)This)->ScrollProcCB(pos);
   }
 #endif	// Athena only
