# New ports collection makefile for:	Terminal
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Terminal
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/xfce-goodies/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

LIB_DEPENDS=	exo-0.3:${PORTSDIR}/x11/libexo \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 vte intlhack
USE_X_PREFIX=	yes

MAN1=		Terminal.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|	doc[    ]*||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
