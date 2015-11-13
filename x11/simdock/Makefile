# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	simdock
PORTVERSION=	1.2
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and customizable dockbar

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		desktop-file-utils pathfix pkgconfig
USE_GNOME=	gnomeprefix gconf2 libwnck
USE_WX=		2.8
USE_XORG=	x11
WX_CONF_ARGS=	absolute

WRKSRC=		${WRKDIR}/trunk

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/main.h
	@${REINPLACE_CMD} '/^simdock_LDADD =/s/$$/ -lX11/' \
		${WRKSRC}/Makefile.in ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/share/firefox|${PREFIX}/lib/firefox|g' \
		${WRKSRC}/src/main.cc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
