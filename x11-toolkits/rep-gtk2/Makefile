# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rep-gtk2
PORTVERSION=	0.90.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.tuxfamily.org/librep/rep-gtk/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Archive
DISTNAME=	rep-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-2 binding for rep Lisp interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	librep.so:${PORTSDIR}/lang/librep

USES=		tar:xz gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
