--- Common/c3270/keymap.c.orig	2024-05-23 04:46:10 UTC
+++ Common/c3270/keymap.c
@@ -111,7 +111,7 @@ static int
  * Returns 0 if equal, nonzero if not.
  */
 static int
-kcmp(k_t *a, k_t *b)
+kcmp3270(k_t *a, k_t *b)
 {
     if (a->key && b->key && (a->key == b->key)) {
 	return 0;
@@ -139,7 +139,7 @@ kvcmp(k_t *a, k_t *b, int len)
     	int i;
 
 	for (i = 0; i < len; i++) {
-	    	if (kcmp(&a[i], &b[i]))
+	    	if (kcmp3270(&a[i], &b[i]))
 			return 1;
 	}
 	return 0;
@@ -673,7 +673,7 @@ lookup_key(int kcode, ucs4_t ucs4, int modifiers)
 	for (k = master_keymap; k != NULL; k = k->next) {
 	    if (IS_INACTIVE(k))
 		continue;
-	    if (!kcmp(&code, &k->codes[0])) {
+	    if (!kcmp3270(&code, &k->codes[0])) {
 		if (k->ncodes == 1) {
 		    shortest = k;
 		    break;
@@ -693,7 +693,7 @@ lookup_key(int kcode, ucs4_t ucs4, int modifiers)
     }
 
     /* See if this character matches the next one we want. */
-    if (!kcmp(&code, &current_match->codes[consumed])) {
+    if (!kcmp3270(&code, &current_match->codes[consumed])) {
 	consumed++;
 	if (consumed == current_match->ncodes) {
 	    /* Final match. */
@@ -721,7 +721,7 @@ lookup_key(int kcode, ucs4_t ucs4, int modifiers)
 	    continue;
 	}
 	if (k->ncodes > consumed && !codecmp(k, current_match, consumed) &&
-		!kcmp(&k->codes[consumed], &code)) {
+		!kcmp3270(&k->codes[consumed], &code)) {
 	    consumed++;
 	    if (k->ncodes == consumed) {
 		j = ambiguous(k, consumed);
