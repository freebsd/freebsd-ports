Backport of

From 6c4f7f84dd1326853475d10e503f220e4555e5e2 Mon Sep 17 00:00:00 2001
From: Milian Wolff <mail@milianw.de>
Date: Sun, 2 Mar 2014 21:48:20 +0100
Subject: [PATCH] Fix clang compilation warning:

khtml/src/xml/dom_stringimpl.h:60:13: warning: cast from 'char *'
to 'QChar *' increases required alignment from 1 to 2 [-Wcast-align
        s = (QChar*) new cha sizeof(QChar)*( havestr ? len : 1 ) ;
            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Note that this line of code is pretty odd I have to say. It this
supposed to be an optimization to prevent the default ctor/dtor of
QChar to be called? Is it really worth it here?

REVIEW: 116544

--- khtml/xml/dom_stringimpl.h.orig	2018-01-07 11:19:19 UTC
+++ khtml/xml/dom_stringimpl.h
@@ -32,8 +32,8 @@
 #include "misc/khtmllayout.h"
 #include "misc/shared.h"
 
-#define QT_ALLOC_QCHAR_VEC( N ) (QChar*) new char[ sizeof(QChar)*( N ) ]
-#define QT_DELETE_QCHAR_VEC( P ) delete[] ((char*)( P ))
+#define QT_ALLOC_QCHAR_VEC( N ) reinterpret_cast<QChar*>(new char[ sizeof(QChar)*( N ) ])
+#define QT_DELETE_QCHAR_VEC( P ) delete[] (reinterpret_cast<char*>( P ))
 
 namespace DOM {
 
