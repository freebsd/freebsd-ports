# New ports collection makefile for:	wdm
# Version required:	1.0
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.17 1999/01/18 06:43:02 asami Exp $

DISTNAME=	wdm-1.0
CATEGORIES=	x11 windowmaker
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/contrib/srcs/utils/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/contrib/srcs/utils/ \
		http://www.de.freebsd.org/de/gif/bsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPIC}

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libPropList.a:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	wdm
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} CPPFLAGS=-I${PREFIX}/include \
		CFLAGS="${CFLAGS} -DHAS_SETUSERCONTEXT"
CONFIGURE_ARGS=	--with-gfx-libs="-L${PREFIX}/lib -L${LOCALBASE}/lib -lgif" \
	--with-gfx-incs="-I${LOCALBASE}/include" \
	--with-tiff-libs="-ljpeg" \
	--with-logdir=/var/log --with-runlockdir=/var/run \
	--with-wdmdir=${PREFIX}/lib/X11/wdm --with-Logo=Earth200x130.xpm \
	--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
	--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin \
	--with-wmlist=wmaker:afterstep:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

MAN1=	wdm.1 wdmLogin.1

DAEMONPIC=	daemon1-HQ-1280x960.jpg

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${DAEMONPIC} ${PREFIX}/lib/X11/wdm/pixmaps

.include <bsd.port.mk>
