# New ports collection makefile for:   kvidtune
# Version required:    0.4.1
# Date created:        15 November 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	kvidtune-0.4.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/admin

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11 \
		kfm.2:${PORTSDIR}/x11/kdelibs11 \
		kfile.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	MOC=${X11BASE}/bin/moc

.include <bsd.port.mk>
