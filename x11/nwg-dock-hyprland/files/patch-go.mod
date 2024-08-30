Drop after lang/go122 appears (switch to USES=go:1.22,modules)

github.com/nwg-piotr/nwg-dock-hyprland: cannot compile Go 1.22 code

--- go.mod.orig	2024-08-30 23:04:22 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module nwg-dock-hyprland
 module nwg-dock-hyprland
 
-go 1.23
+go 1.21
 
 require (
 	github.com/allan-simon/go-singleinstance v0.0.0-20210120080615-d0997106ab37
