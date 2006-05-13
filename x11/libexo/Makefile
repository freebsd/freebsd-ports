# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libexo
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DISTNAME=	exo-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal library, extensions to Xfce by os-cillation

LIB_DEPENDS=	xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
.else
CONFIGURE_ARGS+=--disable-gtk-doc
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--enable-python
USE_PYTHON=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/exo/Makefile.in

.include <bsd.port.mk>
