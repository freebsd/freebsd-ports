# New ports collection makefile for:	sisctrl
# Date created:				15 Aug 2004
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-settings
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/XFree86/nvidia-settings/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for XFree86/X.org NVidia driver

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes

PLIST_FILES=	bin/nvidia-settings

MAKE_ENV=	ROOT=${PREFIX}

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
