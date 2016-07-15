--- xdot.py.orig	2016-03-07 15:58:48 UTC
+++ xdot.py
@@ -30,13 +30,13 @@ import time
 import re
 import optparse
 
-from gi.repository import GLib
-from gi.repository import GObject
-from gi.repository import Gtk
-from gi.repository import Gdk
-from gi.repository import GdkPixbuf
-from gi.repository import Pango
-from gi.repository import PangoCairo
+import glib
+import gobject
+import gtk
+import gtk.gdk
+import gtk.keysyms
+import pango
+import pangocairo
 import cairo
 
 
@@ -120,7 +120,7 @@ class TextShape(Shape):
         try:
             layout = self.layout
         except AttributeError:
-            layout = PangoCairo.create_layout(cr)
+            layout = pangcairo.create_layout(cr)
 
             # set font options
             # see http://lists.freedesktop.org/archives/cairo/2007-February/009688.html
@@ -130,21 +130,21 @@ class TextShape(Shape):
             fo.set_hint_style(cairo.HINT_STYLE_NONE)
             fo.set_hint_metrics(cairo.HINT_METRICS_OFF)
             try:
-                PangoCairo.context_set_font_options(context, fo)
+                pangcairo.context_set_font_options(context, fo)
             except TypeError:
                 # XXX: Some broken pangocairo bindings show the error
                 # 'TypeError: font_options must be a cairo.FontOptions or None'
                 pass
             except KeyError:
-                # cairo.FontOptions is not registered as a foreign struct in older PyGObject versions.
+                # cairo.FontOptions is not registered as a foreign struct in older Pygobject versions.
                 # https://git.gnome.org/browse/pygobject/commit/?id=b21f66d2a399b8c9a36a1758107b7bdff0ec8eaa
                 pass
 
             # set font
-            font = Pango.FontDescription()
+            font = pango.FontDescription()
 
-            # https://developer.gnome.org/pango/stable/PangoMarkupFormat.html
-            markup = GObject.markup_escape_text(self.t)
+            # https://developer.gnome.org/pango/stable/pangoMarkupFormat.html
+            markup = gobject.markup_escape_text(self.t)
             if self.pen.bold:
                 markup = '<b>' + markup + '</b>'
             if self.pen.italic:
@@ -158,12 +158,12 @@ class TextShape(Shape):
             if self.pen.subscript:
                 markup = '<sub><small>' + markup + '</small></sub>'
 
-            success, attrs, text, accel_char = Pango.parse_markup(markup, -1, '\x00')
+            success, attrs, text, accel_char = pango.parse_markup(markup, -1, '\x00')
             assert success
             layout.set_attributes(attrs)
 
             font.set_family(self.pen.fontname)
-            font.set_absolute_size(self.pen.fontsize*Pango.SCALE)
+            font.set_absolute_size(self.pen.fontsize*pango.SCALE)
             layout.set_font_description(font)
 
             # set text
@@ -172,13 +172,13 @@ class TextShape(Shape):
             # cache it
             self.layout = layout
         else:
-            PangoCairo.update_layout(cr, layout)
+            pangcairo.update_layout(cr, layout)
 
         descent = 2 # XXX get descender from font metrics
 
         width, height = layout.get_size()
-        width = float(width)/Pango.SCALE
-        height = float(height)/Pango.SCALE
+        width = float(width)/pango.SCALE
+        height = float(height)/pango.SCALE
 
         # we know the width that dot thinks this text should have
         # we do not necessarily have a font with the same metrics
@@ -207,7 +207,7 @@ class TextShape(Shape):
         cr.save()
         cr.scale(f, f)
         cr.set_source_rgba(*self.select_pen(highlight).color)
-        PangoCairo.show_layout(cr, layout)
+        pangcairo.show_layout(cr, layout)
         cr.restore()
 
         if 0: # DEBUG
@@ -239,13 +239,13 @@ class ImageShape(Shape):
         self.path = path
 
     def draw(self, cr, highlight=False):
-        pixbuf = GdkPixbuf.Pixbuf.new_from_file(self.path)
+        pixbuf = gtk.gdk.pixbuf_new_from_file(self.path)
         sx = float(self.w)/float(pixbuf.get_width())
         sy = float(self.h)/float(pixbuf.get_height())
         cr.save()
         cr.translate(self.x0, self.y0 - self.h)
         cr.scale(sx, sy)
-        Gdk.cairo_set_source_pixbuf(cr, pixbuf, 0, 0)
+        gdk.cairo_set_source_pixbuf(cr, pixbuf, 0, 0)
         cr.paint()
         cr.restore()
 
@@ -631,7 +631,7 @@ class XDotAttrParser:
 
     def lookup_color(self, c):
         try:
-            color = Gdk.color_parse(c)
+            color = gdk.color_parse(c)
         except ValueError:
             pass
         else:
@@ -1318,12 +1318,12 @@ class Animation(object):
         self.timeout_id = None
 
     def start(self):
-        self.timeout_id = GLib.timeout_add(int(self.step * 1000), self.tick)
+        self.timeout_id = glib.timeout_add(int(self.step * 1000), self.tick)
 
     def stop(self):
         self.dot_widget.animation = NoAnimation(self.dot_widget)
         if self.timeout_id is not None:
-            GLib.source_remove(self.timeout_id)
+            glib.source_remove(self.timeout_id)
             self.timeout_id = None
 
     def tick(self):
@@ -1453,7 +1453,7 @@ class NullAction(DragAction):
         if item is None:
             item = dot_widget.get_jump(x, y)
         if item is not None:
-            dot_widget.get_window().set_cursor(Gdk.Cursor(Gdk.CursorType.HAND2))
+            dot_widget.get_window().set_cursor(gdk.Cursor(gdk.CursorType.HAND2))
             dot_widget.set_highlight(item.highlight)
         else:
             dot_widget.get_window().set_cursor(None)
@@ -1463,7 +1463,7 @@ class NullAction(DragAction):
 class PanAction(DragAction):
 
     def start(self):
-        self.dot_widget.get_window().set_cursor(Gdk.Cursor(Gdk.CursorType.FLEUR))
+        self.dot_widget.get_window().set_cursor(gdk.Cursor(gdk.CursorType.FLEUR))
 
     def drag(self, deltax, deltay):
         self.dot_widget.x += deltax / self.dot_widget.zoom_ratio
@@ -1518,18 +1518,18 @@ class ZoomAreaAction(DragAction):
         self.dot_widget.queue_draw()
 
 
-class DotWidget(Gtk.DrawingArea):
+class DotWidget(gtk.DrawingArea):
     """GTK widget that draws dot graphs."""
 
-    #TODO GTK3: Second argument has to be of type Gdk.EventButton instead of object.
+    #TODO GTK3: Second argument has to be of type gdk.EventButton instead of object.
     __gsignals__ = {
-        'clicked' : (GObject.SIGNAL_RUN_LAST, None, (str, object))
+        'clicked' : (gobject.SIGNAL_RUN_LAST, None, (str, object))
     }
 
     filter = 'dot'
 
     def __init__(self):
-        Gtk.DrawingArea.__init__(self)
+        gtk.DrawingArea.__init__(self)
 
         self.graph = Graph()
         self.openfilename = None
@@ -1537,13 +1537,13 @@ class DotWidget(Gtk.DrawingArea):
         self.set_can_focus(True)
 
         self.connect("draw", self.on_draw)
-        self.add_events(Gdk.EventMask.BUTTON_PRESS_MASK | Gdk.EventMask.BUTTON_RELEASE_MASK)
+        self.add_events(gdk.EventMask.BUTTON_PRESS_MASK | gdk.EventMask.BUTTON_RELEASE_MASK)
         self.connect("button-press-event", self.on_area_button_press)
         self.connect("button-release-event", self.on_area_button_release)
-        self.add_events(Gdk.EventMask.POINTER_MOTION_MASK | 
-                        Gdk.EventMask.POINTER_MOTION_HINT_MASK | 
-                        Gdk.EventMask.BUTTON_RELEASE_MASK | 
-                        Gdk.EventMask.SCROLL_MASK)
+        self.add_events(gdk.EventMask.POINTER_MOTION_MASK | 
+                        gdk.EventMask.POINTER_MOTION_HINT_MASK | 
+                        gdk.EventMask.BUTTON_RELEASE_MASK | 
+                        gdk.EventMask.SCROLL_MASK)
         self.connect("motion-notify-event", self.on_area_motion_notify)
         self.connect("scroll-event", self.on_area_scroll_event)
         self.connect("size-allocate", self.on_area_size_allocate)
@@ -1551,7 +1551,7 @@ class DotWidget(Gtk.DrawingArea):
         self.connect('key-press-event', self.on_key_press_event)
         self.last_mtime = None
 
-        GLib.timeout_add(1000, self.update)
+        glib.timeout_add(1000, self.update)
 
         self.x, self.y = 0.0, 0.0
         self.zoom_ratio = 1.0
@@ -1729,59 +1729,59 @@ class DotWidget(Gtk.DrawingArea):
     POS_INCREMENT = 100
 
     def on_key_press_event(self, widget, event):
-        if event.keyval == Gdk.KEY_Left:
+        if event.keyval == gdk.KEY_Left:
             self.x -= self.POS_INCREMENT/self.zoom_ratio
             self.queue_draw()
             return True
-        if event.keyval == Gdk.KEY_Right:
+        if event.keyval == gdk.KEY_Right:
             self.x += self.POS_INCREMENT/self.zoom_ratio
             self.queue_draw()
             return True
-        if event.keyval == Gdk.KEY_Up:
+        if event.keyval == gdk.KEY_Up:
             self.y -= self.POS_INCREMENT/self.zoom_ratio
             self.queue_draw()
             return True
-        if event.keyval == Gdk.KEY_Down:
+        if event.keyval == gdk.KEY_Down:
             self.y += self.POS_INCREMENT/self.zoom_ratio
             self.queue_draw()
             return True
-        if event.keyval in (Gdk.KEY_Page_Up,
-                            Gdk.KEY_plus,
-                            Gdk.KEY_equal,
-                            Gdk.KEY_KP_Add):
+        if event.keyval in (gdk.KEY_Page_Up,
+                            gdk.KEY_plus,
+                            gdk.KEY_equal,
+                            gdk.KEY_KP_Add):
             self.zoom_image(self.zoom_ratio * self.ZOOM_INCREMENT)
             self.queue_draw()
             return True
-        if event.keyval in (Gdk.KEY_Page_Down,
-                            Gdk.KEY_minus,
-                            Gdk.KEY_KP_Subtract):
+        if event.keyval in (gdk.KEY_Page_Down,
+                            gdk.KEY_minus,
+                            gdk.KEY_KP_Subtract):
             self.zoom_image(self.zoom_ratio / self.ZOOM_INCREMENT)
             self.queue_draw()
             return True
-        if event.keyval == Gdk.KEY_Escape:
+        if event.keyval == gdk.KEY_Escape:
             self.drag_action.abort()
             self.drag_action = NullAction(self)
             return True
-        if event.keyval == Gdk.KEY_r:
+        if event.keyval == gdk.KEY_r:
             self.reload()
             return True
-        if event.keyval == Gdk.KEY_f:
+        if event.keyval == gdk.KEY_f:
             win = widget.get_toplevel()
             find_toolitem = win.uimanager.get_widget('/ToolBar/Find')
             textentry = find_toolitem.get_children()
             win.set_focus(textentry[0])
             return True
-        if event.keyval == Gdk.KEY_q:
-            Gtk.main_quit()
+        if event.keyval == gdk.KEY_q:
+            gtk.main_quit()
             return True
-        if event.keyval == Gdk.KEY_p:
+        if event.keyval == gdk.KEY_p:
             self.on_print()
             return True
         return False
 
     print_settings = None
     def on_print(self, action=None):
-        print_op = Gtk.PrintOperation()
+        print_op = gtk.PrintOperation()
 
         if self.print_settings != None:
             print_op.set_print_settings(self.print_settings)
@@ -1789,8 +1789,8 @@ class DotWidget(Gtk.DrawingArea):
         print_op.connect("begin_print", self.begin_print)
         print_op.connect("draw_page", self.draw_page)
 
-        res = print_op.run(Gtk.PrintOperationAction.PRINT_DIALOG, self.get_toplevel())
-        if res == Gtk.PrintOperationResult.APPLY:
+        res = print_op.run(gtk.PrintOperationAction.PRINT_DIALOG, self.get_toplevel())
+        if res == gtk.PrintOperationResult.APPLY:
             self.print_settings = print_op.get_print_settings()
 
     def begin_print(self, operation, context):
@@ -1810,10 +1810,10 @@ class DotWidget(Gtk.DrawingArea):
     def get_drag_action(self, event):
         state = event.state
         if event.button in (1, 2): # left or middle button
-            modifiers = Gtk.accelerator_get_default_mod_mask()
-            if state & modifiers == Gdk.ModifierType.CONTROL_MASK:
+            modifiers = gtk.accelerator_get_default_mod_mask()
+            if state & modifiers == gdk.ModifierType.CONTROL_MASK:
                 return ZoomAction
-            elif state & modifiers == Gdk.ModifierType.SHIFT_MASK:
+            elif state & modifiers == gdk.ModifierType.SHIFT_MASK:
                 return ZoomAreaAction
             else:
                 return PanAction
@@ -1831,7 +1831,7 @@ class DotWidget(Gtk.DrawingArea):
         return False
 
     def is_click(self, event, click_fuzz=4, click_timeout=1.0):
-        assert event.type == Gdk.EventType.BUTTON_RELEASE
+        assert event.type == gdk.EventType.BUTTON_RELEASE
         if self.presstime is None:
             # got a button release without seeing the press?
             return False
@@ -1873,11 +1873,11 @@ class DotWidget(Gtk.DrawingArea):
         return False
 
     def on_area_scroll_event(self, area, event):
-        if event.direction == Gdk.ScrollDirection.UP:
+        if event.direction == gdk.ScrollDirection.UP:
             self.zoom_image(self.zoom_ratio * self.ZOOM_INCREMENT,
                             pos=(event.x, event.y))
             return True
-        if event.direction == Gdk.ScrollDirection.DOWN:
+        if event.direction == gdk.ScrollDirection.DOWN:
             self.zoom_image(self.zoom_ratio / self.ZOOM_INCREMENT,
                             pos=(event.x, event.y))
             return True
@@ -1918,14 +1918,14 @@ class DotWidget(Gtk.DrawingArea):
         return self.graph.get_jump(x, y)
 
 
-class FindMenuToolAction(Gtk.Action):
+class FindMenuToolAction(gtk.Action):
     __gtype_name__ = "FindMenuToolAction"
 
     def do_create_tool_item(self):
-        return Gtk.ToolItem()
+        return gtk.ToolItem()
 
 
-class DotWindow(Gtk.Window):
+class DotWindow(gtk.Window):
 
     ui = '''
     <ui>
@@ -1947,7 +1947,7 @@ class DotWindow(Gtk.Window):
     base_title = 'Dot Viewer'
 
     def __init__(self, widget=None):
-        Gtk.Window.__init__(self)
+        gtk.Window.__init__(self)
 
         self.graph = Graph()
 
@@ -1955,31 +1955,31 @@ class DotWindow(Gtk.Window):
 
         window.set_title(self.base_title)
         window.set_default_size(512, 512)
-        vbox = Gtk.VBox()
+        vbox = gtk.VBox()
         window.add(vbox)
 
         self.dotwidget = widget or DotWidget()
 
         # Create a UIManager instance
-        uimanager = self.uimanager = Gtk.UIManager()
+        uimanager = self.uimanager = gtk.UIManager()
 
         # Add the accelerator group to the toplevel window
         accelgroup = uimanager.get_accel_group()
         window.add_accel_group(accelgroup)
 
         # Create an ActionGroup
-        actiongroup = Gtk.ActionGroup('Actions')
+        actiongroup = gtk.ActionGroup('Actions')
         self.actiongroup = actiongroup
 
         # Create actions
         actiongroup.add_actions((
-            ('Open', Gtk.STOCK_OPEN, None, None, None, self.on_open),
-            ('Reload', Gtk.STOCK_REFRESH, None, None, None, self.on_reload),
-            ('Print', Gtk.STOCK_PRINT, None, None, "Prints the currently visible part of the graph", self.dotwidget.on_print),
-            ('ZoomIn', Gtk.STOCK_ZOOM_IN, None, None, None, self.dotwidget.on_zoom_in),
-            ('ZoomOut', Gtk.STOCK_ZOOM_OUT, None, None, None, self.dotwidget.on_zoom_out),
-            ('ZoomFit', Gtk.STOCK_ZOOM_FIT, None, None, None, self.dotwidget.on_zoom_fit),
-            ('Zoom100', Gtk.STOCK_ZOOM_100, None, None, None, self.dotwidget.on_zoom_100),
+            ('Open', gtk.STOCK_OPEN, None, None, None, self.on_open),
+            ('Reload', gtk.STOCK_REFRESH, None, None, None, self.on_reload),
+            ('Print', gtk.STOCK_PRINT, None, None, "Prints the currently visible part of the graph", self.dotwidget.on_print),
+            ('ZoomIn', gtk.STOCK_ZOOM_IN, None, None, None, self.dotwidget.on_zoom_in),
+            ('ZoomOut', gtk.STOCK_ZOOM_OUT, None, None, None, self.dotwidget.on_zoom_out),
+            ('ZoomFit', gtk.STOCK_ZOOM_FIT, None, None, None, self.dotwidget.on_zoom_fit),
+            ('Zoom100', gtk.STOCK_ZOOM_100, None, None, None, self.dotwidget.on_zoom_100),
         ))
 
         find_action = FindMenuToolAction("Find", None,
@@ -2004,8 +2004,8 @@ class DotWindow(Gtk.Window):
 
         # Add Find text search
         find_toolitem = uimanager.get_widget('/ToolBar/Find')
-        self.textentry = Gtk.Entry(max_length=20)
-        self.textentry.set_icon_from_stock(0, Gtk.STOCK_FIND)
+        self.textentry = gtk.Entry(max_length=20)
+        self.textentry.set_icon_from_stock(0, gtk.STOCK_FIND)
         find_toolitem.add(self.textentry)
 
         self.textentry.set_activates_default(True)
@@ -2073,23 +2073,23 @@ class DotWindow(Gtk.Window):
             self.error_dialog(str(ex))
 
     def on_open(self, action):
-        chooser = Gtk.FileChooserDialog(title="Open dot File",
-                                        action=Gtk.FileChooserAction.OPEN,
-                                        buttons=(Gtk.STOCK_CANCEL,
-                                                 Gtk.ResponseType.CANCEL,
-                                                 Gtk.STOCK_OPEN,
-                                                 Gtk.ResponseType.OK))
-        chooser.set_default_response(Gtk.ResponseType.OK)
+        chooser = gtk.FileChooserDialog(title="Open dot File",
+                                        action=gtk.FileChooserAction.OPEN,
+                                        buttons=(gtk.STOCK_CANCEL,
+                                                 gtk.ResponseType.CANCEL,
+                                                 gtk.STOCK_OPEN,
+                                                 gtk.ResponseType.OK))
+        chooser.set_default_response(gtk.ResponseType.OK)
         chooser.set_current_folder(self.last_open_dir)
-        filter = Gtk.FileFilter()
+        filter = gtk.FileFilter()
         filter.set_name("Graphviz dot files")
         filter.add_pattern("*.dot")
         chooser.add_filter(filter)
-        filter = Gtk.FileFilter()
+        filter = gtk.FileFilter()
         filter.set_name("All files")
         filter.add_pattern("*")
         chooser.add_filter(filter)
-        if chooser.run() == Gtk.ResponseType.OK:
+        if chooser.run() == gtk.ResponseType.OK:
             filename = chooser.get_filename()
             self.last_open_dir = chooser.get_current_folder()
             chooser.destroy()
@@ -2101,9 +2101,9 @@ class DotWindow(Gtk.Window):
         self.dotwidget.reload()
 
     def error_dialog(self, message):
-        dlg = Gtk.MessageDialog(type=Gtk.MessageType.ERROR,
+        dlg = gtk.MessageDialog(type=gtk.MessageType.ERROR,
                                 message_format=message,
-                                buttons=Gtk.ButtonsType.OK)
+                                buttons=gtk.ButtonsType.OK)
         dlg.set_title(self.base_title)
         dlg.run()
         dlg.destroy()
@@ -2150,14 +2150,14 @@ Shortcuts:
         parser.error('incorrect number of arguments')
 
     win = DotWindow()
-    win.connect('delete-event', Gtk.main_quit)
+    win.connect('delete-event', gtk.main_quit)
     win.set_filter(options.filter)
     if len(args) >= 1:
         if args[0] == '-':
             win.set_dotcode(sys.stdin.read())
         else:
             win.open_file(args[0])
-    Gtk.main()
+    gtk.main()
 
 
 # Apache-Style Software License for ColorBrewer software and ColorBrewer Color
