# Created by: ijliao
# $FreeBSD$

PORTNAME=	xvattr
PORTVERSION=	1.3
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://xvattr.sourcearchive.com/downloads/1.3/
DISTFILES=	xvattr_1.3.orig.tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Getting and setting Xv attributes

BROKEN=		unfetchable

USES=		gnome pkgconfig xorg
USE_GNOME=	gtk20
USE_XORG=	x11 xv

PLIST_FILES=	bin/${PORTNAME} bin/g${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

post-extract:
	@${RM} ${WRKSRC}/getopt.h

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} \
		`pkg-config --cflags --libs xv x11`
	cd ${WRKSRC} && ${CC} ${CFLAGS} g${PORTNAME}.c -o g${PORTNAME} \
		`pkg-config --cflags --libs gtk+-2.0 xv x11`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/g${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
