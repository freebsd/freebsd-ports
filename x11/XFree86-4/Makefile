# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION=	4.2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

LIB_DEPENDS=	Xft.1:${PORTSDIR}/x11/XFree86-4-libraries
RUN_DEPENDS=	xvinfo:${PORTSDIR}/x11/XFree86-4-clients \
	${X11BASE}/lib/X11/doc/ddx.TXT:${PORTSDIR}/x11/XFree86-4-documents \
	${FONT100DPI}:${PORTSDIR}/x11-fonts/XFree86-4-font100dpi \
	${FONT75DPI}:${PORTSDIR}/x11-fonts/XFree86-4-font75dpi \
	${FONTCYR}:${PORTSDIR}/x11-fonts/XFree86-4-fontCyrillic \
	${FONTDEFAULT}:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps \
	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
	${X11BASE}/bin/xfs:${PORTSDIR}/x11-servers/XFree86-4-FontServer \
	${X11BASE}/bin/xf86cfg:${PORTSDIR}/x11-servers/XFree86-4-Server \
	${X11BASE}/bin/Xwrapper-4:${PORTSDIR}/x11/wrapper


MAINTAINER=	anholt@FreeBSD.org

NO_BUILD=	yes
LATEST_LINK=	XFree86
FONT100DPI=	${X11BASE}/lib/X11/fonts/100dpi/UTBI__10-ISO8859-1.pcf.gz
FONT75DPI=	${X11BASE}/lib/X11/fonts/75dpi/UTBI__10-ISO8859-1.pcf.gz
FONTCYR=	${X11BASE}/lib/X11/fonts/cyrillic/crox1c.pcf.gz
FONTDEFAULT=	${X11BASE}/lib/X11/fonts/misc/cursor.pcf.gz
FONTSCALE=	${X11BASE}/lib/X11/fonts/PEX/Roman.phont

.if make(package)
DEPENDS_TARGET="package"
.endif
.undef NOCLEANDEPENDS

do-install:	# empty

.include <bsd.port.mk>
