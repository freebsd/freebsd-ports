# New ports collection makefile for:   kworldwatch
# Version required:    0.6
# Date created:        12 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.3 1998/08/07 23:56:54 asami Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/latest/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs

BROKEN=		upgrade

USE_QT=		yes
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
