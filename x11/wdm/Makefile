# New ports collection makefile for:	wdm
# Version required:	0.11
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/09/04 07:17:26 tg Exp $

DISTNAME=	wdm-0.11
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/contrib/srcs/utils/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/contrib/srcs/utils/ \
		http://www.de.freebsd.org/de/gif/bsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPIC}

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		png\\.2\\.:${PORTSDIR}/graphics/png \
		tiff34\\.1:${PORTSDIR}/graphics/tiff34 \
		PropList\\.0\\.8:${PORTSDIR}/x11-wm/windowmaker

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	wdm
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} CPPFLAGS=-I${PREFIX}/include
CONFIGURE_ARGS=	--with-gfx-libs="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include" \
	--with-logdir=/var/log --with-runlockdir=/var/run \
	--with-WDMDIR=${PREFIX}/lib/X11/wdm \
	--with-DEFUSERPATH=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
	--with-DEFSYSTEMPATH=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin

MAN1=	wdm.1 wdmLogin.1

DAEMONPIC=	daemon1-HQ-1280x960.jpg

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${DAEMONPIC} ${PREFIX}/lib/X11/wdm/pixmaps

.include <bsd.port.mk>
