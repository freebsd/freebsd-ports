# New ports collection makefile for:	BBDock
# Date created:				July 31, 2006
# Whom:					Francis Bacque <idroxid01@yahoo.fr>
#
# $FreeBSD$
#

PORTNAME=	bbdock
PORTVERSION=	0.2.9
CATEGORIES=	x11
MASTER_SITES=	http://bbdock.nethence.com/download/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An application launcher for Blackbox-like window manager

LICENSE=	BSD

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_XORG=	x11
PORTDOCS=	README

PLIST_FILES=	bin/bbdock

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
