--- doc/gen.sh.orig	2024-05-02 23:49:23 UTC
+++ doc/gen.sh
@@ -18,7 +18,7 @@ for FILE in "$DIR"/*scd; do
 fi
 
 for FILE in "$DIR"/*scd; do
-	GEN="$GEN_DIR"/"$(basename --suffix .scd "$FILE")"
+	GEN="$GEN_DIR"/"$(basename "$FILE" .scd)"
 	printf "generating %s..." "$GEN"
 	scdoc < "$FILE" > "$GEN"
 	printf " ...done!\n"
