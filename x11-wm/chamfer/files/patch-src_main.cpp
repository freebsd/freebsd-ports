../src/main.cpp:162:47: error: 'RunCompositor' is an incomplete type
                Compositor::CompositorInterface *pcompInt = dynamic_cast<Compositor::CompositorInterface *>(pcomp);
                                                            ^                                               ~~~~~
../src/main.cpp:109:27: note: forward declaration of 'RunCompositor'
        void SetCompositor(class RunCompositor *pcomp){
                                 ^

--- src/main.cpp.orig	2020-01-11 22:22:06 UTC
+++ src/main.cpp
@@ -159,7 +159,7 @@ class RunBackend : public Config::BackendConfig{ (publ
 		Config::ContainerInterface &containerInt = SetupContainer<T,U>(pcreateInfo);
 		containerInt.OnSetupContainer();
 
-		Compositor::CompositorInterface *pcompInt = dynamic_cast<Compositor::CompositorInterface *>(pcomp);
+		Compositor::CompositorInterface *pcompInt = reinterpret_cast<Compositor::CompositorInterface *>(pcomp);
 
 		WManager::Container::Setup setup;
 		if(containerInt.floatingMode == Config::ContainerInterface::FLOAT_ALWAYS ||
