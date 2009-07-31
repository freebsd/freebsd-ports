# New ports collection makefile for:	waimea
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	waimea
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An X11 window manager designed for maximum efficiency

RUN_DEPENDS=	${LOCALBASE}/bin/Esetroot:${PORTSDIR}/x11/eterm

USE_BZIP2=	yes
USE_XORG=	xft
USE_PERL5_RUN=	yes

GNU_CONFIGURE=	yes

MAN1=		waimea.1

OPTIONS=	PIXMAP "Build with pixmap textures support" on \
		DITHER "Enable ordered pseudocolor dithering" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PIXMAP)
USE_EFL+=	imlib2
.endif

.if defined(WITH_DITHER)
CONFIGURE_ARGS+=	--enable-ordered-pseudo
.endif

.include <bsd.port.post.mk>
