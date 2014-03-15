# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ccsm
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python/GTK based settings manager for CompizConfig

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:${PORTSDIR}/x11-wm/compizconfig-python

USES=		gettext gmake tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	2

INSTALLS_EGGINFO=	yes

INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
