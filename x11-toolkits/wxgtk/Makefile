# New ports collection makefile for:	wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.2.9
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxGTK-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-opengl
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} \
			  -I${WRKSRC}/include \
			  -I${LOCALBASE}/include \
			  -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib \
			 -L${X11BASE}/lib -lm"

pre-patch:
	@${PERL} -pi -e 's|-l\$$THREADS_LIB|${PTHREAD_LIBS}|g ; \
			 s|-l\$$THREADS_LINK|${PTHREAD_LIBS}|g' \
				${WRKSRC}/configure

post-install:
	@${RM} -rf ${PREFIX}/include/wx/motif
	@${RM} -rf ${PREFIX}/include/wx/msw

.include <bsd.port.mk>
