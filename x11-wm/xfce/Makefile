# New ports collection makefile for:	xfce
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION= 	3.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	${LOCALBASE}/bin/esdplay:${PORTSDIR}/audio/esound

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share \
		--with-xpm=${X11BASE}

MAN1=	xfbd.1 xfce.1 xfclock.1 xfgnome.1 xfhelp.1 xflock.1 xfmouse.1 \
	xfpager.1 xfprint.1 xfsound.1 xfterm.1 xftrash.1 xftree.1 xfwm.1 \
	xfmountdev.1

.include <bsd.port.mk>
