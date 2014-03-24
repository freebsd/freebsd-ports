# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	roxbg
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	x11 deskutils
MASTER_SITES=	http://vvelox.net/programs/unix/x11/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	tool for setting the background in rox using a simple command.

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/roxbg

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/roxbg

.include <bsd.port.mk>
