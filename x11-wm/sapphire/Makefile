# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION=	0.15.6
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-extract:

post-patch:
	${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/data.inst
.for i in data/menu/default configure data.inst src/sapphire.hh
	${PERL} -pi -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${i}
.endfor
	${CP} ${WRKSRC}/data.inst ${WRKSRC}/sapphire.inst

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sapphire.inst ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/sapphire/menu
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu
	# so the sapphire-themes port can restore the original menu when the
	# themes are de-installed
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu/default.orig
	@${MKDIR} ${PREFIX}/share/sapphire/themes
	${INSTALL_DATA} ${WRKSRC}/data/themes/*.theme ${PREFIX}/share/sapphire/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sapphire
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sapphire
.endif

.include <bsd.port.mk>
