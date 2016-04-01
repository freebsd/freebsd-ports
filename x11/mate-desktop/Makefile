# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-desktop
PORTVERSION=	1.12.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for MATE

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake libtool pathfix pkgconfig \
		python shebangfix tar:xz
USE_XORG=	x11 xrandr
USE_GNOME=	dconf gdkpixbuf2 gtk20 intlhack introspection:build
SHEBANG_FILES=	tools/mpaste
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-gtk-doc \
		--disable-user-guide \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.accessibility-keyboard.gschema.xml \
		org.mate.accessibility-startup.gschema.xml \
		org.mate.applications-at-mobility.gschema.xml \
		org.mate.applications-at-visual.gschema.xml \
		org.mate.applications-browser.gschema.xml \
		org.mate.applications-office.gschema.xml \
		org.mate.applications-terminal.gschema.xml \
		org.mate.background.gschema.xml \
		org.mate.file-views.gschema.xml \
		org.mate.interface.gschema.xml \
		org.mate.lockdown.gschema.xml \
		org.mate.peripherals-keyboard.gschema.xml \
		org.mate.peripherals-mouse.gschema.xml \
		org.mate.sound.gschema.xml \
		org.mate.thumbnail-cache.gschema.xml \
		org.mate.thumbnailers.gschema.xml \
		org.mate.typing-break.gschema.xml \
		org.mate.debug.gschema.xml

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			PASTE
OPTIONS_DEFAULT=		PASTE
PASTE_CONFIGURE_ENABLE=		mpaste
PASTE_DESC=			Build the mate paste tool

.include <bsd.port.mk>
