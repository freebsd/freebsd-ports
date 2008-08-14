# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.8.14
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	e16-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A very artistic X window manager

DATADIR=	${PREFIX}/share/e16

USE_XORG=	xbitmaps xft x11
USE_ICONV=	yes
USE_GMAKE=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --disable-esdtest --disable-dependency-tracking \
		--disable-rpath
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_ESOUND)
USE_GNOME=	esound
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
