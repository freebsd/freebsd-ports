# $FreeBSD$

PORTNAME=	wx
PORTVERSION=	3.0.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/${PORTVERSION}
PKGNAMESUFFIX=	30-gtk2
DISTNAME=	wxWidgets-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png\
		libjpeg.so:${PORTSDIR}/graphics/jpeg\
		libtiff.so:${PORTSDIR}/graphics/tiff\
		libexpat.so:${PORTSDIR}/textproc/expat2\
		libinotify.so:${PORTSDIR}/devel/libinotify\
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

USES+=		iconv gmake pkgconfig tar:bzip2
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		glu
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpng=sys\
		--with-libjpeg=sys\
		--with-libtiff=sys\
		--with-zlib=sys\
		--with-expat=sys\
		--with-opengl\
		--with-libmspack\
		--with-gtk\
		--enable-mediactrl\
		--disable-backtrace\
		--enable-webview\
		--enable-graphics_ctx
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -pthread -linotify"\
		X11BASE="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	GSTREAMER MSPACK NLS
OPTIONS_DEFAULT=GSTREAMER MSPACK
MSPACK_DESC=	MS archives support
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=--enable-mediactrl
USE_GNOME+=	gconf2
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=--disable-mediactrl
.endif

.if ${PORT_OPTIONS:MMSPACK}
CONFIGURE_ARGS+=--with-libmspack
LIB_DEPENDS+=	libmspack.so:${PORTSDIR}/archivers/libmspack
.else
CONFIGURE_ARGS+=--without-libmspack
.endif

.include <bsd.port.mk>
