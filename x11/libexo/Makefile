# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <matt@bsdfly.org>
#
# $FreeBSD$
#

PORTNAME=	libexo
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DISTNAME=	exo-${PORTVERSION}

MAINTAINER=	matt@bsdfly.org
COMMENT=	Terminal library, extensions to Xfce by os-cillation

LIB_DEPENDS=	xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		dbus-1.1:${PORTSDIR}/devel/dbus

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GNOME=	glib20
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
.else
CONFIGURE_ARGS+=--disable-gtk-doc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/exo/Makefile.in

.include <bsd.port.mk>
