# New ports collection makefile for:	wmbutton
# Date created:			10 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmbutton
PORTVERSION=	0.4
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that displays 9 buttons to run apps of your choice

USE_X_PREFIX=	yes
USE_XPM=	yes

do-build:
	@(cd ${WRKSRC} && make)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmbutton ${PREFIX}/bin

post-install:
	@${ECHO} "===>   Installing .wmbutton as ${PREFIX}/share/examples/wmbutton/wmbutton"
	@${ECHO} "===>   Modify if you wish and copy to ~/.wmbutton"
	@${MKDIR} ${PREFIX}/share/examples/wmbutton && ${CHMOD} a+rx ${PREFIX}/share/examples/wmbutton
	@${INSTALL_DATA} ${WRKSRC}/.wmbutton ${PREFIX}/share/examples/wmbutton/wmbutton
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/wmbutton"
	@${ECHO} "===>   Please read it for usage instructions"
	@${MKDIR} ${PREFIX}/share/doc/wmbutton && ${CHMOD} a+rx ${PREFIX}/share/doc/wmbutton
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmbutton

.include <bsd.port.mk>
