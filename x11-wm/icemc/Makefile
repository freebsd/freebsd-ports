# New ports collection makefile for:	icemc
# Date created:				31 December 2001
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	icemc
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.algorithm.at/comp/icemc/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	icemc-0.2.2.patch.tar.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	adamw@FreeBSD.org

PORTCOMMENT=	QT-based menu editor for IceWM

USE_X_PREFIX=	yes
USE_QT_VER=	3

MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" MOC="${MOC}" LIBQT="-lqt-mt"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/icemc ${PREFIX}/bin

.include <bsd.port.mk>
