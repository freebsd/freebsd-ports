--- mk/nvidia.lib.mk.orig
+++ mk/nvidia.lib.mk
@@ -17,6 +17,7 @@
 
 install:
 .if defined(SHLIB_NAME)
+	@mkdir -p ${DESTDIR}${LIBDIR}
 	@rm -f ${DESTDIR}${LIBDIR}/${SHLIB_NAME}
 	@${INSTALL} -C -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
 		${NVIDIA_ROOT}/${OBJDIR}/${SHLIB_NAME} \
