../src/compositor.cpp:62:7: error: 'alignas' attribute cannot be applied to types
        char alignas(16) pushConstantBuffer[128];
             ^

--- src/compositor.cpp.orig	2020-01-11 22:22:06 UTC
+++ src/compositor.cpp
@@ -59,7 +59,7 @@ bool Drawable::AssignPipeline(const Pipeline *prenderP
 }
 
 void Drawable::BindShaderResources(const std::vector<std::pair<ShaderModule::VARIABLE, const void *>> *pVarAddrs, const VkCommandBuffer *pcommandBuffer){
-	char alignas(16) pushConstantBuffer[128];
+	alignas(16) char pushConstantBuffer[128];
 	for(uint i = 0, p = 0; i < Pipeline::SHADER_MODULE_COUNT; ++i){
 		//bind descriptor sets
 		if(!passignedSet->p->pshaderModule[i])
