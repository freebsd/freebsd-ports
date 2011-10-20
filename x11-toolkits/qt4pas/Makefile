# New ports collection makefile for:	qt4pas
# Date created:		2009-01-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qt4pas
PORTVERSION=	2.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://users.telenet.be/Jan.Van.hijfte/qtforfpc/V${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^/V/}_Qt${QT4_VER_MIN}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Qt4 binding for FreePascal

USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network script webkit qmake_build \
		moc_build

QT4_VER_MIN=	4.5.3

.include <bsd.port.pre.mk>

.if  ${QT4_VERSION:S/.//g} < ${QT4_VER_MIN:S/.//g}
IGNORE=	Please update your current qt4 version to ${QT4_VER_MIN}
.endif

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.post.mk>
