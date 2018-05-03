# $FreeBSD$

PORTNAME=	wx
PORTVERSION=	3.0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	30-gtk2

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	The wxWidgets GUI toolkit with GTK+ bindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libexpat.so:textproc/expat2

USE_GITHUB=	yes
GH_ACCOUNT=	wxWidgets
GH_PROJECT=	wxWidgets

USES=		compiler:c++11-lib gmake iconv jpeg localbase pkgconfig
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		glu
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-expat=sys \
		--with-opengl \
		--with-gtk \
		--without-gnomevfs \
		--disable-epollloop \
		--disable-joystick \
		--enable-backtrace \
		--enable-ipv6 \
		--enable-optimise \
		--enable-utf8 \
		--enable-graphics_ctx \
		--enable-compat26 \
		--enable-compat28
CONFIGURE_ENV=	X11BASE="${LOCALBASE}" \
		ac_cv_header_sys_inotify_h=no

OPTIONS_DEFINE=	GSTREAMER MSPACK NLS WEBKIT
OPTIONS_DEFAULT=GSTREAMER MSPACK WEBKIT
MSPACK_DESC=	Microsoft archives support
OPTIONS_SUB=	yes

NLS_USES=	gettext

GSTREAMER_CONFIGURE_ENABLE=	mediactrl
GSTREAMER_USE=	GNOME=gconf2 GSTREAMER1=yes

MSPACK_CONFIGURE_WITH=	libmspack
MSPACK_LIB_DEPENDS=	libmspack.so:archivers/libmspack

WEBKIT_CONFIGURE_ENABLE=	webview
WEBKIT_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

.include <bsd.port.pre.mk>

# PR 196703, 197031
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=--disable-precomp-headers
.endif

post-build-NLS-on:
	@${DO_MAKE_BUILD} allmo -C ${BUILD_WRKSRC}/locale

.include <bsd.port.post.mk>
