# New ports collection makefile for:	kappdock
# Date created:				6 January 2001
# Whom:					Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	kappdock
PORTVERSION=	0.43
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.Informatik.Uni-Oldenburg.DE/~bigboss/kappdock/

MAINTAINER=	jeremy@external.org

LIB_DEPENDS=	kdeui.4:${PORTSDIR}/x11/kdelibs2 \
		intl.1:${PORTSDIR}/devel/gettext

INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure
MAKE_ENV=	${CONFIGURE_ENV}
USE_GMAKE=	yes

.include <bsd.port.mk>
