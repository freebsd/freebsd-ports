--- src/functions.c 3 Nov 2002 21:00:36 -0000       1.98
+++ src/functions.c 30 Oct 2003 05:35:18 -0000      1.99
@@ -704,8 +704,10 @@
            repv name;
            if (type == XA_ATOM && (name = x_atom_symbol (l_data[i])) != Qnil)
                rep_VECTI(ret_data, i) = name;
+           else if (type == XA_INTEGER)
+               rep_VECTI(ret_data, i) = rep_make_long_int((long) l_data[i]);
            else
-               rep_VECTI(ret_data, i) = rep_make_long_uint(l_data[i]);
+               rep_VECTI(ret_data, i) = rep_make_long_uint(l_data[i] & 0xffffffffUL);
        }
        break;
     }



