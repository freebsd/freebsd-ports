# New ports collection makefile for:	vdesk
# Date created:				2002-05-13
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	vdesk
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://azz.us-lot.org/files/

MAINTAINER=	trevor@FreeBSD.org

PLIST=		${WRKDIR}/pkg-plist
RESTRICTED=	"no license"
NO_CDROM=	${RESTRICTED}
NO_FTP=		${RESTRICTED}
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/vdesk

pre-install:
	${ECHO_CMD} bin/vdesk > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vdesk ${PREFIX}/bin

.include <bsd.port.mk>
