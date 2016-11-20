# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	terminology
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL Terminal Emulator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		compiler:c11 pkgconfig tar:xz

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
