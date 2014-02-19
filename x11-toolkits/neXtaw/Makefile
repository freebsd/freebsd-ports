# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	neXtaw
PORTVERSION=	0.15.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Athena Widgets with N*XTSTEP appearance

USE_AUTOTOOLS=	libtool
USE_XORG=	xmu x11 xext
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|version-info.*$$|version-info 8:0:0|g' \
		${WRKSRC}/X11/neXtaw/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
