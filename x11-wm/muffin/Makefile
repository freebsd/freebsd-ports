# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/x11-wm/muffin/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	muffin
PORTVERSION=	2.2.1
PORTREVISION=	1
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
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libcinnamon-desktop.so:${PORTSDIR}/x11/cinnamon-desktop
RUN_DEPENDS=	zenity3>=3.0.0:${PORTSDIR}/x11/zenity3

USES=		gettext libtool:keepla gmake pathfix pkgconfig
USE_GNOME=	gconf2 gnomedocutils gnomehier gnomeprefix gtk30 \
		intlhack introspection:build
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_CSTD=	gnu89
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

pre-configure:
		@cd ${WRKSRC} && ${SH} autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|REQUIRED_AUTOMAKE_VERSION=1.10|REQUIRED_AUTOMAKE_VERSION=1.14|g' \
		${WRKSRC}/autogen.sh

.include <bsd.port.mk>
