# New ports collection makefile for:   xaniroc
# Version required:    0.3
# Date created:        20 Sep 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $Id: Makefile,v 1.1.1.1 1997/11/17 12:47:03 tg Exp $
#

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.freebird.org/unixware/freebird/x11/utils/ \
		ftp://sunsite.cnlab-switch.ch/mirror/novell/freebird/x11/utils/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	sec@42.org

USE_IMAKE=	yes
MAN1=		xaniroc.1

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include <bsd.port.mk>
