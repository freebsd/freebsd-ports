# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tile
PORTVERSION=	0.8.4.0
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/tktable/${PORTNAME}/${PORTNAME}-0-8-4-0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themed widget set for Tk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.terms

USE_TK=		84+

USE_AUTOTOOLS=	autoconf

GNU_CONFIGURE=	yes
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG}

NO_STAGE=	yes
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
