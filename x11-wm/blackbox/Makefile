# New ports collection makefile for:	Blackbox
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.70.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blackboxwm

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A small and fast window manager for X11R6

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	boxtools-*

PORTDOCS=	AUTHORS COMPLIANCE ChangeLog LICENSE README RELNOTES TODO
MAN1=		blackbox.1

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes
USE_GCC=	3.3+

post-patch:
	@${REINPLACE_CMD} -e 's#-pedantic##' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's# bsetroot.1 bsetbg.1##' ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
