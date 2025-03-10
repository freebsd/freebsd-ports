https://github.com/wilhelmy/notion/commit/e7638ba26ec6ddb6d86abf7443b2e617c7b68b1f
https://github.com/raboof/notion/issues/350

From e7638ba26ec6ddb6d86abf7443b2e617c7b68b1f Mon Sep 17 00:00:00 2001
From: Moritz Wilhelmy <mw@barfooze.de>
Date: Fri, 24 Feb 2023 02:08:25 +0100
Subject: [PATCH] mod_notionflux: Add ifdef for fchmod on FreeBSD (closes #350)

--- mod_notionflux/mod_notionflux.c.orig	2024-09-25 10:34:48 UTC
+++ mod_notionflux/mod_notionflux.c
@@ -2,7 +2,7 @@
  * mod_notionflux/mod_notionflux/mod_notionflux.c
  *
  * Copyright (c) Tuomo Valkonen 2004-2005.
- * Copyright (c) The Notion development team 2019
+ * Copyright (c) The Notion development team 2019-2023
  *
  * This is free software; you can redistribute it and/or modify it under
  * the terms of the GNU Lesser General Public License as published by
@@ -328,8 +328,10 @@ static bool start_listening()
     if(listenfd<0)
         goto errwarn;
 
+#ifndef __FreeBSD__
     if(fchmod(listenfd, S_IRUSR|S_IWUSR)<0)
         goto errwarn;
+#endif
 
     addr.sun_family=AF_UNIX;
 
