--- ./VkPipe.C.orig	Wed Jul 23 02:33:13 2003
+++ ./VkPipe.C	Wed Jul 23 03:05:28 2003
@@ -67,7 +67,7 @@
     _input->attach(pipefd[0], XtInputReadMask);
     _input->addCallback(VkInput::inputCallback, 
 						this,
-						(VkCallbackMethod)&(VkPipe::handleInput));
+						(VkCallbackMethod)(&VkPipe::handleInput));
 }
 
 VkPipe::~VkPipe()
