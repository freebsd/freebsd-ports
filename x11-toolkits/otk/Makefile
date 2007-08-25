# New ports collection makefile for:	otk
# Date created:		21 Jan 2006
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	otk
PORTVERSION=	0.61
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_lib_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Widget library based on OpenGL

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_GL=		glu gl
USE_LDCONFIG=	yes
USE_XORG=	xmu xext x11
WRKSRC=		${WRKDIR}/${PORTNAME}_lib
CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS=	-lGLU -lGL -lXmu -lXext -lX11 -L${LOCALBASE}/lib
PLIST_FILES=	lib/libotk.so lib/libotk.so.0 include/gadget_lib.h include/otk_lib.h

do-build:
	@cd ${WRKSRC}/&&\
		${CC} ${CFLAGS} ${LDFLAGS} -shared ./otk_lib.c -o libotk.so.0

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libotk.so.0 ${PREFIX}/lib/
	@${LN} -sf libotk.so.0 ${PREFIX}/lib/libotk.so
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/

.include <bsd.port.mk>
