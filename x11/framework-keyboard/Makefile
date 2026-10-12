PORTNAME=	framework-keyboard
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Framework laptop Fn-row hotkey meta-port

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys-airplane>=1.1:x11/bhotkeys-airplane \
		bhotkeys-audio>=1.1:x11/bhotkeys-audio \
		bhotkeys-brightness>=1.0:x11/bhotkeys-brightness \
		bhotkeys-media>=1.0:x11/bhotkeys-media \
		bhotkeys-mirror>=1.0:x11/bhotkeys-mirror \
		bhotkeys-screenshot>=1.1:x11/bhotkeys-screenshot \
		bhotkeys>=1.3:x11/bhotkeys \
		bosd>=10.5:x11/bosd

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/man/man7/framework-keyboard.7.gz

.include <bsd.port.mk>
