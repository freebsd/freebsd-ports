# New ports collection makefile for:	Blackbox
# Version required:	0.50.4
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.17 1999/03/08 20:57:39 steve Exp $
#

DISTNAME=	blackbox-0.50.4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://balance.wiw.org/pub/blackbox/ \
		ftp://ftp.aist.com.ua/pub/unix/window_managers/blackbox/

MAINTAINER=	ports@FreeBSD.ORG

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.if !defined(USE_KDE)
pre-fetch:
	@ ${ECHO_MSG}
	@ ${ECHO_MSG} If you would like build Blackbox with KDE support
	@ ${ECHO_MSG} you must set the variable USE_KDE
	@ ${ECHO_MSG}
.else
pre-fetch:
	@ ${ECHO_MSG}
	@ ${ECHO_MSG} Building Blackbox with KDE support
	@ ${ECHO_MSG}
CONFIGURE_ARGS= --enable-kde
.endif

.include <bsd.port.mk>
