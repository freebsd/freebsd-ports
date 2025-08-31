PORTNAME=	wx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.8.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/wxWidgets/wxWidgets/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${_SHORT_WX_VER}-${FLAVOR}
DISTNAME=	wxWidgets-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit (wxWidgets) with ${FLAVOR:S/k/&+/:tu} bindings
WWW=		https://www.wxwidgets.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig.so:graphics/jbigkit \
		libnotify.so:devel/libnotify \
		libpcre2-32.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libtiff.so:graphics/tiff \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS=	gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}
gtk3_CONFLICTS_INSTALL=	${PORTNAME}${_SHORT_WX_VER}-gtk2
gtk2_CONFLICTS_INSTALL=	${PORTNAME}${_SHORT_WX_VER}-gtk3

USES=		compiler:c++11-lib gl gmake gnome iconv jpeg localbase \
		pkgconfig tar:bz2 xorg
USE_CXXSTD=	c++11
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf
USE_LDCONFIG=	yes
USE_XORG=	sm x11 xtst xxf86vm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-epollloop \
		--disable-joystick \
		--enable-backtrace \
		--enable-compat28 \
		--enable-compat30 \
		--enable-graphics_ctx \
		--enable-ipv6 \
		--enable-optimise \
		--enable-std_string \
		--enable-unicode \
		--with-expat=sys \
		--with-libjpeg=sys \
		--with-liblzma \
		--with-libpng=sys \
		--with-libtiff=sys \
		--with-nanosvg \
		--with-opengl \
		--with-zlib=sys \
		--without-gnomevfs
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no \
		X11BASE="${LOCALBASE}"

_SOVER=		0.4.1
PLIST_SUB+=	GTKVER=${FLAVOR} SOVER=${_SOVER}

OPTIONS_DEFINE=		GSTREAMER MSPACK NLS
OPTIONS_DEFAULT=	GSTREAMER MSPACK
OPTIONS_SUB=		yes

MSPACK_DESC=	Microsoft archives support

GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=bad
GSTREAMER_CONFIGURE_ENABLE=	mediactrl

MSPACK_LIB_DEPENDS=	libmspack.so:archivers/libmspack
MSPACK_CONFIGURE_WITH=	libmspack

NLS_USES=	gettext

WEBKIT_LIB_DEPENDS=		libwebkit2gtk-4.1.so:www/webkit2-gtk@41
WEBKIT_CONFIGURE_ENABLE=	webview

.if ${FLAVOR} == gtk3
USE_GNOME+=		gtk30
CONFIGURE_ARGS+=	--with-gtk=3
OPTIONS_DEFINE+=	WEBKIT
OPTIONS_DEFAULT+=	WEBKIT
PLIST_SUB+=		GTK2="@comment " \
			GTK3=""
.else
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=		GTK2="" \
			GTK3="@comment " \
			WEBKIT="@comment "
.endif

_SHORT_WX_VER=	${PORTVERSION:S/./ /g:[1..2]:ts}

.include <bsd.port.pre.mk>

# TLS is broken on armv6/7, PR 229396
.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ARGS+=	--disable-tls
.endif

# PR 196703, 197031
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=	--disable-precomp-headers
.endif

# wxWidgets uses the same linker version script for all its shared libraries, so
# some symbols are expectedly undefined. Suppress errors with lld >= 17 due to
# these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

post-build-NLS-on:
	@${DO_MAKE_BUILD} allmo -C ${BUILD_WRKSRC}/locale

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/wxrc

.include <bsd.port.post.mk>
