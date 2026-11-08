PORTNAME=	bhotkeys-dwm
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Chords for the dwm window manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	SUPERASMODKEY

SUPERASMODKEY_DESC=		Use Super instead of Alt for the dwm mod key
SUPERASMODKEY_EXTRA_PATCHES=	${PATCHDIR}/superasmodkey-patch

.include <bsd.port.mk>
