PORTNAME=	bhotkeys
DISTVERSION=	1.3
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Grab-proof X11 plugin hotkey listener

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_XORG=	x11 xext xft xi xrandr xtst

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bhotkeys \
		${STAGEDIR}${PREFIX}/bin/bhotkeys-panel \
		${STAGEDIR}${PREFIX}/bin/bhotkeys-passwd

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
