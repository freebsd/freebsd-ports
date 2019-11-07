# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	E-Run
PORTVERSION=	1.2
PORTREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	LOCAL/kbyanc

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Simple epplet for launching arbitrary programs

LIB_DEPENDS=	libepplet.so:x11-wm/epplets \
		libImlib2.so:graphics/imlib2

PLIST_FILES=	bin/E-Run.epplet

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gl
USE_GL=		gl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib -lepplet -lImlib2 -lGL

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME}.epplet \
		${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.epplet ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
