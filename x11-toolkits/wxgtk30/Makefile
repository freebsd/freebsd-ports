PORTNAME=	wx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.5.1
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/wxWidgets/wxWidgets/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${_SHORT_WX_VER}-${FLAVOR}
DISTNAME=	wxWidgets-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit with GTK bindings
WWW=		https://www.wxwidgets.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lib gl gmake gnome iconv jpeg localbase \
		pkgconfig tar:bz2 xorg
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-expat=sys \
		--with-opengl \
		--without-gnomevfs \
		--disable-epollloop \
		--disable-joystick \
		--enable-backtrace \
		--enable-ipv6 \
		--enable-optimise \
		--enable-unicode \
		--enable-std_string \
		--enable-graphics_ctx \
		--enable-compat26 \
		--enable-compat28
CONFIGURE_ENV=	X11BASE="${LOCALBASE}" \
		ac_cv_header_sys_inotify_h=no

OPTIONS_DEFINE=	GSTREAMER NOTIFY MSPACK NLS
OPTIONS_DEFAULT=GSTREAMER MSPACK
MSPACK_DESC=	Microsoft archives support
OPTIONS_SUB=	yes

NLS_USES=	gettext

GSTREAMER_USES=		gstreamer
GSTREAMER_CONFIGURE_ENABLE=	mediactrl

NOTIFY_CONFIGURE_WITH=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

MSPACK_CONFIGURE_WITH=	libmspack
MSPACK_LIB_DEPENDS=	libmspack.so:archivers/libmspack

WEBKIT_CONFIGURE_ENABLE=	webview
WEBKIT_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk@40

FLAVORS=	gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}

.if ${FLAVOR} == gtk3
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--with-gtk=3
OPTIONS_DEFINE+=	WEBKIT
OPTIONS_DEFAULT+=	WEBKIT
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	GTK2="" WEBKIT="@comment "
.endif
PLIST_SUB+=	GTKVER=${FLAVOR}

_SHORT_WX_VER=	${DISTVERSION:S/./ /g:[1..2]:ts}

gtk3_CONFLICTS_INSTALL=	${PORTNAME}${_SHORT_WX_VER}-gtk2
gtk2_CONFLICTS_INSTALL=	${PORTNAME}${_SHORT_WX_VER}-gtk3

.include <bsd.port.pre.mk>

# TLS is broken on armv6/7, PR 229396
.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ARGS+=--disable-tls
.endif

# PR 196703, 197031
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=--disable-precomp-headers
.endif

# wxWidgets uses the same linker version script for all its shared libraries, so
# some symbols are expectedly undefined. Suppress errors with lld >= 17 due to
# these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

post-build-NLS-on:
	@${DO_MAKE_BUILD} allmo -C ${BUILD_WRKSRC}/locale

.include <bsd.port.post.mk>
