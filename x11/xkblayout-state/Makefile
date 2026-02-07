PORTNAME=	xkblayout-state
PORTVERSION=	g20211106
CATEGORIES=	x11

MAINTAINER=	timp87@gmail.com
COMMENT=	Small program to get/set the current XKB layout
WWW=		https://github.com/nonpop/xkblayout-state

LICENSE=	GPLv2+

USES=		gmake localbase:ldflags xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	nonpop
GH_TAGNAME=	f311779

PORTSCOUT=	skipv:v1,v1b

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
