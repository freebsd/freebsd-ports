# New ports collection makefile for:	ctwm
# Version required:	3.2 patchlevel 1
# Date created:		13 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1994/12/12 04:30:29 gpalmer Exp $
#

DISTNAME=	ctwm-3.2p1
MASTER_SITES=	ftp://ftp.x.org/contrib/window_managers/
USE_IMAKE=	YES
EXTRACT_SUFX=	.tar.Z
.if !exists(/usr/X11R6/lib/libXpm.a)
DEPENDS=	${PORTSDIR}/graphics/xpm
.endif

.include <bsd.port.mk>
