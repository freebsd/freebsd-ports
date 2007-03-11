# New ports collection makefile for:	elicit
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	elicit
PORTVERSION=	20070223
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Screen zoomer/color picker for e17

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	ecore edb eet edje evas imlib2
USE_EFL_ESMART=	trans_x11

.include <bsd.port.pre.mk>
.if ${ARCH} == "ia64"
BROKEN=		edje is broken on ia64
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
