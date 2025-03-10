PORTNAME=	waylock
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small screenlocker for Wayland compositors
WWW=		https://codeberg.org/ifreund/waylock

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		zig>=0.13.0:lang/zig
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ifreund
GH_TUPLE=	ifreund:zig-wayland:v0.2.0:zig_wayland/../.cache/zig/p/1220687c8c47a48ba285d26a05600f8700d37fc637e223ced3aa8324f3650bf52242 \
		ifreund:zig-xkbcommon:v0.2.0:zig_xkbcommon/../.cache/zig/p/1220c90b2228d65fd8427a837d31b0add83e9fade1dcfa539bb56fd06f1f8461605f
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		${WITH_PIE:D-Dpie} \
		${STRIP:C/.+/-Dstrip/} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_CONFIGURE_ON=	-Dman-pages=true
MANPAGES_CONFIGURE_OFF=	-Dman-pages=false
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

.include <bsd.port.mk>
