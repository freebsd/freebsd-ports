# New ports collection makefile for:	xview-clients
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.15 1998/12/02 06:33:37 asami Exp $
#

DISTNAME=	xview-clients
PKGNAME=	xview-clients-3.2.1
CATEGORIES=	x11-toolkits

DEPENDS=        ${PORTSDIR}/x11-toolkits/xview-lib:install

WRKSRC=      	${WRKDIRPREFIX}${.CURDIR}/../xview-config/work/xview3.2p1-X11R6/clients
EXTRACT_ONLY=	# empty
USE_X_PREFIX=	yes

do-fetch:

post-configure:
	(cd $(WRKSRC)/..; $(MAKE) SUBDIRS=clients depend)

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
