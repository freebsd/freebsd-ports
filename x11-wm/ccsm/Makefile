# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ccsm
PORTVERSION=	0.8.4
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gettext gmake python:2.7 tar:bzip2
USE_GNOME=	intltool pygtk2

INSTALLS_ICONS=	yes

post-patch:
	${REINPLACE_CMD} 's,@python ,@${PYTHON_CMD} ,' ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --root=${STAGEDIR} --prefix=${PREFIX})

.include <bsd.port.mk>
