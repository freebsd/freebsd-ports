# New ports collection makefile for:    v
# Date created:         8 Feb 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	v
PORTVERSION=	1.19
CATEGORIES=	x11-toolkits devel graphics
MASTER_SITES=	ftp://ftp.ntua.gr/pub/X11/v/old/ \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/programming/objectcentral/old/

MAINTAINER=	dburr@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		compiler error in function fixup_memory_subreg
.endif

WRKSRC=		${WRKDIR}/v

USE_X_PREFIX=	YES
USE_GMAKE=	YES
MAKE_ENV=	INSTALLDIR=${PREFIX} HOMEV=${WRKSRC}

do-configure:
	${CP} ${WRKSRC}/ConfigX.mk ${WRKSRC}/Config.mk

pre-build:
	${MKDIR} ${WRKSRC}/obj/bsd ${WRKSRC}/objm/bsd ${WRKSRC}/lib/bsd ${WRKSRC}/bin/bsd

post-install:
	${RANLIB} ${PREFIX}/lib/libV.a
.ifdef NOPORTDOCS
	@${ECHO_MSG} "==> Extra documentation WILL NOT be installed."
.else
	@${ECHO_MSG} "==> Installing extra docs under ${PREFIX}/share/doc/v..."
	${MKDIR} ${PREFIX}/share/doc/v
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/v
	find ${PREFIX}/share/doc/v -type d -exec ${CHMOD} 755 {} \;
	find ${PREFIX}/share/doc/v -type f -exec ${CHMOD} 644 {} \;
	@${ECHO_MSG} "==> Extra docs installed.  Note, you will need *tex to read 'em."
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
