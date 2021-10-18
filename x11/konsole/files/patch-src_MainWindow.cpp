From 00d565eedea5be0b5c9ad66b29bdf14c63a5e035 Mon Sep 17 00:00:00 2001
From: Adriaan de Groot <groot@kde.org>
Date: Mon, 18 Oct 2021 11:07:30 +0200
Subject: [PATCH 2/2] Special-case PID 0 on FreeBSD

PID 0 is the kernel; when the shell exits, the process ID for
the session becomes 0. Downstream bug report
	https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258996
--- src/MainWindow.cpp.orig	2021-10-04 22:10:38 UTC
+++ src/MainWindow.cpp
@@ -609,6 +609,14 @@ bool MainWindow::queryClose()
             continue;
         }
 
+        // On FreeBSD, after exiting the shell, the foreground GID is
+        // an invalid value, and the shell PID is 0. Those are not equal,
+        // so isForegroundProcessActive() returns true -- leading to a
+        // complaint about "kernel" here. Special-case PID 0 to avoid that.
+        if (session->processId() == 0) {
+            continue;
+        }
+
         const QString defaultProc = session->program().split(QLatin1Char('/')).last();
         const QString currentProc = session->foregroundProcessName().split(QLatin1Char('/')).last();
 
