# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	simdock
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and customizable dockbar

OPTIONS_DEFINE=	DOCS

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		desktop-file-utils pathfix pkgconfig
USE_GNOME=	gnomeprefix gconf2 libwnck
USE_WX=		2.8
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute

WRKSRC=		${WRKDIR}/trunk

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/main.h
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/share/firefox|${PREFIX}/lib/firefox|g' \
		${WRKSRC}/src/main.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
