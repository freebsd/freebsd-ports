# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	1.3.2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=	pkgconfig cmake gettext tar:bzip2
USE_GNOME=	gtk20
USE_XFCE=	configenv garcon libexo libmenu libutil panel
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib

.include <bsd.port.mk>
