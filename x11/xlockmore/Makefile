# New ports collection makefile for:	xlockmore
# Version required:     3.11
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.0 1994/11/09 00:00:00 smace Exp $
#

DISTNAME=       xlockmore-3.11
MASTER_SITES+=  ftp://crl.dec.com/pub/X11/contrib/applications/
MASTER_SITES+=	ftp://ftp.x.org/contrib/applications/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}.patches
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

.include <bsd.port.mk>
