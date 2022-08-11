PORTNAME=	wx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.5
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/wxWidgets/wxWidgets/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	${_SHORT_WX_VER}-${FLAVOR}
DISTNAME=	wxWidgets-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit (wxWidgets) with ${FLAVOR:S/k/&+/:tu} bindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjbig.so:graphics/jbigkit \
		libnotify.so:devel/libnotify \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff \
		libwayland-egl.so:graphics/wayland

USES=		compiler:c++11-lib gl gmake gnome iconv jpeg localbase \
		pkgconfig tar:bz2 xorg

GNU_CONFIGURE=	yes
USE_XORG=	x11 sm xxf86vm xtst
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
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
		--enable-compat28 \
		--enable-compat30
CONFIGURE_ENV=	X11BASE="${LOCALBASE}" \
		ac_cv_header_sys_inotify_h=no

OPTIONS_DEFINE=		GSTREAMER MSPACK NLS
OPTIONS_DEFAULT=	GSTREAMER MSPACK
MSPACK_DESC=		Microsoft archives support
OPTIONS_SUB=		yes

NLS_USES=			gettext

GSTREAMER_CONFIGURE_ENABLE=	mediactrl
GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=bad

MSPACK_CONFIGURE_WITH=		libmspack
MSPACK_LIB_DEPENDS=		libmspack.so:archivers/libmspack

WEBKIT_CONFIGURE_ENABLE=	webview
WEBKIT_LIB_DEPENDS=		libwebkit2gtk-4.0.so:www/webkit2-gtk3

FLAVORS=	gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}

.if ${FLAVOR} == gtk3
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--with-gtk=3
OPTIONS_DEFINE+=	WEBKIT
OPTIONS_DEFAULT+=	WEBKIT
PLIST_SUB+=	GTK2="@comment " GTK3=""
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	GTK2="" GTK3="@comment " WEBKIT="@comment "
.endif
PLIST_SUB+=	GTKVER=${FLAVOR}

_SHORT_WX_VER=	${PORTVERSION:S/./ /g:[1..2]:ts}

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

post-build-NLS-on:
	@${DO_MAKE_BUILD} allmo -C ${BUILD_WRKSRC}/locale

post-install-NLS-on: # stray file: https://trac.wxwidgets.org/ticket/18147
	@${RM} ${STAGEDIR}${PREFIX}/share/locale/it/LC_MESSAGES/wxmsw.mo

.include <bsd.port.post.mk>
