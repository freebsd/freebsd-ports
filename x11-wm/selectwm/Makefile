# New ports collection makefile for:   selectwm
# Date created:        13 January 2004
# Whom:                Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	selectwm
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://ordiluc.net/selectwm/

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	A GTK application to let you select a window manager when starting X

MAN1=		selectwm.1

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/selectwm share/locale/fr/LC_MESSAGES/selectwm.mo

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,${CFLAGS},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,^CFLAGS =,CFLAGS +=,' -e 's,-O2,,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
