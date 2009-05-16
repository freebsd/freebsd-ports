--- common/gdm-address.h.orig	2009-05-09 21:08:07.000000000 -0400
+++ common/gdm-address.h	2009-05-09 21:08:34.000000000 -0400
@@ -36,6 +36,8 @@ G_BEGIN_DECLS
 
 #define GDM_TYPE_ADDRESS (gdm_address_get_type ())
 
+#define		gdm_sockaddr_len(sa)	(((struct sockaddr *)sa)->sa_family == AF_INET6 ? sizeof(struct sockaddr_in6) : sizeof(struct sockaddr_in))
+
 typedef struct _GdmAddress GdmAddress;
 
 GType                    gdm_address_get_type                  (void);
