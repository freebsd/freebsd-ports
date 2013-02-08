# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	terminology
PORTVERSION=	0.2.0
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.fr/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	EFL Terminal Emulator

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina eet evas ecore edje emotion elementary
USE_EFL_ECORE=	imf imf_evas input
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
