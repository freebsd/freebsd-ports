# New ports collection makefile for:	wmakerconf
# Version required:			2.6.1
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

DISTNAME=	wmakerconf-2.6.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://ulli.linuxave.net/wmakerconf/

MAINTAINER=	dr@domix.de

RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker \
		rpm:${PORTSDIR}/misc/rpm \
		bunzip2:${PORTSDIR}/archivers/bzip2 \
		wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		PropList.2:${PORTSDIR}/devel/libPropList \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.3:${PORTSDIR}/graphics/png \
		wraster.3:${PORTSDIR}/x11-wm/windowmaker \
		wmfun.0:${PORTSDIR}/x11-wm/windowmaker
BUILD_DEPENDS=	bunzip2:${PORTSDIR}/archivers/bzip2 \
		wget:${PORTSDIR}/ftp/wget

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
