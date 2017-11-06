# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-menus
PORTVERSION=	1.18.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix pkgconfig \
		python:2.7 tar:xz
USE_GNOME=	glib20 intltool introspection:buid
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

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
