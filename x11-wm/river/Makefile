PORTNAME=	river
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor
WWW=		https://isaacfreund.com/software/river/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		zig>=0.12.0:lang/zig
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots017 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	riverwm
GH_TUPLE=	ifreund:zig-pixman:v0.1.0:zig_pixman/../.cache/zig/p/122014eeb4600a059bdcfe1c864862f17e6d5e4237e3bb7d6818f2a5583f6f4eb843 \
		ifreund:zig-wayland:v0.1.0:zig_wayland/../.cache/zig/p/1220b0f8f822c1625af7aae4cb3ab2c4ec1a4c0e99ef32867b2a8d88bb070b3e7f6d \
		ifreund:zig-xkbcommon:v0.1.0:zig_xkbcommon/../.cache/zig/p/1220840390382c88caf9b0887f6cebbba3a7d05960b8b2ee6d80567b2950b71e5017 \
		swaywm:zig-wlroots:v0.17.0:zig_wlroots/../.cache/zig/p/1220714d1cc39c3abb1d9c22a0b838d847ead099cb7d9931821490483f30c022e827
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
