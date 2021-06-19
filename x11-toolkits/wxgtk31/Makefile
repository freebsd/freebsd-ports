PORTNAME=	wx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	31-gtk3

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit (wxWidgets) with GTK+ bindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjbig.so:graphics/jbigkit \
		libnotify.so:devel/libnotify \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff \
		libwayland-egl.so:graphics/wayland

USES=		compiler:c++11-lib gl gmake gnome iconv jpeg localbase \
		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	wxWidgets
GH_PROJECT=	wxWidgets
GH_TUPLE=	wxWidgets:Catch:ee4acb6:wxWidgets_Catch/3rdparty/catch

GNU_CONFIGURE=	yes
USE_XORG=	x11 sm xxf86vm xtst
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-expat=sys \
		--with-opengl \
		--with-gtk=3 \
		--without-gnomevfs \
		--disable-epollloop \
		--disable-joystick \
		--enable-backtrace \
		--enable-ipv6 \
		--enable-optimise \
		--enable-utf8 \
		--enable-graphics_ctx \
		--enable-compat28 \
		--enable-compat30
CONFIGURE_ENV=	X11BASE="${LOCALBASE}" \
		ac_cv_header_sys_inotify_h=no

OPTIONS_DEFINE=		GSTREAMER MSPACK NLS WEBKIT
OPTIONS_DEFAULT=	GSTREAMER MSPACK WEBKIT
MSPACK_DESC=		Microsoft archives support
OPTIONS_SUB=		yes

NLS_USES=			gettext

GSTREAMER_CONFIGURE_ENABLE=	mediactrl
GSTREAMER_USE=			GSTREAMER1=bad

MSPACK_CONFIGURE_WITH=		libmspack
MSPACK_LIB_DEPENDS=		libmspack.so:archivers/libmspack

WEBKIT_CONFIGURE_ENABLE=	webview
WEBKIT_LIB_DEPENDS=		libwebkit2gtk-4.0.so:www/webkit2-gtk3

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
