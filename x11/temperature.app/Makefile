PORTNAME=	temperature.app
DISTVERSION=	1.5
CATEGORIES=	x11 windowmaker
MASTER_SITES=	https://www.dockapps.net/download/
DISTNAME=	Temperature.app-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable WindowMaker applet which displays the local temperature
WWW=		https://www.dockapps.net/temperatureapp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	wget:ftp/wget

USES=		xorg
USE_XORG=	x11 xpm

PLIST_FILES=	bin/Temperature.app
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Temperature.app ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
