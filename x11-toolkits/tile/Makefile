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

USES=		autoreconf tk:tea

CONFIGURE_ENV+=	TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" \
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"

pre-configure:
	@${REINPLACE_CMD} -e "s/package require Tcl 8\../package require Tcl ${TCL_VER}/g" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
