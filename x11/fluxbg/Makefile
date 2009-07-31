# New ports collection makefile for:	fluxbg
# Date created:				30 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluxbg
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background changer for fluxbox/blackbox

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/fbsetbg)
RUN_DEPENDS=	fbsetbg:${PORTSDIR}/x11-wm/fluxbox
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/src/fluxbg_conf.cc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
