--- ./os.c	2007-07-22 11:53:22.000000000 +0400
+++ ./os.c	2007-07-22 11:57:56.000000000 +0400
@@ -17397,11 +17397,16 @@
 	jint rc = 0;
 	OS_NATIVE_ENTER(env, that, realpath_FUNC);
 	if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
-	if (arg1) if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
+	if (arg1) {
+	    if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
+	} else
+	    lparg1 = malloc(PATH_MAX);
 	rc = (jint)realpath((const char *)lparg0, (char *)lparg1);
 fail:
 	if (arg1 && lparg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
 	if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
+	if (!arg1 && lparg1 && rc == 0)
+	    free(lparg1);
 	OS_NATIVE_EXIT(env, that, realpath_FUNC);
 	return rc;
 }

