# Created by: vanilla
# $FreeBSD$

PORTNAME=	enlightenment-docs
PORTVERSION=	0.16.8.0.2
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF/enlightenment/e16-docs/${PORTVERSION}
DISTNAME=	e16-docs-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Data files of enlightenment DOX

RUN_DEPENDS=	${LOCALBASE}/bin/e16:${PORTSDIR}/x11-wm/e16

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
DATADIR=	${PREFIX}/share/e16

NO_STAGE=	yes
.include <bsd.port.mk>
