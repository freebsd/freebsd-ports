# New ports collection makefile for:	enity
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	enity
PORTVERSION=	20060926
CATEGORIES=	x11
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Create Etk dialogs using scripts

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	etk
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/enity

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
