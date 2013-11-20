# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/x11-wm/muffin/Makefile 18865 2013-11-08 11:15:16Z kwm $

PORTNAME=	muffin
PORTVERSION=	1.8.2
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon

BUILD_DEPENDS=	zenity3>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity3>=3.0.0:${PORTSDIR}/x11/zenity3

FETCH_ARGS=	-Fpr
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_PYTHON=	2.5+
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool autoconf automake
USE_GNOME=	gconf2 gnomedocutils gnomehier gnomeprefix gtk30 \
		intlhack introspection:build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

pre-configure:
		@cd ${WRKSRC} && ${SH} autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|REQUIRED_AUTOMAKE_VERSION=1.10|REQUIRED_AUTOMAKE_VERSION=1.14|g' \
		${WRKSRC}/autogen.sh

.include <bsd.port.mk>
