# New ports collection makefile for:	idesk
# Date created:		16 February 2003
# Whom:			Sascha Holzleiter <sascha@root-login.org>
#
# $FreeBSD$
#

PORTNAME=	idesk
PORTVERSION=	0.7.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Place launch icons and background directly on your desktop

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	imlib2-config:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CXXFLAGS+=	`imlib2-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/idesk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
		@${SED} -e 's:%%PREFIX%%:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.mk>
