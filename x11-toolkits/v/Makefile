# New ports collection makefile for:    v
# Version required:     1.17
# Date created:         8 Feb 1998
# Whom:                 Donald Burr <dburr@POBoxes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/02/10 07:05:12 jkh Exp $
#

DISTNAME=	v-1.17
CATEGORIES=	x11 devel graphics
MASTER_SITES=	ftp://objectcentral.com/

MAINTAINER=	dburr@POBoxes.com

USE_X11=	YES

WRKSRC=		${WRKDIR}/v

USE_GMAKE=	YES

pre-build:
	${MKDIR} ${WRKSRC}/obj/bsd ${WRKSRC}/lib/bsd ${WRKSRC}/bin/bsd

do-install:
	cd ${WRKSRC} && ${GMAKE} installv PREFIX=${PREFIX}

post-install:
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
