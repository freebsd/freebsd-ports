--- xprop/xprop.c.orig	2002-03-14 12:14:47 UTC
+++ xprop/xprop.c
@@ -586,7 +586,7 @@ _put_char(c)
 {
 	if (--_buf_len<0) {
 		_buf_ptr[0]='\0';
-		return;
+		return 0;
 	}
 	_buf_ptr++[0] = c;
 }
@@ -1357,10 +1357,10 @@ remove_property (dpy, w, propname)
     if (id == None) {
 	fprintf (stderr, "%s:  no such property \"%s\"\n",
 		 program_name, propname);
-	return;
+	return 0;
     }
     XDeleteProperty (dpy, w, id);
-    return;
+    return 0;
 }
 
 thunk *Handle_Prop_Requests(argc, argv)
@@ -1514,13 +1514,13 @@ Show_Prop(format, dformat, prop)
   printf("%s", prop);
   if (!(atom = Parse_Atom(prop, True))) {
 	  printf(":  no such atom on any window.\n");
-	  return;
+	  return 0;
   }
 
   data = Get_Property_Data_And_Type(atom, &length, &type, &size);
   if (!size) {
           puts(":  not found.");
-	  return;
+	  return 0;
   }
 
   if (!notype && type)
@@ -1535,7 +1535,7 @@ Show_Prop(format, dformat, prop)
   if (fsize!=size && fsize!=0) {
 	printf(": Type mismatch: assumed size %d bits, actual size %d bits.\n",
 	 fsize, size);
-	  return;
+	  return 0;
   }
 
   thunks = Break_Down_Property(data, (int)length, format, size);
