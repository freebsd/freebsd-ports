# ex:ts=8
# Ports collection makefile for:	xsel
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xsel
PORTVERSION=	0.04.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.niksula.cs.hut.fi/~vherva/xsel/
DISTFILES=	xsel.c xsel.man

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access X selection from command line

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
USE_XLIB=	yes
USE_GNOME=	gtk12
NO_WRKSUBDIR=	yes
CFLAGS+=	`${GTK_CONFIG} --cflags`
LDFLAGS+=	`${GTK_CONFIG} --libs` -lXt -lXaw

MAN1=		xsel.1
PLIST_FILES=	bin/xsel

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} xsel.c -o xsel ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xsel.man ${MAN1PREFIX}/man/man1/xsel.1

.include <bsd.port.mk>
