# New ports collection makefile for:	waimea
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	waimea
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	waimea

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An X11 window manager designed for maximum efficiency

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	${X11BASE}/bin/Esetroot:${PORTSDIR}/x11/eterm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5_RUN=	yes

GNU_CONFIGURE=	yes

MAN1=		waimea.1

OPTIONS=	PIXMAP "Build with pixmap textures support" on \
		DITHER "Enable ordered pseudocolor dithering" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PIXMAP)
LIB_DEPENDS+=	Imlib2.3:${PORTSDIR}/graphics/imlib2
.endif

.if defined(WITH_DITHER)
CONFIGURE_ARGS+=	--enable-ordered-pseudo
.endif

.include <bsd.port.post.mk>
