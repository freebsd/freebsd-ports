# Created by: oleg@bsdpower.com
# $FreeBSD$

PORTNAME=	setlayout
DISTVERSION=	20080210
CATEGORIES=	x11
MASTER_SITES=	http://icculus.org/openbox/tools/
DISTFILES=	${PORTNAME}.c
EXTRACT_ONLY=	#none

MAINTAINER=	oleg@bsdpower.com
COMMENT=	Arrange desktops in an MxN grid layout

USES=		pkgconfig xorg
USE_XORG=	x11
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} `pkg-config --cflags --libs x11` ${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
