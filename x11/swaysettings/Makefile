PORTNAME=	swaysettings
PORTVERSION=	s20220227
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI for setting Sway wallpaper, default apps, GTK themes, etc.

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libaccountsservice.so:sysutils/accountsservice \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 gettext gnome meson pkgconfig python:build shebangfix
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwaySettings
GH_TAGNAME=	709b482
SHEBANG_FILES=	build-aux/meson/postinstall.py

post-patch:
# Respect PREFIX for images and XKB layouts
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/Page/Input_Page.vala \
		${WRKSRC}/src/Pages/Background/Background_Page.vala \
		${WRKSRC}/src/Pages/Users/Users.vala

.include <bsd.port.mk>
