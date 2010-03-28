# ex:ts=8
# Ports collection makefile for:	xvattr
# Date created:			Jan 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xvattr
PORTVERSION=	1.3
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Getting and setting Xv attributes

OPTIONS=	GTK1 "GTK1 support (Default is GTK2)" off

USE_XORG=	x11 xv
WANT_GNOME=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} bin/g${PORTNAME}

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

.include <bsd.port.pre.mk>

.if defined(WITH_GTK1)
USE_GNOME+=	gtk12
GTK_PC=		gtk+
.else
USE_GNOME+=	gtk20
GTK_PC=		gtk+-2.0
.endif

post-extract:
	@${RM} -f ${WRKSRC}/getopt.h

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} \
		`pkg-config --cflags --libs xv`
	cd ${WRKSRC} && ${CC} ${CFLAGS} g${PORTNAME}.c -o g${PORTNAME} \
		`pkg-config --cflags --libs ${GTK_PC} xv`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/g${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
