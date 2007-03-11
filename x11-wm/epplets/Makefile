# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of Enlightenment dock applications

BUILD_DEPENDS=	e16:${PORTSDIR}/x11-wm/enlightenment
LIB_DEPENDS=	Imlib2.4:${PORTSDIR}/graphics/imlib2 \
		cdaudio.1:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	import:${PORTSDIR}/graphics/ImageMagick \
		e16:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
USE_GNOME=	esound lthack
USE_GL=		yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-fsstd

.include <bsd.port.mk>
