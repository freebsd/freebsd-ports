# New ports collection makefile for:	examine
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	examine
PORTVERSION=	20060719
CATEGORIES=	x11
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Interface for configuring EFL applications

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore \
		ewl.0:${PORTSDIR}/x11-toolkits/ewl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_FILES=	bin/examine bin/exsh

.include <bsd.port.mk>
