# New ports collection makefile for:   kworldwatch
# Version required:    0.6
# Date created:        12 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.4 1998/08/12 06:29:36 asami Exp $
#

DISTNAME=	kworldwatch-0.6
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/latest/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	kdecore\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kdeui\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kfm\\.1\\.:${PORTSDIR}/x11/kdelibs

BROKEN=		upgrade

USE_QT=		yes
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
