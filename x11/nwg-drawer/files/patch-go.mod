Drop after lang/go122 appears (switch to USES=go:1.22,modules)

github.com/nwg-piotr/nwg-drawer: cannot compile Go 1.22 code

--- go.mod.orig	2024-02-08 02:12:17 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/nwg-piotr/nwg-drawer
 module github.com/nwg-piotr/nwg-drawer
 
-go 1.22
+go 1.21
 
 require (
 	github.com/allan-simon/go-singleinstance v0.0.0-20210120080615-d0997106ab37
