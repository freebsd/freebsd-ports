# New ports collection makefile for:	xview-clients
# Date created:         22 November 1994
# Whom:                 ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview-clients
PORTVERSION=	3.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		${MASTER_SITE_XCONTRIB}
# former for ${MASER_SITE_LOCAL}, latter for ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS .
DISTNAME=	xview3.2p1-X11R6

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	OpenLook applications and man pages

DEPENDS=	${PORTSDIR}/x11-toolkits/xview:install

USE_X_PREFIX=	yes
EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../xview/work/${DISTNAME}
ALL_TARGET=	Clients
INSTALL_TARGET=	'SUBDIRS=clients' install install.man

MAN1=		clock.1 cmdtool.1 olwm.1 olwmslave.1 shelltool.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
