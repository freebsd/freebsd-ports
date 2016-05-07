# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	bspwm
PORTVERSION=	0.9.1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling window manager based on binary space partitioning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
RUN_DEPENDS=	sxhkd:x11/sxhkd

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

USES=		gmake pkgconfig

SUB_FILES=	pkg-message

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.mk>
