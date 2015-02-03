From 9fa04388dcbb5bf205319569f540a62c03754688 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?J=C3=B6rg=20Sonnenberger?= <joerg@NetBSD.org>
Date: Wed, 26 Nov 2014 14:33:38 +0100
Subject: Remove unnecessary check.

The vmods member of XkbNamesPtr is an array and thus never NULL.

Signed-off-by: Thomas Klausner <wiz@NetBSD.org>
Signed-off-by: Peter Hutterer <peter.hutterer@who-t.net>

--- src/cout.c.orig	2012-03-08 05:37:23.000000000 +0100
+++ src/cout.c	2015-02-03 19:45:53.373211000 +0100
@@ -45,7 +45,7 @@ WriteCHdrVMods(FILE *file,Display *dpy,X
 {
 register int i,nOut;
 
-    if ((!xkb)||(!xkb->names)||(!xkb->names->vmods))
+    if ((!xkb)||(!xkb->names))
 	return False;
     for (i=nOut=0;i<XkbNumVirtualMods;i++) {
 	if (xkb->names->vmods[i]!=None) {
