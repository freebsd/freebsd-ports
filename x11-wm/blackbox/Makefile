# New ports collection makefile for:	Blackbox
# Date created:				June 15, 1998
# Whom:					Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.70.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}wm/${PORTNAME}wm/Blackbox%20${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A small and fast window manager for X11R6

LICENSE=	MIT

CONFLICTS=	boxtools-*

PORTDOCS=	AUTHORS COMPLIANCE ChangeLog README RELNOTES TODO
MAN1=		blackbox.1

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GNOME=	gnomehack pkgconfig
USE_XORG=	x11 xft

post-patch:
	@${REINPLACE_CMD} -e 's#-pedantic##' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's# bsetroot.1 bsetbg.1##' \
		${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${DOCSDIR}
.endif

.include <bsd.port.mk>
