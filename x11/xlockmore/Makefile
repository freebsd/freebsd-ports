# New ports collection makefile for:	xlockmore
# Version required:     4.01
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.16 1997/02/20 07:26:26 tg Exp $
#

DISTNAME=       xlockmore-4.01
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

post-extract:
	@cp ${FILESDIR}/flag-freebsd.h ${WRKSRC}/flags

.include <bsd.port.mk>
