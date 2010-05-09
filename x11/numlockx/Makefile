# ex:ts=18
# New ports collection makefile for:  numlockx
# Whom:                               Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                       2003-09-09 16:05:29
#
# $FreeBSD$
#

PORTNAME=	numlockx
PORTVERSION=	1.2
CATEGORIES=	x11
MASTER_SITES=	http://ktown.kde.org/~seli/numlockx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turns on numlock in X

USE_XORG=	x11 xext xtst
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/numlockx

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
