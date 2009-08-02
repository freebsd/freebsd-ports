# New ports collection makefile for:	babl
# Date created:		2008-04-14
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	babl
PORTVERSION=	0.0.22
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	babl/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dynamic pixel format conversion library

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig gnomehack ltverhack
USE_GMAKE=	yes

.include <bsd.port.mk>
