# New ports collection makefile for:	SoQt
# Date created:				10 March 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoQt
PORTVERSION=	1.4.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.coin3d.org/coin/src/all/ \
		ftp://ftp.coin3d.org/pub/coin/src/all/
DIST_SUBDIR=	KDE

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Qt4 toolkit library for Coin

LIB_DEPENDS=	Coin.60:${PORTSDIR}/graphics/Coin

USE_AUTOTOOLS=	libtool:22
USE_QT_VER=	4
QT_COMPONENTS=	corelib qt3support opengl moc_build
USE_GMAKE=	yes
CPPFLAGS+=	-I${QT_INCDIR} -I${QT_INCDIR}/Qt -I${LOCALBASE}/include
LDFLAGS+=	-L${QT_LIBDIR} -L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-pthread=yes --with-coin=${LOCALBASE} \
		--with-qt=${QT_LIBDIR}
USE_LDCONFIG=	yes

MAN1=		soqt-config.1

post-install:
	@${TOUCH} ${PREFIX}/include/Inventor/Qt/engines/.keep_me

.include <bsd.port.mk>
