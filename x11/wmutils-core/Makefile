# $FreeBSD$

PORTNAME=	wmutils-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Set of window manipulation tools

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-cursor.so:x11/xcb-util-cursor

USES=		localbase:ldflags xorg

USE_GITHUB=	yes
GH_ACCOUNT=	wmutils
GH_PROJECT=	core

USE_XORG=	xcb

CONFLICTS=	wtf  # games/wtf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
