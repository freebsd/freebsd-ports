# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION= 	0.16.4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/enlightenment/ \
		ftp://ftp.enlighte.nu/pub/Enlightenment/Enlightenment/ \
		ftp://beaver.its.vu.edu.au/pub/enlightenment/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound \
		Fnlib.0:${PORTSDIR}/graphics/fnlib \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		ttf.4:${PORTSDIR}/print/freetype \
		ghttp.1:${PORTSDIR}/www/libghttp \
		intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --with-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

MAN1=		enlightenment.1

post-install:
	${CHOWN} -R root:wheel ${PREFIX}/share/enlightenment/themes
	${CHMOD} -R a+rX ${PREFIX}/share/enlightenment/themes

.include <bsd.port.mk>
