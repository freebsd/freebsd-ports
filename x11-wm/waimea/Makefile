# New ports collection makefile for:	waimea
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	waimea
PORTVERSION=	0.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	waimea

MAINTAINER=	danfe@regency.nsu.ru

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5_RUN=	yes

GNU_CONFIGURE=	yes

MAN1=		waimea.1

.if !defined(WITHOUT_PIXMAP)
LIB_DEPENDS+=	Imlib2.1:${PORTSDIR}/graphics/imlib2
.endif

.if defined(WITH_XFT2)
LIB_DEPENDS+=	Xft2.2:${PORTSDIR}/x11-fonts/Xft
.endif

.include <bsd.port.mk>
