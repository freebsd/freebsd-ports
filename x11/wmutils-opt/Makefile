# $FreeBSD$

PORTNAME=	wmutils-opt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Optional addons to wmutils

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase:ldflags xorg
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	wmutils
GH_PROJECT=	opt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
