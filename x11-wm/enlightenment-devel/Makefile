# New ports collection makefile for:	enlightenment
# Version required:		0.15.5
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	enlightenment-0.15.5
CATEGORIES=	x11-wm gnome
MASTER_SITES=	ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		http://www.rasterman.com/files/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/enlightenment/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	esd.1:${PORTSDIR}/audio/esound \
		Fnlib.0:${PORTSDIR}/graphics/fnlib \
		gif.3:${PORTSDIR}/graphics/giflib \
		Imlib.4:${PORTSDIR}/graphics/imlib \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		ttf.3:${PORTSDIR}/print/freetype \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
