PORTNAME=	workrave
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.50
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	https://github.com/rcaelers/workrave/releases/download/v${DISTVERSION:S/./_/g}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSI prevention tool (${FLAVOR} flavor)
WWW=		https://www.workrave.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgdome.so:textproc/gdome2 \
		libharfbuzz.so:print/harfbuzz

FLAVORS=			default xfce
FLAVOR?=			${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	workrave-xfce
xfce_PKGNAMESUFFIX=		-xfce
xfce_CONFLICTS_INSTALL=		workrave
xfce_DESCR=			${.CURDIR}/pkg-descr.xfce

USES=		compiler:c++11-lang desktop-file-utils gmake gnome libtool \
		localbase pkgconfig xorg
.if ${FLAVOR} == xfce
CATEGORIES+=	xfce
USES+=		xfce
USE_XFCE=	libutil panel
# Easier than using *_SUB since there's no flavor helper for that.
PLIST_FILES=	lib/xfce4/panel/plugins/libworkrave-plugin.a \
		lib/xfce4/panel/plugins/libworkrave-plugin.so \
		share/xfce4/panel/plugins/workrave-xfce-applet.desktop
.endif
USE_CXXSTD=	c++11
USE_GNOME=	gdkpixbuf gtkmm30 intlhack intltool introspection:build libxml2
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xmu xorgproto xscrnsaver xtst

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gconf \
		--disable-gnome3 \
		--disable-gsettings \
		--disable-indicator \
		--disable-mate \
		--disable-pulse

.if ${FLAVOR} != xfce
CONFIGURE_ARGS+=	--disable-xfce
.endif

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=		DBUS DISTRIBUTION GSTREAMER NLS
OPTIONS_DEFAULT=	DBUS GSTREAMER
OPTIONS_SUB=		yes

DISTRIBUTION_DESC=	Build with networking support

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
			boost-libs>0:devel/boost-libs
DBUS_USES=		python:build
DBUS_CONFIGURE_ENABLE=	dbus

DISTRIBUTION_CONFIGURE_ENABLE=	distribution

GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=good
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

# Upstream recommends editing that file to add or remove exercises,
# hence treat it like a config file.
post-stage:
	${MV} ${STAGEDIR}${DATADIR}/exercises/exercises.xml \
		${STAGEDIR}${DATADIR}/exercises/exercises.xml.sample

.include <bsd.port.mk>
