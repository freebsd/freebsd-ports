# New ports collection makefile for:	ccsm
# Date created:		2007-08-17
# Whom:			Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ccsm
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	A Python/GTK based settings manager for CompizConfig

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:${PORTSDIR}/x11-wm/compizconfig-python

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes

INSTALLS_EGGINFO=	yes

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
