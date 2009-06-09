# New ports collection makefile for:	xview-clients
# Date created:         22 November 1994
# Whom:                 ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview-clients
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.efd.lth.se/pub/X11/ \
		ftp://ftp.uni-heidelberg.de/pub/X11/contrib/libraries/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	xview3.2p1-X11R6
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenLook applications and man pages

PATCH_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../xview:patch
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
USE_XORG=	x11 xext
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../xview/work/${DISTNAME}
ALL_TARGET=	Clients

MAN1=		clock.1 cmdtool.1 olwm.1 olwmslave.1 shelltool.1
MANCOMPRESSED=	yes

do-install:
	@cd ${WRKSRC}/clients; ${MAKE} install install.man

.include <bsd.port.mk>
