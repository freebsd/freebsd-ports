# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dashboard
PORTVERSION=	0.4.2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/xfdashboard/${PORTVERSION:R}/
PKGNAMEPREFIX=	xfce4-
DISTNAME=	xfdashboard-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GNOME shell like dashboard for the Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
	libclutter-1.0.so:graphics/clutter

GNU_CONFIGURE=	yes
USES=	pkgconfig libtool gmake perl5 gettext xfce tar:bzip2
USE_GNOME=	glib20 gtk30 libwnck3 intltool intlhack
USE_XFCE=	garcon
USE_XORG=	x11 xcomposite xdamage xinerama
USE_GL=	gl
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

post-patch:
# Decrease default value of desaturation factor (0.0 -> no desaturation)
# With some graphics cards, quick launch icons are totally black with
# default value
	${FIND} ${WRKSRC}/data/themes -type f -name 'effects.xml' \
		| ${XARGS} ${REINPLACE_CMD} -i "" 's|>1.0<|>0.45<|'

.include <bsd.port.mk>
