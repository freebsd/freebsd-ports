# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rep-gtk2
PORTVERSION=	0.90.8.1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Archive
DISTNAME=	rep-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-2 binding for rep Lisp interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	librep.so:${PORTSDIR}/lang/librep

USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
