# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION=	4.4.0
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11/XFree86 core distribution (complete, using mini/meta-ports)

LIB_DEPENDS=	X11.6:${PORTSDIR}/x11/XFree86-4-libraries
RUN_DEPENDS=	xvinfo:${PORTSDIR}/x11/XFree86-4-clients \
	${X11BASE}/lib/X11/doc/ddx.txt:${PORTSDIR}/x11/XFree86-4-documents \
	${X11BASE}/lib/X11/doc/html/X.7.html:${PORTSDIR}/x11/XFree86-4-manuals \
	${FONT100DPI}:${PORTSDIR}/x11-fonts/XFree86-4-font100dpi \
	${FONT75DPI}:${PORTSDIR}/x11-fonts/XFree86-4-font75dpi \
	${FONTCYR}:${PORTSDIR}/x11-fonts/XFree86-4-fontCyrillic \
	${FONTDEFAULT}:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps \
	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
	${X11BASE}/bin/xfs:${PORTSDIR}/x11-servers/XFree86-4-FontServer \
	${X11BASE}/bin/xf86cfg:${PORTSDIR}/x11-servers/XFree86-4-Server \
	${X11BASE}/bin/Xnest:${PORTSDIR}/x11-servers/XFree86-4-NestServer \
	${X11BASE}/bin/Xvfb:${PORTSDIR}/x11-servers/XFree86-4-VirtualFramebufferServer \
	${X11BASE}/bin/Xprt:${PORTSDIR}/x11-servers/XFree86-4-PrintServer \
	${X11BASE}/bin/Xwrapper-4:${PORTSDIR}/x11/wrapper

NO_BUILD=	yes
LATEST_LINK=	XFree86
FONT100DPI=	${X11BASE}/lib/X11/fonts/100dpi/UTBI__10-ISO8859-1.pcf.gz
FONT75DPI=	${X11BASE}/lib/X11/fonts/75dpi/UTBI__10-ISO8859-1.pcf.gz
FONTCYR=	${X11BASE}/lib/X11/fonts/cyrillic/crox1c.pcf.gz
FONTDEFAULT=	${X11BASE}/lib/X11/fonts/misc/cursor.pcf.gz
FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use portupgrade if you want to"
	@${ECHO_MSG} "upgrade XFree86.  If you simply type 'make install' it may use over 2GB to build"
	@${ECHO_MSG} "all of the subports.  You can install the ports singly if you are low on space."

.if make(package)
DEPENDS_TARGET="package"
.endif
.undef NOCLEANDEPENDS

do-install:	# empty

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
