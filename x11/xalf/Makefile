# New ports collection makefile for:	xalf
# Date created:				27 March 2001
# Whom:					Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xalf
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.lysator.liu.se/~astrand/projects/xalf/
MASTER_SITE_SUBDIR=	sources/xalf/0.12
EXTRACT_SUFX=	.tgz

MAINTAINER=	gnome@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libcapplet
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
