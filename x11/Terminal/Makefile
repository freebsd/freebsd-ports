# New ports collection makefile for:	Terminal
# Date created:		23 October 2004
# Whom:			Matt Lancereau <matt@bsdfly.org>
#
# $FreeBSD$
#

PORTNAME=	Terminal
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/xfce-goodies/

MAINTAINER=	matt@bsdfly.org
COMMENT=	Terminal emulator for the X windowing system

LIB_DEPENDS=	exo-0.2:${PORTSDIR}/x11/libexo \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui

BROKEN=		Incomplete pkg-plist

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 vte
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAN1=		Terminal.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|	doc[	]*||' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/Terminal|${DOCSDIR}|g' \
		${WRKSRC}/doc/C/images/Makefile.in \
		${WRKSRC}/doc/C/Makefile.in \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
