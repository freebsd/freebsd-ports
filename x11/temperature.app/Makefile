# Created by: Per Otterstr=F6m <pelle@fukt.bth.se>
# $FreeBSD$

PORTNAME=	temperature.app
PORTVERSION=	1.5
CATEGORIES=	x11 windowmaker
MASTER_SITES=	https://www.dockapps.net/download/
DISTNAME=	Temperature.app-${PORTVERSION}

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Dockable WindowMaker applet which displays the local temperature

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	wget:ftp/wget

USES=		xorg
USE_XORG=	x11 xpm

PORTDOCS=	README
PLIST_FILES=	bin/Temperature.app

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Temperature.app ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
