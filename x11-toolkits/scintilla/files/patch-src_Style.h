--- src/Style.h.orig	2020-04-23 01:50:17 UTC
+++ src/Style.h
@@ -33,9 +33,9 @@ struct FontSpecification {
 class FontAlias : public Font {
 public:
 	FontAlias() noexcept;
-	// FontAlias objects can not be assigned except for initialization
+	// FontAlias objects can be copy or move constructed but not be assigned
 	FontAlias(const FontAlias &) noexcept;
-	FontAlias(FontAlias &&)  = delete;
+	FontAlias(FontAlias &&) noexcept;
 	FontAlias &operator=(const FontAlias &) = delete;
 	FontAlias &operator=(FontAlias &&) = delete;
 	~FontAlias() override;
@@ -72,7 +72,7 @@ class Style : public FontSpecification, public FontMea
 
 	Style();
 	Style(const Style &source) noexcept;
-	Style(Style &&) = delete;
+	Style(Style &&) noexcept = default;
 	~Style();
 	Style &operator=(const Style &source) noexcept;
 	Style &operator=(Style &&) = delete;
