PORTNAME=	framework-laptop12
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Framework Laptop-12 meta-port

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	framework-autorotate-hotkey>=0:x11/framework-autorotate-hotkey \
		framework-autorotate>=0:x11/framework-autorotate \
		framework-keyboard>=0:x11/framework-keyboard

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/man/man7/framework-laptop12.7.gz

.include <bsd.port.mk>
