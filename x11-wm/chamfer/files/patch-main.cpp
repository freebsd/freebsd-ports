- Add default shader path

--- src/main.cpp.orig	2020-01-11 22:22:06 UTC
+++ src/main.cpp
@@ -817,7 +817,7 @@ int main(sint argc, const char **pargv){	
 	args::Flag debugLayersOpt(group_comp,"debugLayers","Enable Vulkan debug layers.",{"debug-layers",'l'},false);
 	args::Flag noScissoringOpt(group_comp,"noScissoring","Disable scissoring optimization.",{"no-scissoring"},false);
 	args::Flag noHostMemoryImportOpt(group_comp,"noHostMemoryImport","Disable host shared memory import.",{"no-host-memory-import"},false);
-	args::ValueFlagList<std::string> shaderPaths(group_comp,"path","Shader lookup path. SPIR-V shader objects are identified by an '.spv' extension. Multiple paths may be specified.",{"shader-path"});
+	args::ValueFlagList<std::string> shaderPaths(group_comp,"path","Shader lookup path. SPIR-V shader objects are identified by an '.spv' extension. Multiple paths may be specified.",{"shader-path"},{"/usr/share/chamfer/shaders"});
 
 	try{
 		parser.ParseCLI(argc,pargv);
