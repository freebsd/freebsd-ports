# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vte
PORTVERSION=	0.11.10
PORTREVISION=	6
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.11
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	gnomeprefix gnomehack lthack gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-python

.ifdef(WITH_GLX)
CONFIGURE_ARGS+=	--with-glX
USE_GL=			yes
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Vte supports the following configurable option(s):"
	@${ECHO_MSG} "	WITH_GLX=yes	Enable support for DRI rendering (may improve performance)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g' \
		${WRKSRC}/gnome-pty-helper/gnome-pty-helper.c

.include <bsd.port.mk>
