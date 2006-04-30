# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/vte/Makefile,v 1.49 2006/04/27 01:40:22 ahze Exp $
#

PORTNAME=	vte
PORTVERSION=	0.12.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-python

OPTIONS=	GLX	"Enable support for DRI/GLX rendering" off

.include <bsd.port.pre.mk>

.if defined(WITH_GLX)
CONFIGURE_ARGS+=	--with-glX
USE_GL=			yes
.endif

.include <bsd.port.post.mk>
