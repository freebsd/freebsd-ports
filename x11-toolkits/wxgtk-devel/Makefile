# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.3.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
MASTER_SITE_SUBDIR=	wxpython
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

NO_LATEST_LINK=	"Unstable, development version."

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib \
			 -L${X11BASE}/lib" \
		GTK_CONFIG_2_0="no"

pre-patch:
	@${PERL} -pi -e 's|-l\$$THREADS_LIB|${PTHREAD_LIBS}|g ; \
			 s|-l\$$THREADS_LINK|${PTHREAD_LIBS}|g' \
				${WRKSRC}/configure

post-install:
	@${RM} -rf ${PREFIX}/include/wx/motif
	@${RM} -rf ${PREFIX}/include/wx/msw

.include <bsd.port.mk>
