PORTNAME=	river
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor
WWW=		https://isaacfreund.com/software/river/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		zig>=0.13.0:lang/zig
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.18.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	riverwm
GH_TUPLE=	ifreund:zig-pixman:v0.2.0:zig_pixman/../.cache/zig/p/12209db20ce873af176138b76632931def33a10539387cba745db72933c43d274d56 \
		ifreund:zig-wayland:v0.2.0:zig_wayland/../.cache/zig/p/1220687c8c47a48ba285d26a05600f8700d37fc637e223ced3aa8324f3650bf52242 \
		ifreund:zig-xkbcommon:v0.2.0:zig_xkbcommon/../.cache/zig/p/1220c90b2228d65fd8427a837d31b0add83e9fade1dcfa539bb56fd06f1f8461605f \
		swaywm:zig-wlroots:v0.18.1:zig_wlroots/../.cache/zig/p/122083317b028705b5d27be12976feebf17066a4e51802b3b5e9f970bec580e433e1
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
