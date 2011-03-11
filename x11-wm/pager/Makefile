# New ports collection makefile for:		pager
# Date created:					November 20 2002
# Whom:						Michael Ebert <ebert@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	pager
PORTVERSION=	0.6
PORTREVISION=	12
CATEGORIES=	x11-wm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sawfish-pager
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pager for sawfish without GNOME

BUILD_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish
RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
USE_XORG=	x11

SAWFISH_VERSION=	`${LOCALBASE}/bin/sawfish --version 2>&1 | \
			${SED} 's/^.*version[ ]*\([0-9.]*\).*/\1/'`

PLIST_SUB+=	SAWFISH_VERSION="${SAWFISH_VERSION}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jl \
		${PREFIX}/share/sawfish/${SAWFISH_VERSION}/lisp/sawfish/wm/ext
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
