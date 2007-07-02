# New ports collection makefile for:	xdm
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xdm
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X display manager

XORG_CAT=	app
USE_XORG=	xmu x11 xau xinerama xpm xdmcp xt xext xaw
MAKE_ENV=	EXAMPLESDIR=${EXAMPLESDIR}

MAN1=		xdm.1

CFFILES=	GiveConsole TakeConsole Xaccess Xreset Xresources \
		Xservers Xsession Xsetup_0 Xstartup Xwilling xdm-config

post-patch:
	${REINPLACE_CMD} -e "s,XDMCONFIGDIR,${PREFIX}/lib/X11/xdm,g" ${WRKSRC}/config/Xreset.cpp ${WRKSRC}/config/Xstartup.cpp

post-install:
.for f in ${CFFILES}
	${CP} -n ${EXAMPLESDIR}/$f ${PREFIX}/lib/X11/xdm/$f
.endfor

.include <bsd.port.mk>
