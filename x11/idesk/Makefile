# New ports collection makefile for:	idesk
# Date created:		16 February 2003
# Whom:			Sascha Holzleiter <sascha@root-login.org>
#
# $FreeBSD$
#

PORTNAME=	idesk
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://idesk.timmfin.net/releases/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/

MAINTAINER=	sascha@root-login.org
COMMENT=	Place launch icons directly on your desktop

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib librsvg2

NO_WRKSUBDIR=	yes

CXXFLAGS+=	`imlib-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/idesk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
		@${SED} -e 's:%%PREFIX%%:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.mk>
