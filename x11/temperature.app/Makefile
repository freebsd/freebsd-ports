# Created by: Per Otterstr=F6m <pelle@fukt.bth.se>
# $FreeBSD$

PORTNAME=	temperature.app
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.fukt.bsnet.se/~per/temperature/
DISTNAME=	Temperature.app-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable WindowMaker applet which displays the local temperature

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xpm

PORTDOCS=	README
PLIST_FILES=	bin/Temperature.app

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} Temperature.app \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
