diff --git a/meson.build b/meson.build
index b9de1119fae84730288d5766e4be1056adb6817f..fc5371bb7e73363b3a11bc5992d6846b93a3b3d5 100644
--- meson.build
+++ meson.build
@@ -96,6 +98,8 @@ endif
 
 ############ udev bits ############
 
+if false
+
 udev_dir = get_option('udev-dir')
 if udev_dir == ''
 	udev_dir = join_paths(get_option('prefix'), 'lib', 'udev')
@@ -173,6 +173,36 @@ litest_groups_rules_file = configure_file(input : 'udev/80-libinput-device-group
 	       install : false,
 	       configuration : litest_udev_rules_config)
 
+endif
+
+############ libepoll-shim (BSD) ############
+
+if cc.has_header_symbol('sys/epoll.h', 'epoll_create1', prefix : prefix)
+	# epoll is built-in (Linux, illumos)
+	dep_libepoll = declare_dependency()
+else
+	# epoll is implemented in userspace by libepoll-shim (FreeBSD)
+	dir_libepoll = get_option('epoll-dir')
+	if dir_libepoll == ''
+		dir_libepoll = get_option('prefix')
+	endif
+	includes_epoll = include_directories(join_paths(dir_libepoll, 'include/libepoll-shim'))
+	dep_libepoll = cc.find_library('epoll-shim', dirs : join_paths(dir_libepoll, 'lib'))
+	code = '''
+	#include <sys/epoll.h>
+	int main(void) { epoll_create1(0); }
+	'''
+	if not cc.links(code,
+		name : 'libepoll-shim check',
+		dependencies : [dep_libepoll, dep_rt],
+		include_directories : includes_epoll) # note: wants an include_directories object
+		error('No built-in epoll or libepoll-shim found.')
+	endif
+	dep_libepoll = declare_dependency(
+		include_directories : includes_epoll,
+		dependencies : [dep_libepoll, dep_rt])
+endif
+
 ############ libinput-util.a ############
 src_libinput_util = [
 		'src/libinput-util.c',
@@ -286,6 +314,7 @@ deps_libinput = [
 	dep_mtdev,
 	dep_udev,
 	dep_libevdev,
+	dep_libepoll,
 	dep_lm,
 	dep_rt,
 	dep_libwacom,
diff --git a/meson_options.txt b/meson_options.txt
index 280cf49f18710211c32c98580f7b2ecaa4b00a88..fd0149657e3635f768195485d38413a31d20e956 100644
--- meson_options.txt
+++ meson_options.txt
@@ -2,6 +2,10 @@ option('udev-dir',
        type: 'string',
        value: '',
        description: 'udev base directory [default=$prefix/lib/udev]')
+option('epoll-dir',
+       type: 'string',
+       value: '',
+       description: 'libepoll-shim base directory (for non-Linux OS) [default=$prefix]')
 option('libwacom',
        type: 'boolean',
        value: true,
