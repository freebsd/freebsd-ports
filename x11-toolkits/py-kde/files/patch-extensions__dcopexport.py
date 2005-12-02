--- extensions/dcopexport.py.orig	Thu Dec  1 22:05:41 2005
+++ extensions/dcopexport.py	Thu Dec  1 22:06:24 2005
@@ -85,15 +85,16 @@
             result = self.method.pymethod (*arglist)
 
         # marshall the result as 'replyData'
-        s = QDataStream (replyData, IO_WriteOnly)
-        if self.method.rtype in numericTypes:
-            dcop_add (s, result, self.method.rtype)
-        elif self.method.rtype in stringTypes and isinstance (result, str):
-            dcop_add (s, eval ("%s('''%s''')" % (self.method.rtype, result)))
-        elif self.method.rtype.startswith ("QMap") or self.method.rtype.startswith ("QValueList"):
-            dcop_add (params, args [i], self.argtypes [i])
-        else:
-            dcop_add (s, result)
+        if self.method.rtype != "void":
+            s = QDataStream (replyData, IO_WriteOnly)
+            if self.method.rtype in numericTypes:
+                dcop_add (s, result, self.method.rtype)
+            elif self.method.rtype in stringTypes and isinstance (result, str):
+                dcop_add (s, eval ("%s('''%s''')" % (self.method.rtype, result)))
+            elif self.method.rtype.startswith ("QMap") or self.method.rtype.startswith ("QValueList"):
+                dcop_add (params, args [i], self.argtypes [i])
+            else:
+                dcop_add (s, result)
 
         # use append because we want to return the replyType reference,
         # not a new QCString
