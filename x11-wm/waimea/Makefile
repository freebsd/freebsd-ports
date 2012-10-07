# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	waimea
PORTVERSION=	0.4.0
PORTREVISION=	10
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	An X11 window manager designed for maximum efficiency

RUN_DEPENDS=	${LOCALBASE}/bin/Esetroot:${PORTSDIR}/x11/eterm

DEPRECATED=	Development ceased
EXPIRATION_DATE=	2012-11-05

USE_BZIP2=	yes
USE_XORG=	xft
USE_PERL5_RUN=	yes

GNU_CONFIGURE=	yes

MAN1=		waimea.1

OPTIONS_DEFINE= PIXMAP DITHER
OPTIONS_DEFAULT=	PIXMAP
PIXMAP_DESC=	Build with pixmap textures support
DITHER_DESC=	=Enable ordered pseudocolor dithering

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIXMAP}
USE_EFL+=	imlib2
.endif

.if ${PORT_OPTIONS:MDITHER}
CONFIGURE_ARGS+=	--enable-ordered-pseudo
.endif

.include <bsd.port.mk>
