# New ports collection makefile for:	qt4pas
# Date created:		2009-01-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qt4pas
PORTVERSION=	1.70
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://users.telenet.be/Jan.Van.hijfte/qtforfpc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^/V/}_Qt${QT4_VER_MIN}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Qt4 binding for FreePascal

USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network script webkit

QT4_VER_MIN=	4.5.0

.include <bsd.port.pre.mk>

.if  ${QT4_VERSION:S/.//g} < ${QT4_VER_MIN:S/.//g}
IGNORE=	Please update your current qt4 version to ${QT4_VER_MIN}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%QT_INCDIR%%|${QT_INCDIR}|' -e 's|%%QT_LIBDIR%%|${QT_LIBDIR}|g' -e \
		's|%%CXX%%|${CXX}|g' -e 's|%%STRIP_CMD%%|${STRIP_CMD}|g' -e 's|bash|sh|g' ${WRKSRC}/compile_lib.sh

do-build:
	@cd ${WRKSRC} && \
		${SH} compile_lib.sh

do-install:
	@${MKDIR} ${PREFIX}/lib/qt4
	${INSTALL_PROGRAM} ${WRKSRC}/libqt4intf.so ${PREFIX}/lib/qt4

.include <bsd.port.post.mk>
