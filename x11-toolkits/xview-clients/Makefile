# New ports collection makefile for:	xview-clients
# Date created:         22 November 1994
# Whom:                 ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview-clients
PORTVERSION=	3.2.1.4.19c
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.physionet.org/physiotools/xview/src/ \
		http://komquats.com/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy
DISTNAME=	xview-3.2p1.4-19c
EXTRACT_ONLY=	# empty

MAINTAINER=	cy@FreeBSD.org
COMMENT=	OpenLook applications and man pages

CONFLICTS=	props-1.0

PATCH_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../xview:patch
CONFIGURE_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../xview:configure
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
USE_XORG=	x11 xext
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../xview/work/${DISTNAME}
ALL_TARGET=	Clients

MAN1=		clock.1 cmdtool.1 olwm.1 olwmslave.1 props.1 shelltool.1 \
		textedit.1
MANCOMPRESSED=	yes

do-install:
	@cd ${WRKSRC}/clients; ${MAKE} install install.man

.include <bsd.port.mk>
