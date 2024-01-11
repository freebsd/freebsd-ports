PORTNAME=	wmutils-opt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Optional addons to wmutils
WWW=		https://github.com/wmutils/opt

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase:ldflags xorg
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	wmutils
GH_PROJECT=	opt

MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
