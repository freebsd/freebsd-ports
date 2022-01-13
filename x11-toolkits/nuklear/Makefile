PORTNAME=	nuklear
DISTVERSION=	4.9.5
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal-state, immediate-mode graphical user interface toolkit

LICENSE=	MIT PD
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	Immediate-Mode-UI
GH_PROJECT=	Nuklear

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nuklear.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/nuklear.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
