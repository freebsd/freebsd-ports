# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	20060926
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
DISTNAME=	e-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A very artistic X window manager

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_EFL=	imlib2 evas edje ecore embryo eet
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
