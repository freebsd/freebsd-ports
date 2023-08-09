PORTNAME=	wlinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	g20171028
CATEGORIES=	x11-toolkits

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Window information utility for Wayland
WWW=		https://github.com/eklitzke/wlinfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		autoreconf localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	eklitzke
GH_TAGNAME=	c394f92
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wlinfo

.include <bsd.port.mk>
