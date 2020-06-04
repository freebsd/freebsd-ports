# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-menus
PORTVERSION=	1.22.1
PORTREVISION=	1
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

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		python tar:xz
USE_GNOME=	glib20 intltool introspection:buid
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
