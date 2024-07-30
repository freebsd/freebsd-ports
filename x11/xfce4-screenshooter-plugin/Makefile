PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.11.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DISTNAME=	xfce4-screenshooter-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application and panel plugin to take screenshots
WWW=		https://goodies.xfce.org/projects/applications/xfce4-screenshooter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_CSTD=	c99
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libexo libmenu panel xfconf
USE_XORG=	ice sm x11 xfixes xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-wayland
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS IMGUR
OPTIONS_DEFAULT=	IMGUR
OPTIONS_SUB=		yes

IMGUR_DESC=		Install imgur image upload custom action

IMGUR_RUN_DEPENDS=	curl:ftp/curl \
			jq:textproc/jq \
			xclip:x11/xclip \
			zenity:x11/zenity

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch-IMGUR-off:
	@${REINPLACE_CMD} '/imgur_custom_action_added = xfconf_channel_get_bool/s/FALSE/TRUE/' \
		${WRKSRC}/lib/screenshooter-custom-actions.c

.include <bsd.port.mk>
