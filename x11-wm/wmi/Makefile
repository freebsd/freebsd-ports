# New ports collection makefile for:   WMI
# Date created:        6 May 2004
# Whom:                Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	wmi
PORTVERSION=	9
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.berlios.de/wmi/

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	A window manager designed to be like Ion and LarsWM

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=	wmi.1 wmiremote.1
MAN5=	actions.conf.5 common.conf.5 session.conf.5 theme.conf.5

PLIST_FILES=	bin/wmi \
		bin/wmiremote

post-patch:
	@${REINPLACE_CMD} -e 's,-Os,,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,CXXFLAGS =,CXXFLAGS +=,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
