# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg
PORTVERSION=	7.7
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org complete distribution metaport

NO_BUILD=	yes
NO_MTREE=	yes
NO_INSTALL=	yes

RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dri.pc:${PORTSDIR}/graphics/dri

# data
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xbitmaps.pc:${PORTSDIR}/x11/xbitmaps \
		${LOCALBASE}/lib/X11/icons/handhelds/cursors/X_cursor:${PORTSDIR}/x11-themes/xcursor-themes

OPTIONS_DEFINE=	DOCS

DOCS_RUN_DEPENDS+=	${LOCALBASE}/share/doc/xorg-docs/README.xml:${PORTSDIR}/x11/xorg-docs

# app, lib, font, driver
RUN_DEPENDS+=	xorg-apps>0:${PORTSDIR}/x11/xorg-apps \
		xorg-libraries>0:${PORTSDIR}/x11/xorg-libraries \
		xorg-fonts>0:${PORTSDIR}/x11-fonts/xorg-fonts \
		xorg-drivers>0:${PORTSDIR}/x11-drivers/xorg-drivers

.if defined(XORG_COMPLETE)
RUN_DEPENDS+=	Xnest:${PORTSDIR}/x11-servers/xorg-nestserver \
		Xdmx:${PORTSDIR}/x11-servers/xorg-dmx \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
.endif

.include <bsd.port.mk>
