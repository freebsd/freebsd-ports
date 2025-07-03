PORTNAME=	wmfocus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	14
CATEGORIES=	x11

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Visually focus windows by label
WWW=		https://github.com/svenstaro/wmfocus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo gnome xorg
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro
USE_GNOME=	cairo
USE_XORG=	xcb

CARGO_FEATURES=	i3

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
