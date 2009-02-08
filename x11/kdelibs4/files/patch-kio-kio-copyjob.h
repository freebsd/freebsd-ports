--- ../kio/kio/copyjob.h	(revision 917169)
+++ ../kio/kio/copyjob.h	(revision 917170)
@@ -245,6 +245,7 @@
 
     protected:
         CopyJob(CopyJobPrivate &dd);
+        void emitResult();
 
     private:
         Q_PRIVATE_SLOT(d_func(), void slotStart())
