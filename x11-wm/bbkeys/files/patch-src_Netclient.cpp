--- src/Netclient.cpp.orig
+++ src/Netclient.cpp
@@ -141,6 +141,7 @@
   int result;
   unsigned long maxread = nelements;
   bool ret = False;
+  int bsize;
 
   // try get the first element
   result = XGetWindowProperty(_display.XDisplay(), win, atom, 0l, 1l, False,
@@ -149,18 +150,19 @@
   ret = (result == Success && ret_type == type && ret_size == size &&
          nelements > 0);
   if (ret) {
+    bsize = (size == 32) ? sizeof(long) : size/8;
     if (ret_bytes == 0 || maxread <= nelements) {
       // we got the whole property's value
-      *value = new unsigned char[nelements * size/8 + 1];
-      memcpy(*value, c_val, nelements * size/8 + 1);
+      *value = new unsigned char[nelements * bsize + 1];
+      memcpy(*value, c_val, nelements * bsize + 1);
     } else {
       // get the entire property since it is larger than one long
       XFree(c_val);
       // the number of longs that need to be retreived to get the property's
       // entire value. The last + 1 is the first long that we retrieved above.
       int remain = (ret_bytes - 1)/sizeof(long) + 1 + 1;
-      if (remain > size/8 * (signed)maxread) // dont get more than the max
-        remain = size/8 * (signed)maxread;
+      if (remain > bsize * (signed)maxread) // dont get more than the max
+        remain = bsize * (signed)maxread;
       result = XGetWindowProperty(_display.XDisplay(), win, atom, 0l, remain, False, type,
                                   &ret_type, &ret_size, &nelements, &ret_bytes,
                                   &c_val);
@@ -174,8 +176,8 @@
       if (! ret)
         return getValue(win, atom, type, maxread, value, size);
   
-      *value = new unsigned char[nelements * size/8 + 1];
-      memcpy(*value, c_val, nelements * size/8 + 1);
+      *value = new unsigned char[nelements * bsize + 1];
+      memcpy(*value, c_val, nelements * bsize + 1);
     }    
   }
   if (c_val) XFree(c_val);
