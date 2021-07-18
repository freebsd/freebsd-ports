PORTNAME=	srandrd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0-10
DISTVERSIONSUFFIX=	-g4e4b754
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple randr daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jceb
USE_XORG=	x11 xinerama xrandr

MAKE_ARGS=	DISTDIR=${STAGEDIR} \
		MANPREFIX=${STAGEDIR}${MAN1PREFIX}/share/man \
		PREFIX=${PREFIX}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
