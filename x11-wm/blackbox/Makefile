# New ports collection makefile for:	Blackbox
# Version required:	0.50.5
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.22 1999/06/19 08:26:18 cpiazza Exp $
#

DISTNAME=	blackbox-0.50.5
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://balance.wiw.org/pub/blackbox/ \
		ftp://ftp.digex.net/pub/X11/window-managers/blackbox/ \
	 	ftp://ftp.dti.ad.jp/pub/X/blackbox/

MAINTAINER=	cpiazza@FreeBSD.org

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
