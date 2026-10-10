PORTNAME=	bhotkeys-airplane
DISTVERSION=	1.2
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Fn airplane-mode hotkeys for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys \
		bosd:x11/bosd

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
GROUPS=		airplane_radiosd

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/airplane-radiosd

.include <bsd.port.mk>
