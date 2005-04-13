# New ports collection makefile for: windowlab
# Date created:        19 April 2003
# Whom:                Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
#
# $FreeBSD$
#

PORTNAME=	windowlab
PORTVERSION=	1.26
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	ppl@nbnet.nb.ca
COMMENT=	A small window manager for X11

MAN1=		windowlab.1x

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAKE_ARGS+=	MENURC=${PREFIX}/etc/windowlab/menurc \
		CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/windowlab etc/windowlab/menurc
PLIST_DIRS=	etc/windowlab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/windowlab ${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/windowlab.1x ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/etc/windowlab/
	${INSTALL_DATA} ${WRKSRC}/menurc.sample ${PREFIX}/etc/windowlab/menurc

.include <bsd.port.mk>
