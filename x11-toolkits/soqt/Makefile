# New ports collection makefile for:	SoQt
# Date created:				10 March 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoQt
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/
DIST_SUBDIR=	KDE

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	Qt toolkit library for Coin

LIB_DEPENDS=	Coin.41:${PORTSDIR}/graphics/Coin

USE_QT_VER=	3
USE_LIBTOOL_VER=13
CONFIGURE_ENV+=	QTDIR=${QT_PREFIX} CXXFLAGS="-pthread"
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${X11BASE}
# avoid renaming of soqt-config and soqt-config.1
CONFIGURE_TARGET=	--target=""
MAKE_ENV+=	QTDIR=${QT_PREFIX}
INSTALLS_SHLIB=	yes
MAN1=		soqt-config.1

.include <bsd.port.mk>
