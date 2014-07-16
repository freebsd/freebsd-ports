# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	neXtaw
PORTVERSION=	0.15.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Athena Widgets with N*XTSTEP appearance

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		libtool
USE_LDCONFIG=	yes
USE_XORG=	xmu x11 xext

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
