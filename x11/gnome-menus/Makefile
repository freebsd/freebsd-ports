# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-menus/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gnome-menus
PORTVERSION=	3.10.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

USES=		gettext gmake libtool pathfix pkgconfig python tar:xz
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
	    	${WRKSRC}/util/Makefile.in

post-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/etc/xdg/menus/ 
	@${INSTALL_DATA} ${WRKSRC}/layout/gnome-applications.menu \
		${STAGEDIR}${PREFIX}/etc/xdg/menus/gnome-applications.menu
	@${INSTALL_DATA} ${WRKSRC}/KDE.directory \
		${STAGEDIR}${PREFIX}/share/desktop-directories

.include <bsd.port.mk>
