# New ports collection makefile for:	xview-clients
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo (orig)
#
# $Id: Makefile,v 1.16 1999/01/11 09:46:58 asami Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-clients-3.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		${MASTER_SITE_XCONTRIB}

MAINTAINER=	ports@FreeBSD.ORG

DEPENDS=	${PORTSDIR}/x11-toolkits/xview:install

USE_X_PREFIX=	yes
EXTRACT_ONLY=	# empty
WRKSRC=		${PORTSDIR}/x11-toolkits/xview/work/${DISTNAME}
ALL_TARGET=	Clients
INSTALL_TARGET=	'SUBDIRS=clients' install install.man

MAN1=		clock.1 cmdtool.1 olwm.1 olwmslave.1 shelltool.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
