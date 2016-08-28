--- mk/nvidia.lib.mk.orig	2015-08-24 03:56:22 UTC
+++ mk/nvidia.lib.mk
@@ -46,8 +46,8 @@ install: ${EXTRADEPS}
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
