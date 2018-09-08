From 62d776518594f517dc59de3c87e53afdda339079 Mon Sep 17 00:00:00 2001
From: Romain Labolle <ravomavain@gmail.com>
Date: Sat, 3 Mar 2018 22:09:30 +0100
Subject: [PATCH] Add SOCK_CLOEXEC to signal handling sockets

SDDM is currennty leaking 8 sockets file descriptors to the user session.
Adding the CLOEXEC flag to the fd to avoid thoses leaks.
---
 src/daemon/SignalHandler.cpp | 8 ++++----
 1 file changed, 4 insertions(+), 4 deletions(-)

diff --git a/src/daemon/SignalHandler.cpp b/src/daemon/SignalHandler.cpp
index 5c536603..3054e635 100644
--- src/daemon/SignalHandler.cpp.orig	2017-12-05 16:00:16 UTC
+++ src/daemon/SignalHandler.cpp
@@ -34,25 +34,25 @@ namespace SDDM {
     int sigusr1Fd[2];
 
     SignalHandler::SignalHandler(QObject *parent) : QObject(parent) {
-        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sighupFd))
+        if (::socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sighupFd))
             qCritical() << "Failed to create socket pair for SIGHUP handling.";
 
         snhup = new QSocketNotifier(sighupFd[1], QSocketNotifier::Read, this);
         connect(snhup, SIGNAL(activated(int)), this, SLOT(handleSighup()));
 
-        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigintFd))
+        if (::socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sigintFd))
             qCritical() << "Failed to create socket pair for SIGINT handling.";
 
         snint = new QSocketNotifier(sigintFd[1], QSocketNotifier::Read, this);
         connect(snint, SIGNAL(activated(int)), this, SLOT(handleSigint()));
 
-        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigtermFd))
+        if (::socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sigtermFd))
             qCritical() << "Failed to create socket pair for SIGTERM handling.";
 
         snterm = new QSocketNotifier(sigtermFd[1], QSocketNotifier::Read, this);
         connect(snterm, SIGNAL(activated(int)), this, SLOT(handleSigterm()));
 
-        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigusr1Fd))
+        if (::socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sigusr1Fd))
             qCritical() << "Failed to create socket pair for SIGUSR1 handling.";
 
         snusr1 = new QSocketNotifier(sigusr1Fd[1], QSocketNotifier::Read, this);
