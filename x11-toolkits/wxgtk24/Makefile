# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.4.2
PORTREVISION?=	17
PKGNAMESUFFIX=	${WXGTK_FLAVOR}
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_XORG=	x11 sm xxf86vm xinerama
USE_GL=		glu
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl\
		--enable-gtk2 \
		--includedir=${PREFIX}/include/wx-2.4
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv \
			 ${PTHREAD_LIBS}"\
		X11BASE="${LOCALBASE}"
NO_LATEST_LINK=	yes
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk2

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's|lgdk|lgdk-x11-2.0|g' ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} -e 's|pkg_config_args --cflags|pkg_config_args pangox --cflags|g ; \
		s|pkg_config_args --libs|pkg_config_args pangox --libs|g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
