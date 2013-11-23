# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-menus
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack ltverhack
USE_GNOME=	glib20 gnomehier introspection:build
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/mate|${LOCALBASE}/share/mate|g' \
		${WRKSRC}/layout/mate-applications.menu \
		${WRKSRC}/layout/mate-settings.menu
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/KDE.directory > ${WRKSRC}/KDE.directory
	@${SED} -e 's|/usr/local|${LOCALBASE}|g' \
		< ${FILESDIR}/GNOME.directory > ${WRKSRC}/GNOME.directory

post-install:
	@${INSTALL_DATA} ${WRKSRC}/*.directory \
		${STAGEDIR}${PREFIX}/share/mate/desktop-directories/

.include <bsd.port.mk>
