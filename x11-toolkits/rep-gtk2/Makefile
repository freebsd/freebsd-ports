# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk2
PORTVERSION=	0.17
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/0.17
DISTNAME=	rep-gtk-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+-2 binding for rep Lisp interpreter

LIB_DEPENDS=	rep.12:${PORTSDIR}/lang/librep

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libglade2
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libglade
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=		libgnomeui
CONFIGURE_ARGS+=	--with-gnome
PKGNAMESUFFIX=		-gnome
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

.include <bsd.port.post.mk>
