# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	terminology
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	EFL Terminal Emulator

LICENSE=	BSD

USES=		pkgconfig tar:bzip2
DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_EFL=	eina eet evas ecore edje emotion elementary
USE_EFL_ECORE=	imf imf_evas input ipc

.include <bsd.port.mk>
