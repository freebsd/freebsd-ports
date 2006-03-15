--- gnome-pty-helper/gnome-pty-helper.c.orig	Tue Feb 14 03:58:10 2006
+++ gnome-pty-helper/gnome-pty-helper.c	Sat Feb 25 16:38:04 2006
@@ -95,12 +95,12 @@ static pty_info *pty_list;
 #endif /* CMSG_DATA */
 
 static struct cmsghdr *cmptr;
-static int CONTROLLEN;
+static socklen_t CONTROLLEN;
 
 static int
 init_msg_pass (void)
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
