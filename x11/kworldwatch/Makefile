# New ports collection makefile for:   kworldwatch
# Version required:    0.6
# Date created:        12 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.12 1998/11/07 18:30:55 fenner Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/latest/apps/utils
EXTRACT_SUFX=	.tgz

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11 \
		kfm.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
