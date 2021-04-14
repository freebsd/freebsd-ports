PORTNAME=	xclickroot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Run a command every time a given mouse button is pressed on the root window

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/README

USES=		localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	phillbush
USE_XORG=	x11

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS} -lX11" \
		LIBS="${LIBS}" \
		PREFIX="${PREFIX}"

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
