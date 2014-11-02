# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	terminology
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/terminology/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	EFL Terminal Emulator

LICENSE=	BSD

USES=		pkgconfig tar:xz
DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_EFL=	eina eet evas ecore edje emotion elementary
USE_EFL_ECORE=	imf imf_evas input ipc

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
