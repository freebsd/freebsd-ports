# New ports collection makefile for:	xrootconsole
# Date created:			12 July 2002
# Whom:				incabulos@mac.com
#
# $FreeBSD$
#

PORTNAME=	xrootconsole
PORTVERSION=	0.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Writes any log live onto the background

USE_XLIB=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=		xrootconsole.1
PLIST_FILES=	bin/xrootconsole

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC ?=|g ; \
		 s|^CFLAGS = -O2|CFLAGS +=|g ; \
		 s|/usr/X11R6|$${X11BASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrootconsole ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrootconsole.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
