PORTNAME=	wdisplays
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI display configurator for wlroots compositors

LICENSE=	CC-BY-SA-4.0 CC0-1.0 GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSES/CC-BY-SA-4.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	artizirk
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/network.cycles.${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg

.include <bsd.port.mk>
