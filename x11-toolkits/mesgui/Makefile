# ex:ts=8
# Ports collection makefile for:	mesgui
# Date created:			Jul 24, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	mesgui
PORTVERSION=	1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12 \
		freetype:${PORTSDIR}/print/freetype2

USE_REINPLACE=	yes
USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	OPT="-I${LOCALBASE}/include -I${X11BASE}/include"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s,OPT =,OPT+=,g" \
		-e "s|-I/usr|-I${LOCALBASE}|g" -e "s,SDL,SDL11,g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/mesgui.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libmesgui.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libmesgui.so.1.0 ${PREFIX}/lib/libmesgui.so.1
	${LN} -fs ${PREFIX}/lib/libmesgui.so.1 ${PREFIX}/lib/libmesgui.so

.include <bsd.port.mk>
