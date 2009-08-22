# New ports collection makefile for:	tile
# Date created:		18 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tile
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/tktable/${PORTNAME}/${PORTNAME}-0-8-2

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Themed widget set for Tk

USE_TK=		84+

USE_AUTOTOOLS=	autoconf:262

GNU_CONFIGURE=	yes
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG}

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--exec-prefix=${PREFIX} --enable-shared
CONFIGURE_ENV+=	TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" \
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"

pre-configure:
	@${REINPLACE_CMD} -e "s/package require Tcl 8\../package require Tcl ${TCL_VER}/g" \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
