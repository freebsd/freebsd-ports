# New ports collection makefile for:   kvidtune
# Version required:    0.4.1
# Date created:        15 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id$
#

DISTNAME=	kvidtune-0.4.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/admin

MAINTAINER=	josh@quick.net

LIB_DEPENDS=	kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs \
		kfm.1:${PORTSDIR}/x11/kdelibs \
		kfile.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CXXFLAGS)" \
		INSTALL_SCRIPT="$(INSTALL_SCRIPT)"

.include <bsd.port.mk>
