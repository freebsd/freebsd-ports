diff --git a/src/main.cpp b/src/main.cpp
index 06f3ce491dbf58270ab5df38794903dab002bf39..b477109fd1a6bf4315efe21dcaaf89570fbd392d 100644
--- src/main.cpp
+++ src/main.cpp
@@ -167,6 +167,8 @@ extern "C" int Q_DECL_EXPORT kdemain(int argc, char *argv[])
     if (!Konsole::KonsoleSettings::useSingleInstance()
         && !parser->isSet(QStringLiteral("new-tab"))) {
         startupOption = KDBusService::Multiple;
+    } else if (Konsole::KonsoleSettings::useSingleInstance()) {
+        startupOption = KDBusService::Unique;
     }
 
     atexit(deleteQApplication);
