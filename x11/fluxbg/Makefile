# New ports collection makefile for:	fluxbg
# Date created:				30 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluxbg
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background changer for fluxbox/blackbox

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2

.if !exists(${X11BASE}/bin/bsetbg) &&  \
    !exists(${X11BASE}/bin/fbsetbg) && \
    !exists(${X11BASE}/bin/fbsetbg-devel)
RUN_DEPENDS=	fbsetbg:${PORTSDIR}/x11-wm/fluxbox
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
