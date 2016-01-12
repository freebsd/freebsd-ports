# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	otk
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}_lib_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Widget library based on OpenGL

LICENSE=	LGPL20+

WRKSRC=		${WRKDIR}/${PORTNAME}_lib

USES=		tar:tgz
USE_XORG=	xmu xext x11
USE_GL=		glut glu gl
USE_LDCONFIG=	yes

PLIST_FILES=	include/gadget_lib.h include/otk_lib.h \
		lib/libotk.so lib/libotk.so.0

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-lGLU -lGL -lXmu -lXext -lX11 -L${LOCALBASE}/lib

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -shared otk_lib.c \
		-o libotk.so.0 ${LDFLAGS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/libotk.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libotk.so.0 ${STAGEDIR}${PREFIX}/lib/libotk.so
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
