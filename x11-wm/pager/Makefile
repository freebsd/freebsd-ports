# New ports collection makefile for:		pager
# Date created:					November 20 2002
# Whom:						Michael Ebert <ebert@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	pager
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://dapfy.bei.t-online.de/sawfish/pager/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ebert@informatik.unibw-muenchen.de
COMMENT=	A pager for sawfish without GNOME

BUILD_DEPENDS=	${X11BASE}/bin/sawfish:${PORTSDIR}/x11-wm/sawfish2
RUN_DEPENDS=	${X11BASE}/bin/sawfish:${PORTSDIR}/x11-wm/sawfish2

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
USE_X_PREFIX=	yes

SAWFISH_VERSION=	`${X11BASE}/bin/sawfish --version 2>&1 | \
			${SED} 's/^.*version[ ]*\([0-9.]*\).*/\1/'`

PLIST_SUB+=	SAWFISH_VERSION="${SAWFISH_VERSION}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
#	doesn't work correct with the compiled .jl file at the moment
#	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jlc \
#		${PREFIX}/share/sawfish/${SAWFISH_VERSION}/lisp/sawfish/wm/ext
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jl \
		${PREFIX}/share/sawfish/${SAWFISH_VERSION}/lisp/sawfish/wm/ext
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
