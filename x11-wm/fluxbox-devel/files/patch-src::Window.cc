--- src/Window.cc.orig	Fri Jan 11 13:21:59 2002
+++ src/Window.cc	Wed Jan 30 06:54:54 2002
@@ -22,7 +22,7 @@
 // FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 // DEALINGS IN THE SOFTWARE.
 
-// $Id: Window.cc,v 1.18 2002/01/11 10:04:32 fluxgen Exp $
+// $Id: Window.cc,v 1.19.2.1 2002/01/12 16:36:18 fluxgen Exp $
 
 // stupid macros needed to access some functions in version 2 of the GNU C
 // library
@@ -441,7 +441,9 @@ FluxboxWindow::FluxboxWindow(Window w, B
 
 FluxboxWindow::~FluxboxWindow(void) {
 	Fluxbox *fluxbox = Fluxbox::instance();
-	
+	//TODO: Move this to Workspace::removeWindow
+	if (client.transient_for)	
+		fluxbox->setFocusedWindow(client.transient_for);	
 	
 	if (moving || resizing) {
 		screen->hideGeometry();
@@ -556,9 +558,7 @@ FluxboxWindow::~FluxboxWindow(void) {
 		fluxbox->removeWindowSearch(client.window);
 		screen->removeNetizen(client.window);
 	}
-	//TODO: Move this to Workspace::removeWindow
-	if (client.transient_for)	
-		fluxbox->setFocusedWindow(client.transient_for);	
+	
 	#ifdef DEBUG	
 	fprintf(stderr, "%s(%d): ~FluxboxWindow(this=%p) done\n", __FILE__, __LINE__, this);
 	#endif
