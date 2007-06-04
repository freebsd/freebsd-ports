--- src/PythonInterface.cc.orig	Fri Nov 22 15:24:42 2002
+++ src/PythonInterface.cc	Sun May 27 01:16:12 2007
@@ -256,7 +256,7 @@
 class PythonInterfaceModule
 {
   public:
-    PythonInterfaceModule::PythonInterfaceModule(const string& name_, PyObject* config_)
+    PythonInterfaceModule(const string& name_, PyObject* config_)
       : name(name_),
         next(NULL),
         module(name_),
@@ -266,7 +266,7 @@
         FSInitialize = new MyPyFunctionPtr(module.dict.GetItemString("fluxlet_main"));
     }
 
-    PythonInterfaceModule::~PythonInterfaceModule()
+    ~PythonInterfaceModule()
     {
         delete FSInitialize;
     }
