# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION=	0.14.2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org

DIST_SUBDIR=	sapphire

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-extract:
	@${CP} ${WRKSRC}/data.inst ${WRKSRC}/sapphire.inst

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/sapphire.inst

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sapphire.inst ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/sapphire/menu
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu
	# so the sapphire-themes port can restore the original menu when the
	# themes are de-installed
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu/default.orig
	@${MKDIR} ${PREFIX}/share/sapphire/themes
	${INSTALL_DATA} ${WRKSRC}/data/themes/*.theme ${PREFIX}/share/sapphire/themes
	@${MKDIR} ${PREFIX}/share/sapphire/wmconfig
	${INSTALL_DATA} ${WRKSRC}/data/wmconfig/wmconf ${PREFIX}/share/sapphire/wmconfig
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sapphire
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sapphire
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
