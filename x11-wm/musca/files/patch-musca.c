--- musca.c.orig	2019-03-04 12:29:07 UTC
+++ musca.c
@@ -421,7 +421,7 @@ int sanity_stack(stack *s, Window *tree, ucell num)
 	if (s->depth)
 	{
 		int *indexes = allocate(sizeof(int) * s->depth);
-		int count = 0, i; Window *w;
+		int count = 0, i; Window *w = NULL;
 		FOR_STACK (w, s, Window*, i)
 		{
 			note("%d", i);
@@ -1673,7 +1673,6 @@ ubyte frame_grow(ubyte direction, ubyte adapt, ucell s
 	frame *f = t->frames;
 	frame **group = NULL;
 	int i = 0, x, y, w, h;
-	ubyte changes = 0;
 	if (direction == HORIZONTAL)
 	{
 		if (f->x + f->w >= t->head->screen->width - t->r)
@@ -1684,7 +1683,6 @@ ubyte frame_grow(ubyte direction, ubyte adapt, ucell s
 				group = frame_siblings(f, LEFT);
 				if (frame_siblings_growable(group, LEFT, size))
 				{
-					changes = 1;
 					x = f->x - size; w = size; y = f->y; h = 0;
 					for (i = 0; group[i]; i++)
 						y = MIN(y, group[i]->y), h += group[i]->h;
@@ -1702,7 +1700,6 @@ ubyte frame_grow(ubyte direction, ubyte adapt, ucell s
 			group = frame_siblings(f, RIGHT);
 			if (frame_siblings_growable(group, RIGHT, size))
 			{
-				changes = 1;
 				x = f->x + f->w; w = size; y = f->y; h = 0;
 				for (i = 0; group[i]; i++)
 					y = MIN(y, group[i]->y), h += group[i]->h;
@@ -1725,7 +1722,6 @@ ubyte frame_grow(ubyte direction, ubyte adapt, ucell s
 				group = frame_siblings(f, TOP);
 				if (frame_siblings_growable(group, TOP, size))
 				{
-					changes = 1;
 					y = f->y - size; h = size; x = f->x; w = 0;
 					for (i = 0; group[i]; i++)
 						x = MIN(x, group[i]->x), w += group[i]->w;
@@ -1743,7 +1739,6 @@ ubyte frame_grow(ubyte direction, ubyte adapt, ucell s
 			group = frame_siblings(f, BOTTOM);
 			if (frame_siblings_growable(group, BOTTOM, size))
 			{
-				changes = 1;
 				y = f->y + f->h; h = size; x = f->x; w = 0;
 				for (i = 0; group[i]; i++)
 					x = MIN(x, group[i]->x), w += group[i]->w;
@@ -2208,11 +2203,9 @@ dcell parse_size(char *cmd, regmatch_t *subs, ucell in
 char* com_frame_split(char *cmd, regmatch_t *subs)
 {
 	group *g = heads->groups; frame *f = g->frames;
-	int sw = heads->screen->width  - g->l - g->r,
-	    sh = heads->screen->height - g->t - g->b;
 	char *mode = regsubstr(cmd, subs, 1);
-	ucell fs = f->h, ss = sh; ubyte dir = VERTICAL;
-	if (*mode == 'h') { fs = f->w; ss = sw; dir = HORIZONTAL; }
+	ucell fs = f->h; ubyte dir = VERTICAL;
+	if (*mode == 'h') { fs = f->w; dir = HORIZONTAL; }
 	dcell size = parse_size(cmd, subs, 2, fs);
 	frame_split(dir, size / fs);
 	free(mode);
@@ -2633,7 +2626,7 @@ char* com_switch(char *cmd, regmatch_t *subs)
 }
 char* com_command(char *cmd, regmatch_t *subs)
 {
-	int i; alias *a; autostr s; str_create(&s);
+	int i; alias *a = NULL; autostr s; str_create(&s);
 	str_print(&s, strlen(command_hints)+NOTE, "%s \n", command_hints);
 	FOR_STACK (a, aliases, alias*, i) str_print(&s, NOTE, "%s \n", a->name);
 	menu_wrapper(s.pad, settings[ms_run_musca_command].s);
@@ -2750,7 +2743,7 @@ char* show_windows()
 char* show_aliases()
 {
 	autostr s; str_create(&s);
-	alias *a; int i;
+	alias *a = NULL; int i;
 	FOR_STACK (a, aliases, alias*, i)
 		str_print(&s, strlen(a->name)+strlen(a->command)+10, "alias %s %s\n",
 			a->name, a->command);
@@ -2852,7 +2845,7 @@ char* com_client(char *cmd, regmatch_t *subs)
 }
 char* com_place(char *cmd, regmatch_t *subs)
 {
-	placement *p; int i;
+	placement *p = NULL; int i;
 	char *class = regsubstr(cmd, subs, 1);
 	ubyte flag = parse_flag(cmd, subs, 2, 0);
 	char *group = regsubstr(cmd, subs, 3);
@@ -3444,7 +3437,7 @@ ubyte insert_command(char* cmd)
 		autostr s; str_create(&s);
 		for (;;)
 		{
-			char c = getchar();
+			int c = getchar();
 			if (c == EOF) break;
 			str_push(&s, c);
 		}
@@ -3533,7 +3526,7 @@ void ungrab_stuff()
 }
 void grab_stuff()
 {
-	int i, j, k; head *h; binding *b; ucell *m;
+	int i, j, k; head *h; binding *b; ucell *m = NULL;
 	refresh_bindings();
 	ungrab_stuff();
 	ucell modifiers[] = { 0, LockMask, NumlockMask, LockMask|NumlockMask };
@@ -3553,7 +3546,7 @@ void setup_regex()
 {
 	int i;
 	command_hash = hash_create();
-	command *c; autostr str; str_create(&str);
+	command *c = NULL; autostr str; str_create(&str);
 	FOR_ARRAY (c, commands, command, i)
 	{
 		char *keys = c->keys;
@@ -3569,7 +3562,7 @@ void setup_regex()
 	strtrim(command_hints);
 	// compile setting regex
 	setting_hash = hash_create();
-	setting *s;
+	setting *s = NULL;
 	FOR_ARRAY (s, settings, setting, i)
 		hash_set(setting_hash, s->name, s);
 	// compile modmask regex
@@ -3600,7 +3593,7 @@ void setup_numlock()
 }
 void setup_bindings()
 {
-	int i; keymap *k;
+	int i; keymap *k = NULL;
 	// prepare key bindings
 	bindings = stack_create();
 	FOR_ARRAY (k, keymaps, keymap, i)
