# New ports collection makefile for:	ecore
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	0.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A core event abstraction library

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/libecore.so.0

.include <bsd.port.mk>
