PORTNAME=	wlr-which-key
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Keymap manager for wlroots-based compositors
WWW=		https://github.com/MaxVerevkin/wlr-which-key

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cargo gnome
USE_GITHUB=	yes
GH_ACCOUNT=	MaxVerevkin
USE_GNOME=	cairo pango

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
