# New ports collection makefile for:	xlockmore
# Version required:     3.11
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.10 1996/11/12 07:08:28 tg Exp $
#

DISTNAME=       xlockmore-3.11
MASTER_SITES=  ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.patches
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

.include <bsd.port.mk>
