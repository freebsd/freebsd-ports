# New ports collection makefile for:	libepplet
# Date created:        			18 October 1999
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	libepplet
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	x11-wm devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	epplets-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for building enlightenment dock applications

USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_GL=		yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	EROOT="${X11BASE}/share/enlightenment" \
		EBIN="${X11BASE}/bin" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU ${PTHREAD_LIBS}

.include <bsd.port.mk>
