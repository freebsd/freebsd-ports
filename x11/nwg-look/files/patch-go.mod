Drop after lang/go122 appears (switch to USES=go:1.22,modules)

github.com/nwg-piotr/nwg-look: cannot compile Go 1.22 code

--- go.mod.orig	2025-01-17 00:47:24 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/nwg-piotr/nwg-look
 module github.com/nwg-piotr/nwg-look
 
-go 1.23
+go 1.21
 
 require (
 	github.com/gotk3/gotk3 v0.6.5-0.20240618185848-ff349ae13f56
