# New ports collection makefile for:	qscintilla
# Date created:				2003-08-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qscintilla
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/QScintilla/
DISTNAME=	qscintilla-1.61-gpl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QT port of scintilla

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
WRKSRC=		${WRKDIR}/${DISTNAME}/qt
CONFIGURE_ENV=	QTDIR="${X11BASE}"
MAKE_ENV=	QTDIR="${X11BASE}"
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qscintilla.pro

do-install:
	${INSTALL_DATA} ${WRKSRC}/qextscintilla*.h ${PREFIX}/include;
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/qscintilla*.qm ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/libqscintilla.so.5.0.0 ${PREFIX}/lib/libqscintilla.so.5
	${LN} -sf ${PREFIX}/lib/libqscintilla.so.5 ${PREFIX}/lib/libqscintilla.so

.include <bsd.port.mk>
