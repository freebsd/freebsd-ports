# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11-wm/mutter/Makefile 20040 2014-11-03 17:21:59Z kwm $

PORTNAME=	mutter
PORTVERSION=	3.14.1.5
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

BUILD_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libupower-glib.so:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm xfixes \
		xrender xdamage
USE_GL=		gbm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml \
		org.gnome.mutter.wayland.gschema.xml

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.options.mk>

# borrowed from graphics/libGL to see where Mesa 10.3 is available.
# hw context support in the i915kms driver
.if ${OPSYS} == FreeBSD && \
 (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100035 || \
  ${OSVERSION} < 1000717)
_OLD_MESA=1
.endif

.if ${OPSYS} == DragonFly && ${DFLYVERSION} >= 300901
_OLD_MESA=1
.endif

.if defined(_OLD_MESA)
EXTRA_PATCHES+=	${FILESDIR}/extra-488dd0b
.endif

# remove the gbm sed line if gbm < 10.3
post-patch:
	@${REINPLACE_CMD} -e 's|-Wcast-align||g' \
		${WRKSRC}/configure
.if defined(_OLD_MESA)
	@${REINPLACE_CMD} -e 's|gbm >= 10.3|gbm|g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
