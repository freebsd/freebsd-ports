# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	2.4.2
PORTREVISION?=	9
PKGNAMESUFFIX=	${WXGTK_FLAVOR}
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER?=	fjoe@FreeBSD.org
COMMENT?=	The wxWidgets GUI toolkit with GTK+ bindings

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl\
		--enable-gtk2 ${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include \
			  ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv \
			 -L${X11BASE}/lib \
			 ${PTHREAD_LIBS}"
NO_LATEST_LINK=	yes
PLIST=		${.CURDIR}/pkg-plist

WXGTK_FLAVOR?=	gtk2

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's|lgdk|lgdk-x11-2.0|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
