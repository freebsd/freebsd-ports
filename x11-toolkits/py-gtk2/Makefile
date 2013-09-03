# Created by: marc@informatik.uni-bremen.de
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gtk2/Makefile,v 1.78 2011/04/01 12:35:27 kwm Exp $

PORTNAME=	gtk
PORTVERSION=	2.24.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygtk/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtk-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of Python bindings for GTK+

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo

LATEST_LINK=	py-gtk2
USE_BZIP2=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	libglade2 pygobject
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lintl" \
		PYTHON="${PYTHON_VERSION}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-docs

DOCSDIR=	${PREFIX}/share/doc/py-gtk
EG_SRC_DIR=	${WRKSRC}/examples
EXAMPLESDIR=	${PREFIX}/share/examples/py-gtk

CONFLICTS=	py*-gtk-0*

OPTIONS_DEFINE=	NUMPY
NUMPY_DESC=	Numpy support (pulls in gcc44)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNUMPY}
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
CONFIGURE_ARGS+=--enable-numpy
.else
CONFIGURE_ARGS+=--disable-numpy
.endif

#
# Use the same way as the Python port to determine if we want
# threading support.
#
.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-thread
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--disable-thread
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -type d -print | ${XARGS} ${CHMOD} 0555
	${FIND} ${EXAMPLESDIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THREADS ${DOCSDIR}
.endif

.include <bsd.port.mk>
