# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	workrave
PORTVERSION=	1.10.34
CATEGORIES=	x11
MASTER_SITES=	https://github.com/rcaelers/workrave/releases/download/v${PORTVERSION:S/./_/g}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	RSI prevention tool

LICENSE=	GPLv3+

LIB_DEPENDS=	libgdome.so:textproc/gdome2

USES=		compiler:c++11-lang gettext gmake gnome libtool localbase \
		pkgconfig xorg
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 intlhack intltool introspection:build
INSTALLS_ICONS=	yes
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

OPTIONS_DEFINE=		DBUS DISTRIBUTION GSTREAMER
OPTIONS_DEFAULT=	DBUS GSTREAMER
OPTIONS_SUB=		yes

DISTRIBUTION_DESC=	Build with networking support

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
			boost-libs>0:devel/boost-libs
DBUS_USES=		python:3.5+,build
DBUS_CONFIGURE_ENABLE=	dbus

DISTRIBUTION_CONFIGURE_ENABLE=	distribution

GSTREAMER_USE=			GSTREAMER1=good
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

.include <bsd.port.mk>
