# New ports collection makefile for:	tycoon
# Version required:	1.07o
# Date created:		19 September 1997
# Whom:			steve@farrell.org
#
# $Id: Makefile,v 1.3 1998/09/26 23:18:08 steve Exp $
#

DISTNAME=	tycoon-1.07o
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	steve@farrell.org

LIB_DEPENDS=	xforms:${PORTSDIR}/x11-toolkits/xforms

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-install:
	@cd ${WRKSRC}/xbackdrop/backdrops; ${MV} index index.orig; ${SED} -e 's,/usr/lib,${PREFIX}/lib,' index.orig > index; ${RM} index.orig index~

.include <bsd.port.mk>
