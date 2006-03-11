--- includex/v/vtimer.h.orig	Fri Apr  4 23:37:28 2003
+++ includex/v/vtimer.h	Thu Mar  9 19:05:20 2006
@@ -19,13 +19,13 @@
 
     extern "C"
       {
-	void CtimerCB(XtPointer client_data, XtIntervalId* notUsed);
+	void CtimerCB(XtPointer client_data, XtIntervalId* notUsedVoid);
       }
 
     class vTimer
       {
 
-	friend void CtimerCB(XtPointer client_data, XtIntervalId* notUsed);
+	friend void CtimerCB(XtPointer client_data, XtIntervalId* notUsedVoid);
 
       public:		//---------------------------------------- public
 
