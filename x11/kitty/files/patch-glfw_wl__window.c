--- glfw/wl_window.c.orig	2022-11-07 10:06:42 UTC
+++ glfw/wl_window.c
@@ -1964,12 +1964,12 @@ primary_selection_copy_callback_done(void *data, struc
     wl_callback_destroy(callback);
 }
 
-void _glfwSetupWaylandDataDevice() {
+void _glfwSetupWaylandDataDevice(void) {
     _glfw.wl.dataDevice = wl_data_device_manager_get_data_device(_glfw.wl.dataDeviceManager, _glfw.wl.seat);
     if (_glfw.wl.dataDevice) wl_data_device_add_listener(_glfw.wl.dataDevice, &data_device_listener, NULL);
 }
 
-void _glfwSetupWaylandPrimarySelectionDevice() {
+void _glfwSetupWaylandPrimarySelectionDevice(void) {
     _glfw.wl.primarySelectionDevice = zwp_primary_selection_device_manager_v1_get_device(_glfw.wl.primarySelectionDeviceManager, _glfw.wl.seat);
     if (_glfw.wl.primarySelectionDevice) zwp_primary_selection_device_v1_add_listener(_glfw.wl.primarySelectionDevice, &primary_selection_device_listener, NULL);
 }
