# New ports collection makefile for:	xfce4
# Date created:		9 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	4.2.3.2
PORTREVISION=	3
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
		${LOCALBASE}/lib/xfce4/panel-plugins/libtriggerlauncher.so:${PORTSDIR}/x11/xfce4-trigger-launcher \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		startxfce4:${PORTSDIR}/sysutils/xfce4-utils \
		xffm:${PORTSDIR}/x11-fm/xfce4-fm \
		xfprint4:${PORTSDIR}/print/xfce4-print \
		xfce4-iconbox:${PORTSDIR}/misc/xfce4-iconbox \
		${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libxfce.so:${PORTSDIR}/x11-themes/gtk-xfce-engine

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
RUN_DEPENDS+=	${LOCALBASE}/share/xfce4/mime/Rodent.mime.xml:${PORTSDIR}/x11-themes/xfce4-icon-theme
.endif

.if !defined(WITHOUT_PLUGINS)
RUN_DEPENDS+=	${LOCALBASE}/lib/xfce4/panel-plugins/libmixer.so:${PORTSDIR}/audio/xfce4-mixer \
		${LOCALBASE}/lib/xfce4/panel-plugins/libsystray.so:${PORTSDIR}/x11-wm/xfce4-systray \
		xfce4-tips:${PORTSDIR}/games/xfce4-toys
.endif
.endif

LATEST_LINK=	xfce4
NO_BUILD=	yes
USE_GNOME=	gtk20

do-install:	# empty

post-install:
.if defined(WITH_GDM)
	@${TEST} -d ${LOCALBASE}/etc/gdm/Sessions || \
		${MKDIR} -p ${LOCALBASE}/etc/gdm/Sessions
	@${INSTALL_SCRIPT} ${FILESDIR}/XFce4 ${LOCALBASE}/etc/gdm/Sessions
	@${INSTALL_DATA} ${FILESDIR}/XFce4.desktop ${LOCALBASE}/etc/dm/Sessions
.endif

.include <bsd.port.mk>
