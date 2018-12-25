# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	16.6
CATEGORIES=	x11

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libImlib2.so:graphics/imlib2 \
		libstartup-notification-1.so:x11/startup-notification

USES=		alias cmake desktop-file-utils gettext-runtime \
		pkgconfig shared-mime-info
USE_GNOME=	cairo glib20 gtk20 librsvg2 pango
USE_XORG=	x11 xcomposite xdamage xext xfixes xinerama xrandr xrender
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DMANDIR:PATH=man -DSYSCONFDIR:PATH=etc

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Gettext

USE_GITLAB=	yes
GL_ACCOUNT=	o9000
GL_COMMIT= 1054aac7ca9f93aa140a5a7606b75599521fed5b

.include <bsd.port.mk>
