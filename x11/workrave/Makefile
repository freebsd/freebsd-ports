PORTNAME=	workrave
PORTVERSION=	1.10.50
DISTVERSIONPREFIX=	v
CATEGORIES=	x11
MASTER_SITES=	https://github.com/rcaelers/workrave/releases/download/v${PORTVERSION:S/./_/g}/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	RSI prevention tool
WWW=		https://www.workrave.org/

LICENSE=	GPLv3+

LIB_DEPENDS=	libgdome.so:textproc/gdome2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang gmake gnome libtool localbase pkgconfig \
		xorg
USE_CXXSTD=	c++11
USE_GNOME=	gdkpixbuf2 gtkmm30 intlhack intltool introspection:build
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xmu xorgproto xscrnsaver xtst

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gconf \
		--disable-gnome3 \
		--disable-gsettings \
		--disable-indicator \
		--disable-mate \
		--disable-pulse \
		--disable-xfce
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		DBUS DISTRIBUTION GSTREAMER NLS
OPTIONS_DEFAULT=	DBUS GSTREAMER
OPTIONS_SUB=		yes

DISTRIBUTION_DESC=	Build with networking support

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
			boost-libs>0:devel/boost-libs
DBUS_USES=		python:3.5+,build
DBUS_CONFIGURE_ENABLE=	dbus

DISTRIBUTION_CONFIGURE_ENABLE=	distribution

GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=good
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
