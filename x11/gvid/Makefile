# Ports collection Makefile for:	gvid
# Date created:				5 June 2000
# Whom:			Scott A. Moberly <smoberly@xavier.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	gvid
PORTVERSION=	0.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://kvand.mit.edu/kvand/gVid/ \
		ftp://ftp.proxad.net/mirrors/ftp.linuxberg.com/files/gnome/xwin/ \
		ftp://ftp.sunsite.auc.dk/disk1/linuxberg.com/files/gnome/xwin/ \
		ftp://ftp.infomagic.com/pub/mirrors/tucows/mlinux/files/gnome/xwin/ \
		ftp://ftp.uni-c.dk/mirrors/mirror.linuxberg.com/files/gnome/xwin/

MAINTAINER=	smoberly@xavier.dyndns.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gnome.4:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes

MAKE_ENV=	MKDIR="${MKDIR}"

ALL_TARGET=	gvid

.include <bsd.port.mk>
