# New ports collection makefile for:	Blackbox
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION= 	0.51.3.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://portal.alug.org/pub/blackbox/0.5x.x/ \
	 	ftp://ftp.dti.ad.jp/pub/X/blackbox/0.5x.x/

MAINTAINER=	cpiazza@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

.if !defined(USE_KDE)
pre-configure:
	@ ${ECHO_MSG}
	@ ${ECHO_MSG} If you would like build Blackbox with KDE support
	@ ${ECHO_MSG} you must set the variable USE_KDE
	@ ${ECHO_MSG}
.else
pre-configure:
	@ ${ECHO_MSG}
	@ ${ECHO_MSG} Building Blackbox with KDE support
	@ ${ECHO_MSG}
CONFIGURE_ARGS= --enable-kde
.endif

.include <bsd.port.mk>
