# Ports collection Makefile for:	fluxconf
# Date created:				29/04/2002
# Whom:					hendrik@scholz.net
#
# $FreeBSD$
#

PORTNAME=	fluxconf
PORTVERSION=	0.9.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configuration program for the fluxbox window manager

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PORTDOCS=	fluxconf.png fluxkeys.png fluxmenu.png index.html

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
