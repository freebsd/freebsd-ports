# New ports collection makefile for:	libzvt
# Date created:				12 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libzvt
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
		 s|[(]datadir[)]/gnome/|(datadir)/|g'
	@find ${WRKSRC} -name "*.[ch]" | xargs ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
