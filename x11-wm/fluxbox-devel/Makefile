# New ports collection makefile for:	fluxbox
# Date created:				29 November 2001
# Whom:					spn
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.1.8
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://fluxbox.sourceforge.net/download/patches/
PATCHFILES=	fluxbox-0.1.8-bugfix-1-2.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	spn@g0v.ru

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		fluxbox.1 bsetroot.1

.include <bsd.port.mk>
