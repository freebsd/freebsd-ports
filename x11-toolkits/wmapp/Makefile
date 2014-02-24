# Created by: ijliao
# $FreeBSD$

PORTNAME=	wmapp
PORTVERSION=	0.0.4.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits windowmaker
MASTER_SITES=	http://starplot.org/wmapp/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DockApp Graphics Library

OPTIONS_DEFINE=	DOCS

USES=		gmake
USE_XORG=	x11 xpm
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s|export |#export |g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|g" ${WRKSRC}/xwrapper.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/wmapp
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/wmapp
	${INSTALL_DATA} ${WRKSRC}/libwmapp.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FAQ.txt README Widgets.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
