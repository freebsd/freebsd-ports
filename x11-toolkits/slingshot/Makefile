# New ports collection makefile for:   SlingShot
# Version required:    2.1
# Date created:        5 March 1997
# Whom:                Pedro Giffuni
#
# $Id: Makefile,v 1.4 1998/08/07 22:56:39 asami Exp $
#

DISTNAME=	SlingShot2.1
PKGNAME=	slingshot-2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	giffunip@asme.org

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11-toolkits/xview-lib

WRKSRC=		$(WRKDIR)/sspkg2.1
USE_X_PREFIX=	yes
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
