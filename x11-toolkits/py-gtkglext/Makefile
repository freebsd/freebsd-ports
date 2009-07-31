# New ports collection makefile for:   PyGtkGLExt
# Date created:                18 April 2003
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkglext
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtkglext-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python binding for GtkGLExt

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl
LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget pygtk2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
