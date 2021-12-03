BEMENU_LIB=	libbemenu.so.${VERSION}
wayland_PC=	epoll-shim pangocairo wayland-client xkbcommon
x11_PC=		pangocairo x11 xinerama
CFLAGS+=	-DBM_VERSION="\"${VERSION}\"" -DBM_PLUGIN_VERSION="\"${VERSION}-nogit\"" -DINSTALL_LIBDIR="\"${PREFIX}/lib\"" -std=c99 -fPIC -pthread -Ilib ${:!pkg-config --cflags ${RENDERERS:@r@${${r}_PC}@}!} ${RENDERERS:@r@${${r}_CFLAGS}@}
LDFLAGS+=	-Wl,--as-needed -Wl,--no-undefined -pthread

all: bemenu bemenu.1 bemenu-run bemenu.pc ${RENDERERS:@r@bemenu-renderer-${r}.so@}
${BEMENU_LIB}: lib/3rdparty/cdl.o lib/filter.o lib/item.o lib/library.o lib/list.o lib/menu.o lib/util.o
bemenu: client/bemenu.o client/common/common.o
bemenu-run: client/bemenu-run.o client/common/common.o
bemenu-renderer-curses.so: lib/renderers/curses/curses.o
wayland_OBJS=	lib/renderers/wayland/registry.o lib/renderers/wayland/wayland.o lib/renderers/wayland/window.o lib/renderers/wayland/wlr-layer-shell-unstable-v1.o lib/renderers/wayland/xdg-output-unstable-v1.o lib/renderers/wayland/xdg-shell.o
bemenu-renderer-wayland.so: ${wayland_OBJS}
${wayland_OBJS}: lib/renderers/wayland/wlr-layer-shell-unstable-v1.h lib/renderers/wayland/xdg-output-unstable-v1.h
bemenu-renderer-x11.so: lib/renderers/x11/window.o lib/renderers/x11/x11.o lib/renderers/x11/xkb_unicode.o

.SUFFIXES: .xml
.xml.c .xml.h:
	wayland-scanner ${"${@:M*.h}"!="":?client-header:private-code} < $< > $@

lib/renderers/wayland/xdg-shell.xml:
	cp "`pkg-config --variable=pkgdatadir wayland-protocols`/stable/${@:T:R}/${@:T}" $@

${BEMENU_LIB}:
	${CC} ${LDFLAGS} -fPIC -shared -Wl,-soname=${BEMENU_LIB:R:R} -o $@ $>

bemenu bemenu-run: ${BEMENU_LIB}
	${CC} ${LDFLAGS} -o $@ $>

bemenu-renderer-curses.so bemenu-renderer-wayland.so bemenu-renderer-x11.so: ${BEMENU_LIB}
	${CC} ${LDFLAGS} -fPIC -shared -o $@ $> ${${@:R:S,-, ,g:[3]}_LIBS} ${${@:R:S,-, ,g:[3]}_PC:D`pkg-config --libs ${${@:R:S,-, ,g:[3]}_PC}`} -lm

bemenu.pc: bemenu.pc.in
	sed -e 's,@INCLUDEDIR@,/include,' -e 's,@LIBDIR@,/lib,' -e 's,@PREFIX@,${PREFIX},' -e 's,@VERSION@,${VERSION},' $> > $@
	cat $@

bemenu.1: man/bemenu.1.in
	sed 's,@LIBDIR@,${PREFIX}/lib,' $> > $@

install:
	@mkdir -p ${DESTDIR}${PREFIX}/bin ${DESTDIR}${PREFIX}/include ${DESTDIR}${PREFIX}/lib ${DESTDIR}${PREFIX}/libdata/pkgconfig ${DESTDIR}${PREFIX}/share/man/man1
	${BSD_INSTALL_PROGRAM} bemenu bemenu-run ${DESTDIR}${PREFIX}/bin
	${BSD_INSTALL_DATA} lib/bemenu.h ${DESTDIR}${PREFIX}/include
	${BSD_INSTALL_LIB} ${BEMENU_LIB} ${DESTDIR}${PREFIX}/lib
	cd ${DESTDIR}${PREFIX}/lib && \
		ln -sf ${BEMENU_LIB} ${BEMENU_LIB:R:R} && \
		ln -sf ${BEMENU_LIB:R:R} ${BEMENU_LIB:R:R:R}
.if !empty(RENDERERS)
	@mkdir -p ${DESTDIR}${PREFIX}/lib/bemenu
	${BSD_INSTALL_LIB} bemenu-renderer-*.so ${DESTDIR}${PREFIX}/lib/bemenu
.endif
	${BSD_INSTALL_DATA} bemenu.pc ${DESTDIR}${PREFIX}/libdata/pkgconfig
	${BSD_INSTALL_MAN} bemenu.1 ${DESTDIR}${PREFIX}/share/man/man1
	ln ${DESTDIR}${PREFIX}/share/man/man1/bemenu.1 ${DESTDIR}${PREFIX}/share/man/man1/bemenu-run.1
