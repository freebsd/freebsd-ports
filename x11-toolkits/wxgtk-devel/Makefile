# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The wxWindows GUI toolkit with GTK+ bindings (unstable version)

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iconv.3:${PORTSDIR}/converters/libiconv

NO_LATEST_LINK=	"Unstable, development version."

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=builtin \
		--with-opengl \
		--host=${CONFIGURE_TARGET} \
		--build=${CONFIGURE_TARGET}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} \
			  -I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} \
			 -L${LOCALBASE}/lib -liconv \
			 -L${X11BASE}/lib" \
		GTK_CONFIG_2_0="no"

pre-patch:
	@${REINPLACE_CMD} -e 's|[$$]THREADS_LINK|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
