# New ports collection makefile for:	kappdock
# Date created:				6 January 2001
# Whom:					Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	kappdock
PORTVERSION=	0.46.1
PORTREVISION=	1
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.Informatik.Uni-Oldenburg.DE/~bigboss/kappdock/
DISTNAME=	${PORTNAME}-0.46-1
WRKSRC=		${WRKDIR}/${PORTNAME}-0.46

MAINTAINER=	jeremy@external.org
COMMENT=	A dock-like applet for KDE3

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--enable-threads \
		--disable-closure
MAKE_ENV=	${CONFIGURE_ENV}
USE_GMAKE=	yes

.include <bsd.port.mk>
