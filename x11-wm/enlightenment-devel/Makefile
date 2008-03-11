# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.999.042
PORTREVISION=	0
PORTEPOCH=	2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A very artistic X window manager

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_EFL=	imlib2 evas edje ecore embryo eet efreet edbus
USE_EFL_ECORE=	evas config file ipc con job txt imf imf_evas
USE_EFL_EVAS_LOADERS=	edb eet jpeg png
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
