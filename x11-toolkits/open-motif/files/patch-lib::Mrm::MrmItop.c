--- lib/Mrm/MrmItop.c~	Fri Jan 11 14:56:23 2002
+++ lib/Mrm/MrmItop.c	Sun Nov 23 19:42:03 2003
@@ -642,10 +642,11 @@
    *  Local variables
    */
   Cardinal	result ;		/* function results */
+  IDBResource	resid ;
 
   if ( (result=Idb__FIL_Valid((IDBFile)file_id)) != MrmSUCCESS ) return result ;
-  result = Idb__RID_NextRID ((IDBFile)file_id, 
-			     (IDBResource *)resource_id_return) ;
+  result = Idb__RID_NextRID ((IDBFile)file_id, &resid) ;
+  if ( result == MrmSUCCESS ) *resource_id_return = resid;
   return result ;
 
 }
