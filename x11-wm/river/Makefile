PORTNAME=	river
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.11
CATEGORIES=	x11-wm wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor
WWW=		https://isaacfreund.com/software/river/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		zig>=0.14.0:lang/zig
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	riverwm
GH_TUPLE=	ifreund:zig-pixman:v0.3.0:zig_pixman/../.cache/zig/p/pixman-0.3.0-LClMnz2VAAAs7QSCGwLimV5VUYx0JFnX5xWU6HwtMuDX \
		ifreund:zig-wayland:v0.3.0:zig_wayland/../.cache/zig/p/wayland-0.3.0-lQa1kjPIAQDmhGYpY-zxiRzQJFHQ2VqhJkQLbKKdt5wl \
		ifreund:zig-xkbcommon:v0.3.0:zig_xkbcommon/../.cache/zig/p/xkbcommon-0.3.0-VDqIe3K9AQB2fG5ZeRcMC9i7kfrp5m2rWgLrmdNn9azr \
		swaywm:zig-wlroots:v0.19.2:zig_wlroots/../.cache/zig/p/wlroots-0.19.2-jmOlcsnnAwDFAeOamkUaxyHNhKngH4Ai5rrLSVbqA8LW
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
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

.include <bsd.port.mk>
