# New ports collection makefile for:	enlightenment
# Version required:		0.15.0-19990120
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.32 1999/01/14 17:08:21 vanilla Exp $
#

DISTNAME=	enlightenment-0.15.0-19990120
PKGNAME=	enlightenment-0.15.0
CATEGORIES=	x11-wm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	esd.1:${PORTSDIR}/audio/esound \
		Fnlib.0:${PORTSDIR}/graphics/fnlib \
		gif.3:${PORTSDIR}/graphics/giflib \
		Imlib.2:${PORTSDIR}/graphics/imlib \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		ttf.3:${PORTSDIR}/print/freetype

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS=-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/enlightenment-0.15.0

pre-patch:
.if defined(XLOCALE)
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-xlocale
.endif

.include <bsd.port.mk>
