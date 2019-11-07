# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	muffin
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	x11-wm gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libclutter-glx-1.0.so:graphics/clutter \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity

USES=		autoreconf:build gettext libtool gmake \
		pathfix pkgconfig python:2.7 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	gconf2 gnomedocutils gnomeprefix gtk30 \
		intlhack introspection:build
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=unused-function
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=unused-function
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
MAKE_ARGS=	V=1
GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml
INSTALL_TARGET=	install-strip

pre-configure:
		@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|REQUIRED_AUTOMAKE_VERSION=1.10|REQUIRED_AUTOMAKE_VERSION=1.14|g' \
		${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e 's|--warn-error||g' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
