# Created by: Lin, Cheng-Tao <b89605222@ntu.edu.tw>
# $FreeBSD$

PORTNAME=	lxpanel
PORTVERSION=	0.9.3
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXPanel%20%28desktop%20panel%29/LXPanel%20${PORTVERSION:R}.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight X11 desktop panel

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libkeybinder.so:x11/keybinder \
		libfm-gtk.so:x11/libfm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/etc/xdg/menus/lxde-applications.menu:x11/lxmenu-data

USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2 libwnck intltool
USE_XORG=	x11
USES=		gmake libtool localbase pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugins="${LXPANEL_PLUGINS}"
INSTALL_TARGET=	install-strip

# Panel plugins
LXPANEL_PLUGINS=	"-netstat,-netstatus,deskno,-batt,kbled,xkb,-thermal,cpu,cpufreq,monitors,-indicator"

OPTIONS_SINGLE=	SOUND
OPTIONS_SINGLE_SOUND=	ALSA OSS
OPTIONS_DEFINE=	NLS WEATHER
OPTIONS_DEFAULT=	OSS WEATHER
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
ALSA_VARS=		lxpanel_plugins+=",-volume,volumealsa"
OSS_VARS=		lxpanel_plugins+=",volume,-volumealsa"
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
WEATHER_USE=		gnome=libxml2
WEATHER_VARS=		lxpanel_plugins+=",weather"
WEATHER_VARS_OFF=	lxpanel_plugins+=",-weather"
WEATHER_DESC=		Weather plugin

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
