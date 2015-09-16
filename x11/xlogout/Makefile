# $FreeBSD$

PORTNAME=	xlogout
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tu-darmstadt.de/pub/X11/other/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Simple logout button

DEPRECATED=	Useless cruft from 1989
EXPIRATION_DATE=2015-09-26

USES=		imake tar:Z
WRKSRC=		${WRKDIR}/xlogout
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

PLIST_FILES=	bin/xlogout \
		lib/X11/app-defaults/XLogout \
		man/man1/xlogout.1.gz

.include <bsd.port.mk>
