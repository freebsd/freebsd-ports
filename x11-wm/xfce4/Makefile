# New ports collection makefile for:	xfce4
# Date created:		9 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	4.4.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The "meta-port" for the XFce 4 desktop environment

RUN_DEPENDS=	${LOCALBASE}/lib/xfce4/mcs-plugins/ui_plugin.so:${PORTSDIR}/sysutils/xfce4-mcs-plugins \
		xfwm4:${PORTSDIR}/x11-wm/xfce4-wm \
		xfce4-appfinder:${PORTSDIR}/misc/xfce4-appfinder \
		xfce4-session:${PORTSDIR}/x11-wm/xfce4-session \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		startxfce4:${PORTSDIR}/sysutils/xfce4-utils \
		xfprint4:${PORTSDIR}/print/xfce4-print \
		${LOCALBASE}/lib/gtk-2.0/2.10.0/engines/libxfce.so:${PORTSDIR}/x11-themes/gtk-xfce-engine \
		thunar:${PORTSDIR}/x11-fm/thunar \
		orage:${PORTSDIR}/deskutils/orage \
		mousepad:${PORTSDIR}/editors/mousepad \
		Terminal:${PORTSDIR}/x11/Terminal

NO_BUILD=	yes
LATEST_LINK=	xfce4

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/sbin/gdm)
WITH_GDM=	yes
.endif

.if defined(WITH_GDM)
RUN_DEPENDS+=	${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm
PLIST_SUB+=	GDM=""
.else
PLIST_SUB+=	GDM="@comment "
.endif

.if !defined(WITHOUT_EXTRAS)
.if !defined(WITHOUT_THEMES)
RUN_DEPENDS+=	${LOCALBASE}/share/xfce4/mime/Rodent.mime.xml:${PORTSDIR}/x11-themes/xfce4-icon-theme \
		${LOCALBASE}/share/themes/Xfce/xfwm4/themerc:${PORTSDIR}/misc/xfce4-wm-themes
.endif

.if !defined(WITHOUT_PLUGINS)
RUN_DEPENDS+=	${LOCALBASE}/lib/xfce4/modules/libxfce4mixer.so:${PORTSDIR}/audio/xfce4-mixer
.endif
.endif

do-install:	# empty

post-install:
.if defined(WITH_GDM)
	@${TEST} -d ${PREFIX}/etc/gdm/Sessions || \
		${MKDIR} -p ${PREFIX}/etc/gdm/Sessions
	@${INSTALL_SCRIPT} ${FILESDIR}/XFce4 ${PREFIX}/etc/gdm/Sessions
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/XFce4.desktop > ${PREFIX}/etc/dm/Sessions/XFce4.desktop
.endif

.include <bsd.port.post.mk>
