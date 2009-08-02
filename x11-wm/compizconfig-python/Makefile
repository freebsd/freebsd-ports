# New ports collection makefile for:	compizconfig-python
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compizconfig-python
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Python bindings for the compizconfig library

BUILD_DEPENDS=	\
	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:${PORTSDIR}/x11-wm/libcompizconfig \
	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack glib20
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
