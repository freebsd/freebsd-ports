# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	deskshow
PORTVERSION=	20130510
PORTREVISION=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/e17/modules/
PKGNAMEPREFIX=	e-module-

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment module that minimizes windows to show the desktop

BUILD_DEPENDS=	enlightenment:x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:x11-wm/enlightenment

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig tar:bzip2
INSTALL_TARGET=	install-strip

.include "../enlightenment/Makefile.plist"

.include <bsd.port.mk>
