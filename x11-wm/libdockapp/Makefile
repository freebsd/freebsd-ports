# New ports collection makefile for:	DockApp Library
# Date created:		17 July 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdockapp
PORTVERSION=	0.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard library for Window Maker dock apps

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
