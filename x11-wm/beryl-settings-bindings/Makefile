# New ports collection makefile for:	beryl-settings-bindings
# Date created:				Jan 29 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-settings-bindings
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Beryl Settings Bindings

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/berylsettings.pc:${PORTSDIR}/x11-wm/beryl-core \
		${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11
USE_GNOME=	glib20 gnomehack
USE_PYTHON=	2.4+

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
