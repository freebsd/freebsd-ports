PORTNAME=	bhotkeys-lock
DISTVERSION=	1.2
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Super+L lock-screen hotkey for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys \
		xlock:x11/xlockmore

USES=		localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_XORG=	x11 xext

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xlock-run

.include <bsd.port.mk>
