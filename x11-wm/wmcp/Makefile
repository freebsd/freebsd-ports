# New ports collection makefile for:	wmcp
# Version required:		1.2.6
# Date created:			10 February 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	wmcp-1.2.6
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.linuxbox.com/~bac/src/wmcp/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

pre-build:
	(cd ${WRKSRC} && ${GMAKE} clean)

do-build:
	(cd ${WRKSRC} && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcp ${PREFIX}/bin

.include <bsd.port.post.mk>
