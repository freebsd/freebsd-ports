# New ports collection makefile for:	wmx
# Version required:	4.0
# Date created:		11. Jan 1998
# Whom:			Stefan Zehl <sec@42.org>
#
# $Id: Makefile,v 1.5 1998/09/17 00:32:59 asami Exp $
#

DISTNAME=	wmx-4
PKGNAME=        wmx-4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.all-day-breakfast.com/wmx/ \
		ftp://ftp.tu-clausthal.de/pub/unix.new/x11-wm/ \
		ftp://ftp.maths.tcd.ie/src/eoin-tmp/window_managers/

MAINTAINER=	sec@42.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
ALL_TARGET=	depend wmx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
.endif

.include <bsd.port.mk>
