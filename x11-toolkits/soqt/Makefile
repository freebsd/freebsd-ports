# New ports collection makefile for:	SoQt
# Date created:				10 March 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoQt
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.coin3d.org/coin/src/all/ \
		ftp://ftp.coin3d.org/pub/coin/src/all/
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt toolkit library for Coin

LIB_DEPENDS=	Coin.60:${PORTSDIR}/graphics/Coin

USE_AUTOTOOLS=	libtool:15
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	--with-pthread=yes --with-coin=${LOCALBASE}
USE_LDCONFIG=	yes

MAN1=		soqt-config.1

post-install:
	@${TOUCH} ${PREFIX}/include/Inventor/Qt/engines/.keep_me

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
