# New ports collection makefile for:	sisctrl
# Date created:				14 Aug 2004
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sisctrl
PORTVERSION=	0.0.20051202
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://www.winischhofer.net/sis/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for XFree86/X.org SiS driver

USE_XORG=	x11 ice xxf86vm xinerama xv xrandr xext sm
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --with-xv-path=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/sisctrl
MAN1=		sisctrl.1x

.include <bsd.port.mk>
