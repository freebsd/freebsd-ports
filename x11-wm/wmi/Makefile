# New ports collection makefile for:   WMI
# Date created:        6 May 2004
# Whom:                Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	wmi
PORTVERSION=	10
CATEGORIES=	x11-wm
MASTER_SITES=	http://suckless.org/download/

MAINTAINER=	wxs@atarininja.org
COMMENT=	A window manager designed to be like Ion and LarsWM

DEPRECATED=	This port is unsupported by the author.  Please use x11-wm/wmii instead.
EXPIRATION_DATE=	2007-01-15

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
