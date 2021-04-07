PORTNAME=	xprintidle
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Print X idle time

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase:ldflags xorg
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	lucianposton
USE_XORG=	x11 xext xscrnsaver

PLIST_FILES=	bin/xprintidle

.include <bsd.port.mk>
