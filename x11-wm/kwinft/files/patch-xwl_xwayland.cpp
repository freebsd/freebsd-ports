Revert https://gitlab.com/kwinft/kwinft/-/commit/e22b49694e87

xwl/xwayland.cpp:64:5: error: use of undeclared identifier 'close'
    close(pipe);
    ^
xwl/xwayland.cpp:79:9: error: use of undeclared identifier 'pipe'
    if (pipe(pipeFds) != 0) {
        ^
xwl/xwayland.cpp:88:14: error: use of undeclared identifier 'dup'
    int fd = dup(sx[1]);
             ^
xwl/xwayland.cpp:96:9: error: use of undeclared identifier 'close'
        close(fd);
        ^
xwl/xwayland.cpp:99:23: error: use of undeclared identifier 'dup'
    auto const wlfd = dup(waylandSocket);
                      ^
xwl/xwayland.cpp:101:9: error: use of undeclared identifier 'close'
        close(fd);
        ^
xwl/xwayland.cpp:153:5: error: use of undeclared identifier 'close'
    close(pipeFds[1]);
    ^

--- xwl/xwayland.cpp.orig	2022-06-14 17:35:07 UTC
+++ xwl/xwayland.cpp
@@ -44,6 +44,7 @@ along with this program.  If not, see <http://www.gnu.
 #include <compositor.h>
 #include <iostream>
 #include <sys/socket.h>
+#include <unistd.h>
 
 static void readDisplay(int pipe)
 {
