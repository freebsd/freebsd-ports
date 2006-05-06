# New ports collection makefile for:	SoQt
# Date created:				10 March 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoQt
PORTVERSION=	1.3.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.coin3d.org/coin/src/ \
		ftp://ftp.coin3d.org/pub/coin/src/
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt toolkit library for Coin

LIB_DEPENDS=	Coin.44:${PORTSDIR}/graphics/Coin

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	--with-pthread=yes --with-coin=${X11BASE}
INSTALLS_SHLIB=	yes

MAN1=		soqt-config.1

post-install:
	@${TOUCH} ${PREFIX}/include/Inventor/Qt/engines/.keep_me

.include <bsd.port.mk>
