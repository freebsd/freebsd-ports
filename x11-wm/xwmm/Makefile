# New ports collection makefile for:	xwmm
# Version required:	0.7
# Date created:		26 Nov 1999
# Whom:			imura@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	xwmm-0.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.softarc.com/~msharkey/wmm/

MAINTAINER=	imura@FreeBSD.org

FETCH_BEFORE_ARGS=	-b

USE_X_PREFIX=	yes
USE_QT2=	yes
USE_GMAKE=	yes
MAKE_ENV=	QTDIR=$(X11BASE)
ALL_TARGET=	# empty

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/xwmm $(PREFIX)/bin
	$(INSTALL_SCRIPT) $(WRKSRC)/startkde.fixed $(PREFIX)/bin
	$(MKDIR) $(PREFIX)/lib/X11/xwmm
	$(INSTALL_DATA) $(WRKSRC)/system.xwmmrc $(PREFIX)/lib/X11/xwmm

.include <bsd.port.mk>
