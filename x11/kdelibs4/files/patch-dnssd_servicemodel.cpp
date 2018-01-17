Backport of

rom 80b43aaae27cfdf543483cd55d9012e37219350a Mon Sep 17 00:00:00 2001
From: Alex Richardson <arichardson.kde@gmail.com>
Date: Wed, 29 Jan 2014 21:56:27 +0100
Subject: [PATCH] Fix build with clang

If we don't cast to unsigned int clang complains with following message:

error: case value evaluates to 2690980318, which cannot be narrowed to
type 'int'

--- dnssd/servicemodel.cpp.orig	2018-01-07 11:07:50 UTC
+++ dnssd/servicemodel.cpp
@@ -80,7 +80,7 @@ QVariant ServiceModel::data(const QModelIndex& index, 
     if (!index.isValid()) return QVariant();
     if (!hasIndex(index.row(), index.column(), index.parent())) return QVariant();
     const QList<RemoteService::Ptr> srv=d->m_browser->services();
-    switch (role) {
+    switch ((uint)role) {
 	case Qt::DisplayRole: 
 	    switch (index.column()) {
 		case ServiceName: return srv[index.row()]->serviceName();
