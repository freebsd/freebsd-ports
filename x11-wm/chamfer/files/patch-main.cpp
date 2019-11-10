- Add default shader path

--- src/main.cpp.orig	2019-08-02 19:10:02 UTC
+++ src/main.cpp
@@ -806,7 +806,7 @@ int main(sint argc, const char **pargv){	
 	args::ValueFlag<uint> deviceIndexOpt(group_comp,"id","GPU to use by its index. By default the first device in the list of enumerated GPUs will be used.",{"device-index"});
 	args::Flag debugLayersOpt(group_comp,"debugLayers","Enable Vulkan debug layers.",{"debug-layers",'l'},false);
 	args::Flag noScissoringOpt(group_comp,"noScissoring","Disable scissoring optimization.",{"no-scissoring"},false);
-	args::ValueFlagList<std::string> shaderPaths(group_comp,"path","Shader lookup path. SPIR-V shader objects are identified by an '.spv' extension. Multiple paths may be specified.",{"shader-path"});
+	args::ValueFlagList<std::string> shaderPaths(group_comp,"path","Shader lookup path. SPIR-V shader objects are identified by an '.spv' extension. Multiple paths may be specified.",{"shader-path"},{"/usr/share/chamfer/shaders"});
 
 	try{
 		parser.ParseCLI(argc,pargv);
