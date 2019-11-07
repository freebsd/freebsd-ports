# Created by: ijliao
# $FreeBSD$

PORTNAME=	wmapp
PORTVERSION=	0.0.4.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits windowmaker
MASTER_SITES=	http://starplot.org/wmapp/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DockApp Graphics Library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg
USE_XORG=	x11 xpm
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|export |#export |g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|g" ${WRKSRC}/xwrapper.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/wmapp
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/wmapp
	${INSTALL_DATA} ${WRKSRC}/libwmapp.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FAQ.txt README Widgets.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
