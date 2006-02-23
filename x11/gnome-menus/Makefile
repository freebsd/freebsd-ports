# New ports collection makefile for:	gnome-menus
# Date created:				30 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/x11/gnome-menus/Makefile,v 1.21 2005/09/08 18:04:51 marcus Exp $
#

PORTNAME=	gnome-menus
PORTVERSION=	2.12.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomevfs2 ltverhack
USE_AUTOTOOLS=  libtool:15
USE_PYTHON=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/gnome|${X11BASE}/share/gnome|g' \
		${WRKSRC}/layout/applications.menu \
		${WRKSRC}/layout/settings.menu
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory
	@${REINPLACE_CMD} -e s'|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/simple-editor/GMenuSimpleEditor/menutreemodel.py

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/desktop-directories
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory ${PREFIX}/share/gnome/desktop-directories

.include <bsd.port.mk>
