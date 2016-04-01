# Created by: marc@informatik.uni-bremen.de
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gtk2/Makefile,v 1.78 2011/04/01 12:35:27 kwm Exp $

PORTNAME=	gtk
PORTVERSION=	2.24.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	GNOME/sources/pygtk/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2
DISTNAME=	pygtk-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of Python bindings for GTK+

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:graphics/py-cairo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:graphics/py-cairo

USES=		gettext gmake libtool pathfix pkgconfig python:2 tar:bzip2
USE_GNOME=	libglade2 pygobject
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_VERSION}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-docs

DOCSDIR=	${PREFIX}/share/doc/py-gtk
EG_SRC_DIR=	${WRKSRC}/examples
EXAMPLESDIR=	${PREFIX}/share/examples/py-gtk

CONFLICTS=	py*-gtk-0*

OPTIONS_DEFINE=	NUMPY DOCS EXAMPLES
NUMPY_DESC=	Numpy support (pulls in lang/gcc)

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
LDFLAGS+=		-lpthread
.else
CONFIGURE_ARGS+=	--disable-thread
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${RM} ${WRKSRC}/examples/pygtk-demo/pygtk-demo.in
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${EG_SRC_DIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MAPPING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THREADS ${STAGEDIR}${DOCSDIR}
.endif
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gtk-2.0/gtk/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gtk-2.0/*.so

.include <bsd.port.mk>
