# New ports collection makefile for:	gnome-menus
# Date created:				30 November 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-menus/Makefile,v 1.100 2009/10/18 23:13:39 marcus Exp $
#

PORTNAME=	gnome-menus
PORTVERSION=	2.28.0.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack glib20 ltverhack
USE_AUTOTOOLS=	libtool:22
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu||' \
		${WRKSRC}/layout/Makefile.in
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/util/test-menu-spec.c
	@${REINPLACE_CMD} -e 's|/usr/share/gnome|${LOCALBASE}/share/gnome|g' \
		${WRKSRC}/layout/applications.menu \
		${WRKSRC}/layout/settings.menu
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/simple-editor/GMenuSimpleEditor/menutreemodel.py
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
	    	${WRKSRC}/util/Makefile.in

post-install:
	@${INSTALL_DATA} ${WRKSRC}/layout/applications.menu \
		${PREFIX}/etc/xdg/menus/gnome-applications.menu
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory \
		${PREFIX}/share/desktop-directories

.include <bsd.port.mk>
