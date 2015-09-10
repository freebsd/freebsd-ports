From 0e4d41f065f7803d096e6c53b3956c820186c3ea Mon Sep 17 00:00:00 2001
From: Reginald Kennedy <rk@rejii.com>
Date: Sun, 31 May 2015 07:25:46 +0800
Subject: [PATCH] Add SIMPLEQ->STAILQ macros for freebsd.

---
 freebsd/util.h |   18 +++++++++++++++++-
 1 files changed, 17 insertions(+), 1 deletions(-)

diff --git a/freebsd/util.h b/freebsd/util.h
index 4737d42..34b5c36 100644
--- freebsd/util.h
+++ freebsd/util.h
@@ -1,5 +1,21 @@
 #include <libutil.h>
 
 #ifndef TAILQ_END
-#define	TAILQ_END(head)			NULL
+#define TAILQ_END(head)			NULL
+#endif
+
+#ifndef SIMPLEQ_HEAD
+#define SIMPLEQ_HEAD			STAILQ_HEAD
+#define SIMPLEQ_HEAD_INITIALIZER	STAILQ_HEAD_INITIALIZER
+#define SIMPLEQ_ENTRY			STAILQ_ENTRY
+#define SIMPLEQ_INIT			STAILQ_INIT
+#define SIMPLEQ_INSERT_AFTER		STAILQ_INSERT_AFTER
+#define SIMPLEQ_INSERT_HEAD		STAILQ_INSERT_HEAD
+#define SIMPLEQ_INSERT_TAIL		STAILQ_INSERT_TAIL
+#define SIMPLEQ_EMPTY			STAILQ_EMPTY
+#define SIMPLEQ_FIRST			STAILQ_FIRST
+#define SIMPLEQ_REMOVE_AFTER		STAILQ_REMOVE_AFTER
+#define SIMPLEQ_REMOVE_HEAD		STAILQ_REMOVE_HEAD
+#define SIMPLEQ_FOREACH			STAILQ_FOREACH
+#define SIMPLEQ_END(head)		NULL
 #endif
-- 
1.7.6

