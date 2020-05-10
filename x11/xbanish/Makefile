# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	xbanish
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
CATEGORIES=	x11

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Banish the mouse cursor when typing

LICENSE=	BSD3CLAUSE

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jcs
USE_XORG=	x11 xfixes xi xt

MAKE_ARGS=	X11BASE="${LOCALBASE}"

PLIST_FILES=	bin/xbanish \
		man/man1/xbanish.1.gz

.include <bsd.port.mk>
