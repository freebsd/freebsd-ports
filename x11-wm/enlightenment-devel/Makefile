# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.999.013
PORTREVISION=	0
CATEGORIES=	x11-wm
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A very artistic X window manager

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		evas.1:${PORTSDIR}/graphics/evas \
		edje.5:${PORTSDIR}/graphics/edje \
		ecore.1:${PORTSDIR}/x11/ecore \
		embryo.9:${PORTSDIR}/lang/embryo \
		eet.9:${PORTSDIR}/devel/eet

USE_GMAKE=	yes
CONFLICTS=	enlightenment-[0-9]*
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnometarget
USE_ICONV=	yes
USE_GETTEXT=	yes
NO_LATEST_LINK=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 50000
IGNORE=	Does not build on 4.X
.endif

.include <bsd.port.post.mk>
