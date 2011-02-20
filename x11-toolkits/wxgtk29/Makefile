# New ports collection makefile for:	wxgtk26
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.9.1
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/${PORTVERSION}
PKGNAMESUFFIX=	gtk2
DISTNAME=	wxWidgets-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png\
		jpeg.11:${PORTSDIR}/graphics/jpeg\
		tiff.4:${PORTSDIR}/graphics/tiff\
		expat.6:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
USE_XORG=	x11 sm xxf86vm xinerama 
USE_GL=		glu
USE_GMAKE=	yes
USE_ICONV=	yes
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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"\
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"\
		PTHREAD_LIBS="${PTHREAD_LIBS}"\
		X11BASE="${LOCALBASE}"
NO_LATEST_LINK=	yes

OPTIONS=	GSTREAMER "media support" on\
		MSPACK "MS archives support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=--enable-mediactrl
USE_GNOME+=	gconf2
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=--disable-mediactrl
.endif

.if defined(WITH_MSPACK)
CONFIGURE_ARGS+=--with-libmspack
LIB_DEPENDS+=	mspack.1:${PORTSDIR}/archivers/libmspack
.else
CONFIGURE_ARGS+=--without-libmspack
.endif

.include <bsd.port.post.mk>
