# New ports collection makefile for:   SlingShot
# Version required:    2.1
# Date created:        5 March 1997
# Whom:                pgiffuni@FPS.biblos.unal.edu.co
#
# $Id$
#

DISTNAME=	SlingShot2.1
PKGNAME=	slingshot-2.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11/xview-lib

WRKSRC=		$(WRKDIR)/sspkg2.1
USE_X11=	yes
USE_GMAKE=	yes
MAKE_ENV=       OPENWINHOME=$(X11BASE)

pre-patch:
	${CP} $(WRKSRC)/config.sunos4x $(WRKSRC)/config.fbsd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/SlingShot
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/SlingShot
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${PREFIX}/share/doc/SlingShot
.endif

.include <bsd.port.mk>
