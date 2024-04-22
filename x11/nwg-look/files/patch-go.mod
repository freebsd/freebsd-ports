Drop after lang/go122 appears (switch to USES=go:1.22,modules)

github.com/nwg-piotr/nwg-look: cannot compile Go 1.22 code

--- go.mod.orig	2024-02-11 23:43:12 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/nwg-piotr/nwg-look
 module github.com/nwg-piotr/nwg-look
 
-go 1.22
+go 1.21
 
 require (
 	github.com/gotk3/gotk3 v0.6.3
