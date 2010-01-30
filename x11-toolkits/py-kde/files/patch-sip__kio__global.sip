diff -ru PyKDE-3.16.6/sip/kio/global.sip PyKDE-3.16.7/sip/kio/global.sip
--- sip/kio/global.sip	2009-06-10 22:44:48.000000000 +0100
+++ sip/kio/global.sip	2010-01-25 09:47:39.410088826 +0000
@@ -477,20 +477,7 @@
 %MethodCode
 //takes dict | (KIO.MetaData)
 //returns (KIO.MetaData)
-
-
-    PyObject *dict;
-    if (sipParseArgs(&sipArgsParsed,sipArgs,"T", &PyDict_Type, &dict))
-    {
-        int isErr = 0;
-        KIO::MetaData *map = (KIO::MetaData *)sipForceConvertToType(dict, sipType_KIO_MetaData, NULL, SIP_NO_CONVERTORS, NULL, &isErr);
-        if (isErr)
-        {
-            Py_INCREF (Py_None);
-            return Py_None;
-        }
-        return sipConvertFromType(map, sipType_KIO_MetaData, NULL);
-    }
+    sipRes = a0;
 %End
 
 //end
