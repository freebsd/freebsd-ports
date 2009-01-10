# New ports collection makefile for:	gegl
# Date created:		2008-04-14
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/gegl/Makefile,v 1.3 2008/07/26 15:50:04 ahze Exp $

PORTNAME=	gegl
PORTVERSION=	0.0.18
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gegl/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generic Graphics Library: graph based image processing framework

LIB_DEPENDS=	babl-0.0.0:${PORTSDIR}/x11/babl \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR
#		cdt.4:${PORTSDIR}/graphics/graphviz

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig gtk20 librsvg2 ltverhack
#USE_LUA=	5.1+
USE_SDL=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
