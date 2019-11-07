# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-desktop
PORTVERSION=	1.22.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for MATE

LICENSE=	GPLv2 GFDL LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig python shebangfix tar:xz xorg
USE_XORG=	x11 xrandr
USE_GNOME=	cairo dconf gdkpixbuf2 gnomeprefix gtk30 \
		intltool introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.mate.accessibility-keyboard.gschema.xml \
		org.mate.accessibility-startup.gschema.xml \
		org.mate.applications-at-mobility.gschema.xml \
		org.mate.applications-at-visual.gschema.xml \
		org.mate.applications-browser.gschema.xml \
		org.mate.applications-calculator.gschema.xml \
		org.mate.applications-office.gschema.xml \
		org.mate.applications-terminal.gschema.xml \
		org.mate.background.gschema.xml \
		org.mate.debug.gschema.xml \
		org.mate.file-views.gschema.xml \
		org.mate.interface.gschema.xml \
		org.mate.lockdown.gschema.xml \
		org.mate.peripherals-keyboard.gschema.xml \
		org.mate.peripherals-mouse.gschema.xml \
		org.mate.sound.gschema.xml \
		org.mate.thumbnail-cache.gschema.xml \
		org.mate.thumbnailers.gschema.xml \
		org.mate.typing-break.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
