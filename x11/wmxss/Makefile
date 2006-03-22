# New ports collection makefile for:	wmxss
# Date created:		27 August 2002
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmxss
PORTVERSION=	0.1
CATEGORIES=	x11
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run xscreensaver modules inside a WindowMaker dock

PLIST_FILES=	bin/wmxss
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/Src

post-extract:
	@( cd ${WRKSRC} ; ${MAKE} clean ; ${RM} -f .nfs* )

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		${BUILD_WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
