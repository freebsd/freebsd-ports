# New ports collection makefile for:	xwmm
# Date created:		26 Nov 1999
# Whom:			imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	xwmm
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami

MAINTAINER=	ports@freebsd.org
COMMENT=	A simple utility managing multiple Window Managers with Qt

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
MAKE_ENV=	QTDIR=$(X11BASE)
ALL_TARGET=	# empty

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/xwmm $(PREFIX)/bin
	$(INSTALL_SCRIPT) $(WRKSRC)/startkde.fixed $(PREFIX)/bin/startkde.xwmm
	$(MKDIR) $(PREFIX)/lib/X11/xwmm
	$(INSTALL_DATA) $(WRKSRC)/system.xwmmrc $(PREFIX)/lib/X11/xwmm

.include <bsd.port.post.mk>
