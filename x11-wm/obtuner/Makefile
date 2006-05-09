# New ports collection makefile for:	obtuner
# Date created:				2006-05-09
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	obtuner
PORTVERSION=	0.3
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Configurator for Openbox with keybinding and mousebinding editor

BUILD_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GNOME=	libxml2 glib20 gtk20

PLIST_FILES=	bin/obtuner

.include <bsd.port.mk>
