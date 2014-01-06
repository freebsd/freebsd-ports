# Created by: fjoe@FreeBSD.org
# $FreeBSD$

PORTNAME=	wx
PORTVERSION=	2.9.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/${PORTVERSION}
PKGNAMESUFFIX=	29-gtk2
DISTNAME=	wxWidgets-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png\
		jpeg.11:${PORTSDIR}/graphics/jpeg\
		tiff.4:${PORTSDIR}/graphics/tiff\
		expat.6:${PORTSDIR}/textproc/expat2\
		inotify.0:${PORTSDIR}/devel/libinotify\
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2

USES+=		iconv gmake pkgconfig
USE_BZIP2=	yes
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
		--with-mspack\
		--with-gtk\
		--enable-mediactrl\
		--disable-backtrace\
		--enable-graphics_ctx
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -linotify"\
		PTHREAD_LIBS="${PTHREAD_LIBS}"\
		X11BASE="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
NO_LATEST_LINK=	yes

OPTIONS_DEFINE=	GSTREAMER MSPACK
OPTIONS_DEFAULT=	GSTREAMER MSPACK
MSPACK_DESC=	MS archives support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=--enable-mediactrl
USE_GNOME+=	gconf2
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-mediactrl
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if ${PORT_OPTIONS:MMSPACK}
CONFIGURE_ARGS+=--with-libmspack
LIB_DEPENDS+=	mspack.1:${PORTSDIR}/archivers/libmspack
.else
CONFIGURE_ARGS+=--without-libmspack
.endif

.include <bsd.port.mk>
