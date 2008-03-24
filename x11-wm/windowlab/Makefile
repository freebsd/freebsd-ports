# New ports collection makefile for: windowlab
# Date created:        19 April 2003
# Whom:                Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
#
# $FreeBSD$
#

PORTNAME=	windowlab
PORTVERSION=	1.33
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	ppl@nbnet.nb.ca
COMMENT=	A small window manager for X11

MAN1=		windowlab.1x

USE_XORG=	x11 xext
USE_GMAKE=	yes

MAKE_ARGS=	MENURC=${PREFIX}/etc/windowlab/menurc CC="${CC}"

PLIST_FILES=	bin/windowlab etc/windowlab/menurc
PLIST_DIRS=	etc/windowlab

PORTDOCS=	CHANGELOG README

post-patch:
	@${REINPLACE_CMD} -e 's,^CC =,CC ?=,' \
		-e 's,/usr/X11R6,${X11BASE},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/windowlab ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/windowlab.1x ${MANPREFIX}/man/man1
	${MKDIR} ${PREFIX}/etc/windowlab
	${INSTALL_DATA} ${WRKSRC}/windowlab.menurc ${PREFIX}/etc/windowlab/menurc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
