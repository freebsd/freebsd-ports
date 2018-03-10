# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gtkglext
PORTVERSION=	1.1.0
PORTREVISION=	13
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtkglext-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for GtkGLExt

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:graphics/py-PyOpenGL@${FLAVOR}
LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:graphics/py-PyOpenGL@${FLAVOR}

USES=		gmake libtool pathfix pkgconfig python:2.7 tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/gtk/gtkgl/_gtkgl.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/gtk/gdkgl/_gdkgl.so

.include <bsd.port.mk>
