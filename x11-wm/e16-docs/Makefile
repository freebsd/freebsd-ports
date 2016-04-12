# Created by: vanilla
# $FreeBSD$

PORTNAME=	e16-docs
PORTVERSION=	0.16.8.0.2
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF/enlightenment/e16-docs/${PORTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Data files of enlightenment DOX

RUN_DEPENDS=	${LOCALBASE}/bin/e16:x11-wm/e16

USES=		gmake
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd
DATADIR=	${PREFIX}/share/e16

.include <bsd.port.mk>
