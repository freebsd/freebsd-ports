# New ports collection Makefile for: rxvt
# Version required:	2.16
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $Id: Makefile,v 1.10 1996/12/08 02:30:29 obrien Exp $
#

DISTNAME=	rxvt-2.16
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		ftp://ftp.jurai.net/users/winter/rxvt/distfiles/
MASTER_SITE_SUBDIR=	X11/xutils/terms

MAINTAINER=	winter@jurai.net

USE_X11=	yes
GNU_CONFIGURE=  yes
MAN1=		rxvt.1

post-install:
	/usr/sbin/chown root ${PREFIX}/bin/rxvt
	/bin/chmod 4755 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
