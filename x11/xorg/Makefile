# New ports collection makefile for:    xorg
# Date created:		18 Jun 2004
# Whom:			anholt
#
# $FreeBSD$
#

PORTNAME=	xorg
PORTVERSION=	6.8.2
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org distribution metaport

LIB_DEPENDS=	X11.6:${PORTSDIR}/x11/xorg-libraries
RUN_DEPENDS=	xvinfo:${PORTSDIR}/x11/xorg-clients \
		${X11BASE}/share/doc/X11/ddx.txt:${PORTSDIR}/x11/xorg-documents \
		${FONT100DPI}:${PORTSDIR}/x11-fonts/xorg-fonts-100dpi \
		${FONT75DPI}:${PORTSDIR}/x11-fonts/xorg-fonts-75dpi \
		${FONTCYR}:${PORTSDIR}/x11-fonts/xorg-fonts-cyrillic \
		${FONTDEFAULT}:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
		${FONTTT}:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		${FONTT1}:${PORTSDIR}/x11-fonts/xorg-fonts-type1 \
		${X11BASE}/bin/xfs:${PORTSDIR}/x11-servers/xorg-fontserver \
		${X11BASE}/bin/Xnest:${PORTSDIR}/x11-servers/xorg-nestserver \
		${X11BASE}/bin/Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
		${X11BASE}/bin/Xprt:${PORTSDIR}/x11-servers/xorg-printserver

.include <bsd.port.pre.mk>

.if ${ARCH} != ia64
RUN_DEPENDS+=	${X11BASE}/bin/Xorg:${PORTSDIR}/x11-servers/xorg-server
.endif

.if ${ARCH} == i386 || ${ARCH} == alpha || ${ARCH} == amd64
RUN_DEPENDS+=	${X11BASE}/lib/modules/dri/r200_dri.so:${PORTSDIR}/graphics/dri
.endif

FONT100DPI=	${X11BASE}/lib/X11/fonts/100dpi/UTBI__10-ISO8859-1.pcf.gz
FONT75DPI=	${X11BASE}/lib/X11/fonts/75dpi/UTBI__10-ISO8859-1.pcf.gz
FONTCYR=	${X11BASE}/lib/X11/fonts/cyrillic/crox1c.pcf.gz
FONTDEFAULT=	${X11BASE}/lib/X11/fonts/misc/cursor.pcf.gz
FONTTT=		${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTT1=		${X11BASE}/lib/X11/fonts/Type1/UTBI____.afm

NO_BUILD=	yes

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"
	@${ECHO_MSG} "This port does not ensure things are upgraded; use portupgrade if you want to"
	@${ECHO_MSG} "upgrade X.Org.  If you simply type 'make install' it may use over 2GB to build"
	@${ECHO_MSG} "all of the subports.  You can install the ports singly if you are low on space."

.if make(package)
.if !defined(DEPENDS_TARGET:Mpackage) || empty(DEPENDS_TARGET:Mpackage)
DEPENDS_TARGET="package"
.endif
.endif

do-install:	# empty

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif
.include <bsd.port.post.mk>
