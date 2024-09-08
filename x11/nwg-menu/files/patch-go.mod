Drop after lang/go122 appears (switch to USES=go:1.22,modules)

github.com/nwg-piotr/nwg-menu: cannot compile Go 1.22 code

--- go.mod.orig	2024-08-29 23:11:28 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/nwg-piotr/nwg-menu
 module github.com/nwg-piotr/nwg-menu
 
-go 1.23
+go 1.21
 
 require (
 	github.com/allan-simon/go-singleinstance v0.0.0-20210120080615-d0997106ab37
