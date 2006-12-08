# New ports collection makefile for:	qwt-devel
# Date created:		2006-12-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	5.0.0.r1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-5.0.0rc1

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Qt Widgets for Technical Applications

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

CONFLICTS=	qwt-4.*

USE_QT_VER=	3
USE_BZIP2=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" \
		QTDIR="${QT_PREFIX}"
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PLIST_SUB+=	NODOCS=""
.else
PLIST_SUB+=	NODOCS="@comment "
.endif

pre-build:
	cd ${WRKSRC} && qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qwt.pro -o Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libqwt.so.5.0.0 ${PREFIX}/lib/libqwt.so.5
	${LN} -fs ${PREFIX}/lib/libqwt.so.5 ${PREFIX}/lib/libqwt.so
	${MKDIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qwt
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/qwt
.endif

.include <bsd.port.mk>
