--- gnome-pty-helper/gnome-pty-helper.c.orig	Sat Aug 13 07:55:19 2005
+++ gnome-pty-helper/gnome-pty-helper.c	Wed Aug 24 19:03:08 2005
@@ -95,12 +95,12 @@ static pty_info *pty_list;
 #endif /* CMSG_DATA */
 
 static struct cmsghdr *cmptr;
-static int CONTROLLEN;
+static socklen_t CONTROLLEN;
 
 static int
 init_msg_pass ()
 {
-	CONTROLLEN = (CMSG_DATA (cmptr) - (unsigned char *)cmptr) + sizeof(int);
+	CONTROLLEN = CMSG_SPACE (sizeof (int));
 	cmptr = malloc (CONTROLLEN);
 
 	if (cmptr)
@@ -128,7 +128,7 @@ pass_fd (int client_fd, int fd)
 
 	cmptr->cmsg_level = SOL_SOCKET;
 	cmptr->cmsg_type  = SCM_RIGHTS;
-	cmptr->cmsg_len   = CONTROLLEN;
+	cmptr->cmsg_len   = CMSG_LEN (sizeof (fd));
 	*(int *)CMSG_DATA (cmptr) = fd;
 
 	if (sendmsg (client_fd, &msg, 0) != 1)
