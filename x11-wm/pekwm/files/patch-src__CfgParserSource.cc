--- ./src/CfgParserSource.cc.orig	2023-01-31 19:52:25.779184000 +0100
+++ ./src/CfgParserSource.cc	2023-01-31 19:53:09.043407000 +0100
@@ -144,7 +144,7 @@
 		std::string path(Util::getEnv("PATH"));
 		path = _command_path + ":" + path;
 		env.override("PATH", path);
-		execle(PEKWM_SH, PEKWM_SH, "-c", _name.c_str(), nullptr,
+		execle(PEKWM_SH, PEKWM_SH, "-c", _name.c_str(), NULL,
 		       env.getCEnv());
 
 		::close (STDOUT_FILENO);
