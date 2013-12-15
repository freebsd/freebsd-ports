# Created by: trevor
# $FreeBSD$

PORTNAME=	vdesk
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line utility for setting up and using virtual desktops

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README
PLIST_DIRS=	share/doc/vdesk
PLIST_FILES=	bin/vdesk

USE_AUTOTOOLS=	autoconf
USE_XORG=	x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vdesk ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
