# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dashboard
PORTVERSION=	0.6.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/xfdashboard/${PORTVERSION:R}/
PKGNAMEPREFIX=	xfce4-
DISTNAME=	xfdashboard-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GNOME shell like dashboard for the Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
	libdbus-1.so:devel/dbus \
	libjson-glib-1.0.so:devel/json-glib \
	libcogl.so:graphics/cogl \
	libclutter-1.0.so:graphics/clutter

GNU_CONFIGURE=	yes
USES=	gettext-tools gmake localbase libtool pathfix perl5 pkgconfig \
	tar:bzip2 xfce:gtk3
USE_GNOME=	glib20 gtk30 libwnck3 cairo intltool intlhack
USE_XFCE=	garcon
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xinerama xrandr
USE_GL=	egl gl
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
# Decrease default value of desaturation factor (0.0 -> no desaturation)
# With some graphics cards, quick launch icons are totally black with
# default value
	${FIND} ${WRKSRC}/data/themes -type f -name 'effects.xml' \
		| ${XARGS} ${REINPLACE_CMD} -i "" 's|>1.0<|>0.45<|'

.include <bsd.port.mk>
