# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	bricons
PORTVERSION=	3.0
DISTVERSIONPREFIX=	athena-
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/../R5contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick start up utility for applications on an X display

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake perl5 tar:Z xorg
USE_PERL5=	build
USE_XORG=	xaw

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Xbricons
	@${REINPLACE_CMD} -e \
		's|^unsigned int argc|int argc|' ${WRKSRC}/main.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xbricons ${STAGEDIR}${PREFIX}/lib/X11/app-defaults
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/X11/bitmaps
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${STAGEDIR}${PREFIX}/include/X11/bitmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/X11/pixmaps
	${INSTALL_DATA} ${WRKSRC}/*.xpm ${STAGEDIR}${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
