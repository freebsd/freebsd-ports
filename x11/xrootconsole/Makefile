# New ports collection makefile for:	xrootconsole
# Date created:			12 July 2002
# Whom:				incabulos@mac.com
#
# $FreeBSD$
#

PORTNAME=	xrootconsole
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://de-fac.to/bob/xrootconsole/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	incabulos@mac.com
COMMENT=	Writes any log live onto the background

USE_REINPLACE=	yes
USE_XLIB=	yes
CFLAGS+=	-I${X11BASE}/include
USE_GMAKE=	yes

MAN1=		xrootconsole.1
PLIST_FILES=	bin/xrootconsole

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
		-e "s|CFLAGS = -O2|CFLAGS +=|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrootconsole ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrootconsole.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
