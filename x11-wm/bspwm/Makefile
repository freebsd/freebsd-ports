# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	bspwm
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	x11-wm

MAINTAINER=	antont@inbox.lv
COMMENT=	Tiling window manager based on binary space partitioning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm
RUN_DEPENDS=	sxhkd:${PORTSDIR}/x11/sxhkd

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

USES=		gmake shebangfix
SHEBANG_FILES=	contrib/freedesktop/bspwm-session

MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.mk>
