# New ports collection makefile for:	Blackbox
# Version required:	0.50.5
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.20 1999/05/01 02:15:38 steve Exp $
#

DISTNAME=	blackbox-0.50.5
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://balance.wiw.org/pub/blackbox/ \
	 	ftp://ftp.dti.ad.jp/pub/X/blackbox/ \
		ftp://ftp.max.irk.ru/unix/x/wm/

MAINTAINER=	cpiazza@home.net

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

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

post-extract:
	@ ${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
