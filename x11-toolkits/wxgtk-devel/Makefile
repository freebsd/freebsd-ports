# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.2.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER=	nectar@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/wxGTK

USE_X_PREFIX=	yes
USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

AUTOCONF=	autoconf && \
			${PERL} -pi -e 's|-l\$$THREADS_LIB|${PTHREAD_LIBS}|g ; \
					s|-l\$$THREADS_LINK|${PTHREAD_LIBS}|g' \
						${WRKSRC}/configure

post-install:
	@${RM} -rf ${PREFIX}/include/wx/motif
	@${RM} -rf ${PREFIX}/include/wx/msw

.include <bsd.port.mk>
