# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=	pkgconfig cmake gettext xfce tar:bzip2
USE_GNOME=	gtk20
USE_XFCE=	panel
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib

.include <bsd.port.mk>
