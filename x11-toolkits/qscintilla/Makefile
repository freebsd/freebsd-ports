# New ports collection makefile for:	qscintilla
# Date created:				2003-08-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qscintilla
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/snapshots/QScintilla/ \
		http://freebsd.ricin.com/ports/distfiles/
DISTNAME=	${PORTNAME}-1.64-gpl-snapshot-20050709

MAINTAINER=	danny@ricin.com
COMMENT=	QT port of scintilla

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${DISTNAME}/qt

USE_X_PREFIX=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QTDIR="${X11BASE}"
MAKE_ENV=	QTDIR="${X11BASE}"
INSTALLS_SHLIB=	yes

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qscintilla.pro

do-install:
	${INSTALL_DATA} ${WRKSRC}/qextscintilla*.h ${PREFIX}/include
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/qscintilla*.qm ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/libqscintilla.so.6.0.0 ${PREFIX}/lib/libqscintilla.so.6
	${LN} -sf ${PREFIX}/lib/libqscintilla.so.6 ${PREFIX}/lib/libqscintilla.so

.include <bsd.port.mk>
