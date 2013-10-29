# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-menus/Makefile,v 1.110 2010/11/17 11:29:19 kwm Exp $

PORTNAME=	gnome-menus
PORTVERSION=	2.30.5
PORTREVISION=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack glib20 ltverhack
USES=		pkgconfig gettext
USE_AUTOTOOLS=	libtool
USE_PYTHON=	-2.7
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
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
