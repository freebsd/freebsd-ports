# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	bspwm
PORTVERSION=	0.9
CATEGORIES=	x11-wm

MAINTAINER=	antont@inbox.lv
COMMENT=	Tiling window manager based on binary space partitioning

LIB_DEPENDS=	libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm
RUN_DEPENDS=	sxhkd:${PORTSDIR}/x11/sxhkd

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
GH_COMMIT=	cbaf43e

USES=		gmake shebangfix
SHEBANG_FILES=	contrib/freedesktop/bspwm-session

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
