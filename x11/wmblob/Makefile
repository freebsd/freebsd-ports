# New ports collection makefile for:	wmblob
# Date created:				Thu Feb  6 12:24:23 MSK 2003
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	wmblob
PORTVERSION=	0.0.2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://dockapps.org/files/155/205/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Showing moving blobs

PLIST_FILES=	bin/wmblob
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_BZIP2=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmblob ${PREFIX}/bin

.include <bsd.port.mk>
