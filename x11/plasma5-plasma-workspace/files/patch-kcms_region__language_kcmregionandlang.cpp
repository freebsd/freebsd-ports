--- kcms/region_language/kcmregionandlang.cpp.orig	2023-10-25 10:05:43 UTC
+++ kcms/region_language/kcmregionandlang.cpp
@@ -61,7 +61,7 @@ KCMRegionAndLang::KCMRegionAndLang(QObject *parent, co
     qRegisterMetaType<KCM_RegionAndLang::SettingType>();
     qmlRegisterUncreatableMetaObject(KCM_RegionAndLang::staticMetaObject, "kcmregionandlang", 1, 0, "SettingType", "Error: SettingType is an enum");
 
-#ifdef GLIBC_LOCALE_GENERATED
+#if GLIBC_LOCALE_GENERATED
     // fedora pre generate locales, fetch available locales from localectl. /usr/share/i18n/locales is empty in fedora
     QDir glibcLocaleDir(localeFileDirPath());
     if (glibcLocaleDir.isEmpty()) {
