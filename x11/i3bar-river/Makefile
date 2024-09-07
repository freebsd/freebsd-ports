PORTNAME=	i3bar-river
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.10
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Port of i3bar for wlroots-based compositors
WWW=		https://github.com/MaxVerevkin/i3bar-river

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gnome
USE_GITHUB=	yes
USE_GNOME=	cairo pango
GH_ACCOUNT=	MaxVerevkin
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
