# New ports collection makefile for:	Blackbox
# Version required:	0.50.3
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.16 1998/12/23 01:37:34 steve Exp $
#

DISTNAME=	blackbox-0.50.3
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://balance.wiw.org/pub/blackbox/ \
		ftp://ftp.aist.com.ua/pub/unix/window_managers/blackbox/

MAINTAINER=	ports@FreeBSD.ORG

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if !defined(USE_KDE)
pre-fetch:
	@echo
	@echo If you would like build Blackbox with KDE support
	@echo you must set the variable USE_KDE
	@echo
.else
pre-fetch:
	@echo
	@echo Building Blackbox with KDE support
	@echo
CONFIGURE_ARGS= --enable-kde
.endif
.include <bsd.port.mk>
