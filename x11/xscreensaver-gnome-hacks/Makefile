# New ports collection makefile for:	xscreensaver-gnome-hacks
# Date created:				12 September 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xscreensaver-gnome-hacks
PORTREVISION=	1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Screensaver modules for use with xscreensaver and gnome-screensaver

MASTERDIR=	${.CURDIR}/../xscreensaver-gnome
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS=	xscreensaver-[0-9]* xscreensaver-gnome-[0-9]*

OPTIONS=	ALL_FORTUNES "Enable support for all fortunes" off

EXTRA_PATCHES=	${FILESDIR}/extra-patch-nodriver

SS_SCRIPTS=	xscreensaver-getimage-desktop xscreensaver-getimage-file \
		xscreensaver-getimage xscreensaver-getimage-video \
		xscreensaver-text

MAN1=		xscreensaver-getimage-desktop.1 xscreensaver-getimage-file.1 \
		xscreensaver-getimage-video.1 xscreensaver-getimage.1 \
		xscreensaver-text.1

post-build:
	@cd ${WRKSRC}/driver && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} xscreensaver-getimage

post-install-slave:
	${MKDIR} ${PREFIX}/bin
.for sf in ${SS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/driver/${sf} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driver/${sf}.man \
		${MAN1PREFIX}/man/man1/${sf}.1
.endfor

.include "${MASTERDIR}/Makefile"
