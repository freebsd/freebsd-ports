# New ports collection makefile for:   libxdg-basedir
# Date created:                April 18, 2009
# Whom:                        Nikos Ntarmos <ntarmos@cs.uoi.gr>
#
# $FreeBSD$
#

PORTNAME=	libxdg-basedir
PORTVERSION=	1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://n.ethz.ch/student/nevillm/download/libxdg-basedir/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	An implementation of the XDG Base Directory specification

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE}

pre-configure:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
