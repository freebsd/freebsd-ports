--- ../generic/tkCursor.c	2001/08/15 15:44:36	1.7
+++ ../generic/tkCursor.c	2001/10/23 08:40:47	1.8
@@ -276,13 +276,12 @@
     cursorPtr->objRefCount = 0;
     cursorPtr->otherTable = &dispPtr->cursorNameTable;
     cursorPtr->hashPtr = nameHashPtr;
-	cursorPtr->nextPtr = NULL;
+    cursorPtr->nextPtr = existingCursorPtr;
     cursorPtr->idHashPtr = Tcl_CreateHashEntry(&dispPtr->cursorIdTable, 
             (char *) cursorPtr->cursor, &new);
     if (!new) {
 	panic("cursor already registered in Tk_GetCursor");
     }
-    cursorPtr->nextPtr = existingCursorPtr;
     Tcl_SetHashValue(nameHashPtr, cursorPtr);
     Tcl_SetHashValue(cursorPtr->idHashPtr, cursorPtr);
 
@@ -384,6 +383,7 @@
     cursorPtr->objRefCount = 0;
     cursorPtr->idHashPtr = Tcl_CreateHashEntry(&dispPtr->cursorIdTable, 
             (char *) cursorPtr->cursor, &new);
+    cursorPtr->nextPtr = NULL;
 
     if (!new) {
 	panic("cursor already registered in Tk_GetCursorFromData");
