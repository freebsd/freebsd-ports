# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce
PORTVERSION=	4.10
PORTREVISION=	5
CATEGORIES=	x11-wm xfce
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The "meta-port" for the Xfce Desktop Environment

OPTIONS_DEFINE=	ICONS ORAGE MOUSEPAD TERMINAL APPFINDER MIXER PRINT SQUEEZE GDM NOTIFY XPM
OPTIONS_DEFAULT=	ICONS ORAGE MOUSEPAD TERMINAL APPFINDER NOTIFY
ORAGE_DESC=	Install the Xfce calendar application
MOUSEPAD_DESC=	Install the Xfce text editor
TERMINAL_DESC=	Install the Xfce terminal application
APPFINDER_DESC=	Install the Xfce application finder
SQUEEZE_DESC=	Install the Xfce archiver application
XPM_DESC=	Install the Xfce power manager

RUN_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm \
		xfce4-session:${PORTSDIR}/x11-wm/xfce4-session \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		${LOCALBASE}/lib/gtk-2.0/2.10.0/engines/libxfce.so:${PORTSDIR}/x11-themes/gtk-xfce-engine \
		xfsettingsd:${PORTSDIR}/sysutils/xfce4-settings

NO_BUILD=	yes
LATEST_LINK=	xfce4

NO_MTREE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDM}
RUN_DEPENDS+=	${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm
REINPLACE_ARGS=	-i ""
PLIST_FILES=	etc/gdm/Sessions/XFce4 \
		etc/dm/Sessions/XFce4.desktop
.endif

.if ${PORT_OPTIONS:MICONS}
RUN_DEPENDS+=	icons-tango-extras>=0.1.0:${PORTSDIR}/x11-themes/icons-tango-extras
.endif

.if ${PORT_OPTIONS:MORAGE}
RUN_DEPENDS+=	orage:${PORTSDIR}/deskutils/orage
.endif

.if ${PORT_OPTIONS:MMOUSEPAD}
RUN_DEPENDS+=	mousepad:${PORTSDIR}/editors/mousepad
.endif

.if ${PORT_OPTIONS:MTERMINAL}
RUN_DEPENDS+=	xfce4-terminal:${PORTSDIR}/x11/xfce4-terminal
.endif

.if ${PORT_OPTIONS:MAPPFINDER}
RUN_DEPENDS+=	xfce4-appfinder:${PORTSDIR}/misc/xfce4-appfinder
.endif

.if ${PORT_OPTIONS:MMIXER}
RUN_DEPENDS+=	xfce4-mixer:${PORTSDIR}/audio/xfce4-mixer
.endif

.if ${PORT_OPTIONS:MPRINT}
RUN_DEPENDS+=	xfprint4:${PORTSDIR}/print/xfce4-print
.endif

.if ${PORT_OPTIONS:MSQUEEZE}
RUN_DEPENDS+=   squeeze:${PORTSDIR}/archivers/squeeze
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	xfce4-notifyd-config:${PORTSDIR}/deskutils/xfce4-notifyd
.endif

.if ${PORT_OPTIONS:MXPM}
RUN_DEPENDS+=	xfce4-power-manager:${PORTSDIR}/sysutils/xfce4-power-manager
.endif

do-install:	# empty

post-install:
.if ${PORT_OPTIONS:MGDM}
.for dir in dm gdm
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${dir}/Sessions
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/XFce4 \
		${STAGEDIR}${PREFIX}/etc/gdm/Sessions
	@${INSTALL_DATA} ${FILESDIR}/XFce4.desktop \
		${STAGEDIR}${PREFIX}/etc/dm/Sessions
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
		${STAGEDIR}${PREFIX}/etc/dm/Sessions/XFce4.desktop
.endif

.include <bsd.port.mk>
