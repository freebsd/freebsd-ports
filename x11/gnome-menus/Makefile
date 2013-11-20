# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-menus3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-menus
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack introspection:build \
		ltverhack
USE_AUTOTOOLS=	libtool
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu||' \
		${WRKSRC}/layout/Makefile.in
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/util/test-menu-spec.c
	@${REINPLACE_CMD} -e 's|/usr/share/gnome|${LOCALBASE}/share/gnome|g' \
		${WRKSRC}/layout/applications.menu
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/simple-editor/GMenuSimpleEditor/menutreemodel.py
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
	    	${WRKSRC}/util/Makefile.in

post-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/etc/xdg/menus/ 
	@${INSTALL_DATA} ${WRKSRC}/layout/applications.menu \
		${STAGEDIR}${PREFIX}/etc/xdg/menus/gnome-applications.menu
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory \
		${STAGEDIR}${PREFIX}/share/desktop-directories
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnome-menu-3.so.0

.include <bsd.port.mk>
