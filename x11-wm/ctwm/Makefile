# New ports collection makefile for:	ctwm
# Version required:	3.2 patchlevel 1
# Date created:		13 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1995/01/13 12:48:46 jkh Exp $
#

DISTNAME=	ctwm-3.2p1
MASTER_SITES=	ftp://ftp.x.org/contrib/window_managers/
USE_IMAKE=	YES
EXTRACT_SUFX=	.tar.Z
.if !exists(/usr/X11R6/lib/libXpm.a)
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
.endif

.include <bsd.port.mk>
