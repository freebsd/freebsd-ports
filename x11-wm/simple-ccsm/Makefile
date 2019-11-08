# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simple-ccsm
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gettext gmake gnome pkgconfig python:2.7 tar:bzip2
USE_GNOME=	intltool pygtk2

INSTALLS_ICONS=	yes

post-patch:
	${REINPLACE_CMD} 's,@python ,@${PYTHON_CMD} ,' ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --root=${STAGEDIR} --prefix=${PREFIX})

.include <bsd.port.mk>
