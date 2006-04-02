# New ports collection makefile for:	enlightenment-docs
# Date created:				08 Aug 2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	enlightenment-docs
PORTVERSION=	0.16.8
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	e16-docs-${PORTVERSION}-0.02

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Data files of enlightenment DOX

RUN_DEPENDS=	${X11BASE}/bin/e16:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
DATADIR=	${PREFIX}/share/e16

.include <bsd.port.mk>
