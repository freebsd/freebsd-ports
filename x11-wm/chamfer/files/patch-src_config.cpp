../src/config.cpp:198:33: error: ordered comparison between pointer and zero ('const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::value_type *' (aka 'const char *') and 'int')
                        (*m)->fragmentShader.c_str() > 0?(*m)->fragmentShader.c_str():0
                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^ ~

--- src/config.cpp.orig	2020-01-11 22:22:06 UTC
+++ src/config.cpp
@@ -195,7 +195,7 @@ void ContainerInterface::UpdateShaders(){
 		const char *pshaderName[Compositor::Pipeline::SHADER_MODULE_COUNT] = {
 			(*m)->vertexShader.size() > 0?(*m)->vertexShader.c_str():0,
 			(*m)->geometryShader.size() > 0?(*m)->geometryShader.c_str():0,
-			(*m)->fragmentShader.c_str() > 0?(*m)->fragmentShader.c_str():0
+			(*m)->fragmentShader.size() > 0?(*m)->fragmentShader.c_str():0
 		};
 		pclientFrame->SetShaders(pshaderName);
 
