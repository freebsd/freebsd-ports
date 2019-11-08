# $FreeBSD$

PORTNAME=	controllermap
PORTVERSION=	2.0.10
CATEGORIES=	x11
MASTER_SITES=	https://www.libsdl.org/release/
DISTNAME=	SDL2-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Game controller mapping generator

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sdl
USE_SDL=	sdl2
WRKSRC_SUBDIR=	test
CFLAGS+=	`sdl2-config --cflags`
LIBS+=		`sdl2-config --libs`
MAKEFILE=	/dev/null
MAKE_ENV=	LDLIBS="${LIBS}"
ALL_TARGET=	${PORTNAME} testgamecontroller testjoystick
PLIST_FILES=	${ALL_TARGET:S,^,bin/,}
PORTDATA=	${PORTNAME}.bmp axis.bmp button.bmp

post-patch:
	@${REINPLACE_CMD} '/bmp/s,","${DATADIR}/,' \
		${ALL_TARGET:S,^,${WRKSRC}/,:S,$,.c,}

do-install:
	${INSTALL_PROGRAM} ${ALL_TARGET:S,^,${WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
