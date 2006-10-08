# New ports collection makefile for:	examine
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	examine
PORTVERSION=	20060926
CATEGORIES=	x11
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Interface for configuring EFL applications

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore \
		ewl.0:${PORTSDIR}/x11-toolkits/ewl

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	ecore ewl

PLIST_FILES=	bin/examine bin/exsh

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
