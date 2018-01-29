# $FreeBSD$

PORTNAME=	wmutils-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
CATEGORIES=	x11

MAINTAINER=	dg@syrec.org
COMMENT=	Set of window manipulation tools

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		localbase:ldflags
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	wmutils
GH_PROJECT=	core

CONFLICTS=	wtf  # games/wtf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
