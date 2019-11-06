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
COMMENT=	Tool for setting the background in rox using a simple command

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/roxbg

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/roxbg

.include <bsd.port.mk>
