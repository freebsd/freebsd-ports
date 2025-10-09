--- winit/src/platform_specific/mod.rs.orig	2025-09-19 07:04:16 UTC
+++ winit/src/platform_specific/mod.rs
@@ -10,19 +10,19 @@ use winit::raw_window_handle::HasWindowHandle;
 };
 use winit::raw_window_handle::HasWindowHandle;
 
-#[cfg(all(feature = "wayland", target_os = "linux"))]
+#[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
 pub mod wayland;
 
-#[cfg(all(feature = "wayland", target_os = "linux"))]
+#[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
 pub use wayland::*;
-#[cfg(all(feature = "wayland", target_os = "linux"))]
+#[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
 use wayland_backend::client::Backend;
 
 use crate::{program::WindowManager, Program};
 
 #[derive(Debug)]
 pub enum Event {
-    #[cfg(all(feature = "wayland", target_os = "linux"))]
+    #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
     Wayland(sctk_event::SctkEvent),
 }
 
@@ -48,7 +48,7 @@ pub struct PlatformSpecific {
 
 #[derive(Debug, Default)]
 pub struct PlatformSpecific {
-    #[cfg(all(feature = "wayland", target_os = "linux"))]
+    #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
     wayland: WaylandSpecific,
 }
 
@@ -58,7 +58,7 @@ impl PlatformSpecific {
         action: iced_runtime::platform_specific::Action,
     ) {
         match action {
-            #[cfg(all(feature = "wayland", target_os = "linux"))]
+            #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
             iced_runtime::platform_specific::Action::Wayland(a) => {
                 self.send_wayland(wayland::Action::Action(a));
             }
@@ -76,7 +76,7 @@ impl PlatformSpecific {
     }
 
     pub(crate) fn clear_subsurface_list(&mut self) {
-        #[cfg(all(feature = "wayland", target_os = "linux"))]
+        #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
         {
             self.wayland.clear_subsurface_list();
         }
@@ -87,7 +87,7 @@ impl PlatformSpecific {
         id: window::Id,
         window: &dyn HasWindowHandle,
     ) {
-        #[cfg(all(feature = "wayland", target_os = "linux"))]
+        #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
         {
             use cctk::sctk::reexports::client::{
                 protocol::wl_surface::WlSurface, Proxy,
@@ -138,7 +138,7 @@ impl PlatformSpecific {
     pub(crate) fn create_surface(
         &mut self,
     ) -> Option<Box<dyn HasWindowHandle + Send + Sync + 'static>> {
-        #[cfg(all(feature = "wayland", target_os = "linux"))]
+        #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
         {
             return self.wayland.create_surface();
         }
@@ -154,7 +154,7 @@ impl PlatformSpecific {
         data: &[u8],
         offset: Vector,
     ) {
-        #[cfg(all(feature = "wayland", target_os = "linux"))]
+        #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
         {
             return self.wayland.update_surface_shm(
                 surface, width, height, scale, data, offset,
@@ -193,7 +193,7 @@ pub(crate) fn handle_event<'a, P, C>(
     C: Compositor<Renderer = P::Renderer>,
 {
     match e {
-        #[cfg(all(feature = "wayland", target_os = "linux"))]
+        #[cfg(all(feature = "wayland", any(target_os = "linux", target_os = "freebsd")))]
         Event::Wayland(e) => {
             platform_specific.wayland.handle_event(
                 e,
