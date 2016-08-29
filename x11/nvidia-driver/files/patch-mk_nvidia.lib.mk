--- mk/nvidia.lib.mk.orig	2013-08-16 10:53:30.000000000 +0200
+++ mk/nvidia.lib.mk	2014-01-27 16:55:39.000000000 +0100
@@ -46,8 +46,8 @@
 .endif		
 .endif
 .if defined(AUXLINK_TGT)
-	@rm -f ${AUXLINK_LINK}
-	@ln -fs ${AUXLINK_TGT} ${AUXLINK_LINK}
+	@rm -f ${DESTDIR}${AUXLINK_LINK}
+	@ln -fs ${AUXLINK_TGT} ${DESTDIR}${AUXLINK_LINK}
 .endif
 .if defined(STATICLIB_NAME)
 	@rm -f ${DESTDIR}${LIBDIR}/${STATICLIB_NAME}
