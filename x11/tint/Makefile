# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	0.12.9
CATEGORIES=	x11
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/tint/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libstartup-notification-1.so:x11/startup-notification

USES=		alias cmake gettext pkgconfig tar:xz
USE_GNOME=	glib20 gtk20 librsvg2 pango
USE_XORG=	x11 xcomposite xdamage xinerama xrandr xrender
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DMANDIR:PATH=man -DSYSCONFDIR:PATH=etc

OPTIONS_DEFINE=	EXAMPLES NLS
EXAMPLES_CMAKE_ON=	-DENABLE_EXAMPLES:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DENABLE_EXAMPLES:BOOL=OFF
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
