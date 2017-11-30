# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-vte/Makefile,v 1.5 2010/09/30 09:15:43 kwm Exp $

PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface for VTE (Terminal widget)

MASTERDIR=	${.CURDIR}/../vte
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USES=		python:2.7
USE_GNOME=	intltool pygtk2 vte
USE_PYTHON=	flavors
CONFIGURE_ARGS=	--enable-python \
		--disable-Bsymbolic \
		--disable-freetypetest

.include "${MASTERDIR}/Makefile"
