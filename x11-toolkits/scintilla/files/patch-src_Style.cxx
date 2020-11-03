--- src/Style.cxx.orig	2020-04-23 01:50:17 UTC
+++ src/Style.cxx
@@ -24,6 +24,11 @@ FontAlias::FontAlias(const FontAlias &other) noexcept 
 	SetID(other.fid);
 }
 
+FontAlias::FontAlias(FontAlias &&other) noexcept : Font() {
+	SetID(other.fid);
+	other.ClearFont();
+}
+
 FontAlias::~FontAlias() {
 	SetID(FontID{});
 	// ~Font will not release the actual font resource since it is now 0
