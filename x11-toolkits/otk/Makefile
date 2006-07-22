# New ports collection makefile for:	otk
# Date created:		21 Jan 2006
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	otk
PORTVERSION=	0.53
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_lib_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Widget library based on OpenGL

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_GL=		yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}_lib

PLIST_FILES=	lib/libotk.a include/gadget_lib.h include/otk_lib.h

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -I${X11BASE}/include -c ./otk_lib.c && \
		ar q ./libotk.a ./otk_lib.o && ranlib ./libotk.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/libotk.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include

.include <bsd.port.mk>
