# New ports collection makefile for:	wmbutton
# Version required:		0.4
# Date created:			10 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmbutton-0.4
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www-personal.ksu.edu/~ehflora/wmbutton/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

do-build:
	(cd ${WRKSRC} && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbutton ${PREFIX}/bin

post-install:
	@${ECHO} "===>   Installing .wmbutton as ${PREFIX}/share/examples/wmbutton/wmbutton"
	@${ECHO} "===>   Modify if you wish and copy to ~/.wmbutton"
	@${MKDIR} ${PREFIX}/share/examples/wmbutton && ${CHMOD} a+rx ${PREFIX}/share/examples/wmbutton
	${INSTALL_DATA} ${WRKSRC}/.wmbutton ${PREFIX}/share/examples/wmbutton/wmbutton
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/wmbutton"
	@${ECHO} "===>   Please read it for usage instructions"
	@${MKDIR} ${PREFIX}/share/doc/wmbutton && ${CHMOD} a+rx ${PREFIX}/share/doc/wmbutton
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmbutton

.include <bsd.port.mk>
