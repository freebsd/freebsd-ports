# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	simdock
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast and customizable dockbar

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix gconf2 libwnck
USE_WX=		2.8
WX_CONF_ARGS=	absolute

WRKSRC=		${WRKDIR}/trunk

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL LICENSE NEWS README TODO

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/main.h
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/share/firefox|${PREFIX}/lib/firefox|g' \
		${WRKSRC}/src/main.cc

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
