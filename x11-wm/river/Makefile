PORTNAME=	river
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor
WWW=		https://github.com/riverwm/river

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		wlroots>=0.16.0:x11-toolkits/wlroots \
		zig>=0.10.0:lang/zig
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	riverwm
GH_TUPLE=	ifreund:zig-pixman:4a49ba1:zig_pixman/deps/zig-pixman \
		ifreund:zig-wayland:ace6aee:zig_wayland/deps/zig-wayland \
		ifreund:zig-xkbcommon:bfd1f97:zig_xkbcommon/deps/zig-xkbcommon \
		swaywm:zig-wlroots:04bcd67:zig_wlroots/deps/zig-wlroots
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Drelease-fast} \
		${WITH_PIE:D-Dpie} \
		${STRIP:C/.+/-Dstrip/} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}ctl \
		bin/${PORTNAME}tile \
		libdata/pkgconfig/${PORTNAME}-protocols.pc \
		share/${PORTNAME}-protocols/${PORTNAME}-layout-v3.xml \
		share/bash-completion/completions/${PORTNAME}ctl \
		share/fish/vendor_completions.d/${PORTNAME}ctl.fish \
		share/zsh/site-functions/_${PORTNAME}ctl \
		${NULL}

# https://github.com/ziglang/zig/issues/12170 (pixman)
MAKE_ENV+=	PKG_CONFIG_SYSTEM_LIBRARY_PATH="${LOCALBASE}/lib"

OPTIONS_DEFINE=	MANPAGES X11
OPTIONS_DEFAULT=MANPAGES X11

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_CONFIGURE_ON=	-Dman-pages=true
MANPAGES_CONFIGURE_OFF=	-Dman-pages=false
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man1/${PORTNAME}ctl.1.gz \
			share/man/man1/${PORTNAME}tile.1.gz \
			${NULL}

X11_CONFIGURE_ON=	-Dxwayland=true
X11_CONFIGURE_OFF=	-Dxwayland=false

post-patch:
# Respect devel/pkgconf default search
	@${REINPLACE_CMD} -e '/pkgconfig/s/share/libdata/' \
		${WRKSRC}/build.zig
# Respect PREFIX in path references
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/doc/${PORTNAME}ctl.1.scd

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include "${.CURDIR:H:H}/x11-toolkits/wlroots016/override.mk"
.include <bsd.port.mk>
