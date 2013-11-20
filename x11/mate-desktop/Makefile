# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-desktop
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for MATE

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	docutils
USE_XORG=	x11 xrandr
USE_GNOME=	gnomehier gdkpixbuf2 glib20 gtk20 intlhack ltverhack
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-desktop-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
		org.mate.typing-break.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmate-desktop-2.so.17

.include <bsd.port.mk>
