# Created by: fjoe@FreeBSD.org
# $FreeBSD$

PORTNAME=	wx
PORTVERSION=	2.8.12
PORTREVISION?=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/${PORTVERSION}
PKGNAMESUFFIX=	28-${WXGTK_FLAVOR}
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	libpng.so:graphics/png\
		libtiff.so:graphics/tiff\
		libexpat.so:textproc/expat2

USES=		compiler gmake iconv jpeg pkgconfig tar:bzip2
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		glu
USE_GNOME=	gtk20 pangox-compat
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpng=sys\
		--with-libjpeg=sys\
		--with-libtiff=sys\
		--with-zlib=sys\
		--with-expat=sys\
		--with-opengl\
		--with-mspack\
		--with-gtk\
		--enable-mediactrl\
		--disable-backtrace\
		--enable-graphics_ctx
CONFIGURE_ENV=	X11BASE="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk2

OPTIONS_DEFINE=	GSTREAMER MSPACK
OPTIONS_DEFAULT=	GSTREAMER MSPACK
MSPACK_DESC=	MS archives support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=--enable-mediactrl
USE_GNOME+=	gconf2
USE_GSTREAMER=	yes
PLIST_SUB+=     GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-mediactrl
PLIST_SUB+=     GSTREAMER="@comment "
.endif

.if ${PORT_OPTIONS:MMSPACK}
CONFIGURE_ARGS+=--with-libmspack
LIB_DEPENDS+=	libmspack.so:archivers/libmspack
.else
CONFIGURE_ARGS+=--without-libmspack
.endif

.if ${WXGTK_FLAVOR} != "gtk2-common"
RUN_DEPENDS=	${LOCALBASE}/include/wx-2.8/wx/wx.h:x11-toolkits/wxgtk28-common
.endif

.if ${WXGTK_FLAVOR:M*-common} != ""
NO_BUILD=	yes
INSTALL_TARGET=	install-common
USES+=		gettext-tools
.else
USE_LDCONFIG=	yes
.endif # *-common

.if ${WXGTK_FLAVOR:M*-contrib*} != ""
BUILD_WRKSRC=	${WRKSRC}/contrib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.if ${WXGTK_FLAVOR} != "gtk2-contrib-common"
USE_WX=		2.8
RUN_DEPENDS=	${LOCALBASE}/include/wx-2.8/wx/stc/stc.h:x11-toolkits/wxgtk28-contrib-common
WX_UNICODE=	yes

pre-configure:
	@${FIND} ${BUILD_WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e "s|@CXXFLAGS@|${CFLAGS} `${WX_CONFIG} --cxxflags`|" \
		-e "s|@CFLAGS@|${CFLAGS} `${WX_CONFIG} --cflags`|" \
		-e "s|@CPPFLAGS@||"

.endif # !gtk2-contrib-common
.endif # *-contrib*

CONFIGURE_ARGS+=--enable-unicode

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=	--disable-precomp-headers
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_config_args --cflags|pkg_config_args pangox --cflags|g ; \
		s|pkg_config_args --libs|pkg_config_args pangox --libs|g' \
		-e 's|png_check_sig|png_sig_cmp|g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
