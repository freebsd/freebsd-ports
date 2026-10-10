PORTNAME=	bhotkeys-lid-state
DISTVERSION=	1.3.1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Super+Z lid stay-awake hotkey for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys \
		bosd:x11/bosd

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
GROUPS=		lid_switchd

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/lid-switchd

.include <bsd.port.mk>
