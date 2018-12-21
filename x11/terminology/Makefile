# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	terminology
PORTVERSION=	1.3.2
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL Terminal Emulator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
USES=		compiler:c11 meson pkgconfig tar:xz

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_MESON_TRUE=		nls
NLS_LDFLAGS=		-lintl

.include <bsd.port.mk>
