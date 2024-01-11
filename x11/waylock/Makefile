PORTNAME=	waylock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
CATEGORIES=	x11 wayland
MASTER_SITES=	https://codeberg.org/ifreund/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/ \
		https://codeberg.org/ifreund/zig-wayland/archive/65475ba${EXTRACT_SUFX}?dummy=/:zig_wayland \
		https://codeberg.org/ifreund/zig-xkbcommon/archive/7b188de${EXTRACT_SUFX}?dummy=/:zig_xkbcommon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		zig-wayland-65475ba${EXTRACT_SUFX}:zig_wayland \
		zig-xkbcommon-7b188de${EXTRACT_SUFX}:zig_xkbcommon

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small screenlocker for Wayland compositors
WWW=		https://codeberg.org/ifreund/waylock

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		zig>=0.11.0:lang/zig
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}
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

post-extract:
	@${MV} ${WRKDIR}/zig-* ${WRKSRC}/deps

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

.include <bsd.port.mk>
