# New ports collection makefile for:    v
# Version required:     1.19
# Date created:         8 Feb 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/05/30 12:36:21 dburr Exp $
#

DISTNAME=	v-1.19
CATEGORIES=	x11 devel graphics
MASTER_SITES=	ftp://objectcentral.com/

MAINTAINER=	dburr@FreeBSD.ORG

WRKSRC=		${WRKDIR}/v

USE_X11=	YES
USE_GMAKE=	YES
MAKE_ENV=	INSTALLDIR=${PREFIX} HOMEV=${WRKSRC}

do-configure:
	${CP} ${WRKSRC}/ConfigX.mk ${WRKSRC}/Config.mk

pre-build:
	${MKDIR} ${WRKSRC}/obj/bsd ${WRKSRC}/objm/bsd ${WRKSRC}/lib/bsd ${WRKSRC}/bin/bsd

post-install:
	${RANLIB} ${PREFIX}/lib/libV.a
.ifdef NOPORTDOCS
	@echo "==> Extra documentation WILL NOT be installed."
.else
	@echo "==> Installing extra docs under ${PREFIX}/share/doc/v..."
	${MKDIR} ${PREFIX}/share/doc/v
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/v
	find ${PREFIX}/share/doc/v -type d -exec chmod 755 {} \;
	find ${PREFIX}/share/doc/v -type f -exec chmod 644 {} \;
	@echo "==> Extra docs installed.  Note, you will need *tex to read 'em."
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
