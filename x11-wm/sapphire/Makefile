# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION=	0.14.2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://sapphire.sourceforge.net/themes/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${THEMES_SRC}

MAINTAINER=	trevor@jpj.net

RUN_DEPENDS=	xsetbg:${PORTSDIR}/graphics/xli

DIST_SUBDIR=	sapphire

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

THEMES_SRC=	atomic.tar.gz bevel.tar.gz blues.tar.gz dtheater.tar.gz \
		klamath.tar.gz metal.tar.gz nocturne.tar.gz river.tar.gz \
		sapphire.tar.gz slate.tar.gz synopsis.tar.gz

post-extract:
	@${CP} ${WRKSRC}/data.inst ${WRKSRC}/sapphire.inst
	@${CP} ${WRKDIR}/*/*.theme ${WRKSRC}/data/themes
	@${CP} ${WRKDIR}/*/*.jpg ${WRKSRC}/data/themes

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/sapphire.inst

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sapphire.inst ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/sapphire/menu
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu
	@${MKDIR} ${PREFIX}/share/sapphire/themes
	${INSTALL_DATA} ${WRKSRC}/data/themes/*.theme ${PREFIX}/share/sapphire/themes
	@${MKDIR} ${PREFIX}/share/sapphire/themes/backgrounds
	${INSTALL_DATA} ${WRKSRC}/data/themes/*.jpg ${PREFIX}/share/sapphire/themes/backgrounds
	@${MKDIR} ${PREFIX}/share/sapphire/wmconfig
	${INSTALL_DATA} ${WRKSRC}/data/wmconfig/wmconf ${PREFIX}/share/sapphire/wmconfig
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sapphire
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sapphire
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
