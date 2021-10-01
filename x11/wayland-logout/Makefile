PORTNAME=	wayland-logout
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple logout on Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	soreau
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.options.mk>

# Cannot use C implementation without cr_pid
.if make(makesum)
DISTFILES=	${DISTNAME:S/${DISTVERSION}/1.3/}${EXTRACT_SUFX}
.elif ${OPSYS} != FreeBSD || ${OSVERSION} < 1202506
DISTVERSION=	1.3
NO_ARCH=	yes
MESON_ARGS+=	-Dimplementation=shell
.endif

.include <bsd.port.mk>
