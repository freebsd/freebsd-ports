# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION= 	0.14.0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.sourceforge.net/sapphire/
DISTNAME=	${PORTNAME}-0.14.0-2

MAINTAINER=	trevor@jpj.net

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-extract:
	@${CP} ${WRKSRC}/data.inst ${WRKSRC}/sapphire.inst

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/sapphire.inst

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sapphire.inst ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/sapphire
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/sapphire
	@${MKDIR} ${PREFIX}/share/sapphire/menu
	${INSTALL_DATA} ${WRKSRC}/data/menu/* ${PREFIX}/share/sapphire/menu
	@${MKDIR} ${PREFIX}/share/sapphire/themes
	${INSTALL_DATA} ${WRKSRC}/data/themes/* ${PREFIX}/share/sapphire/themes
	@${MKDIR} ${PREFIX}/share/sapphire/wmconfig
	${INSTALL_DATA} ${WRKSRC}/data/wmconfig/* ${PREFIX}/share/sapphire/wmconfig

.include <bsd.port.mk>
