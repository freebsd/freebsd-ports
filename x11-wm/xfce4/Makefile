# New ports collection makefile for:	xfce4
# Date created:		9 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	4.8
CATEGORIES=	x11-wm xfce
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The "meta-port" for the XFce 4 desktop environment

OPTIONS=	ICONS		"Install a full icon theme"		on  \
		ORAGE		"Install the Xfce calendar application"	on  \
		MOUSEPAD	"Install the Xfce text editor"		on  \
		TERMINAL	"Install the Xfce terminal application"	on  \
		APPFINDER	"Install the Xfce application finder"	on  \
		MIXER		"Install the Xfce mixer application"	on  \
		PRINT		"Install the Xfce printing helper"	on  \
		SQUEEZE		"Install the Xfce archiver application"	on  \
		GDM		"Install the login manager gdm"		off

RUN_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm \
		xfce4-session:${PORTSDIR}/x11-wm/xfce4-session \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		startxfce4:${PORTSDIR}/sysutils/xfce4-utils \
		${LOCALBASE}/lib/gtk-2.0/2.10.0/engines/libxfce.so:${PORTSDIR}/x11-themes/gtk-xfce-engine \
		xfsettingsd:${PORTSDIR}/sysutils/xfce4-settings

NO_BUILD=	yes
LATEST_LINK=	xfce4

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/sbin/gdm)
WITH_GDM=	yes
.endif

.if defined(WITH_GDM)
RUN_DEPENDS+=	${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm
PLIST_FILES=	etc/gdm/Sessions/XFce4 \
		etc/dm/Sessions/XFce4.desktop
PLIST_DIRS=	etc/gdm/Sessions
.endif

.if !defined(WITHOUT_ICONS)
RUN_DEPENDS+=	${LOCALBASE}/share/themes/Xfce/xfwm4/themerc:${PORTSDIR}/misc/xfce4-wm-themes \
		icons-tango-extras>=0.1.0:${PORTSDIR}/x11-themes/icons-tango-extras
.endif

.if !defined(WITHOUT_ORAGE)
RUN_DEPENDS+=	orage:${PORTSDIR}/deskutils/orage
.endif

.if !defined(WITHOUT_MOUSEPAD)
RUN_DEPENDS+=	mousepad:${PORTSDIR}/editors/mousepad
.endif

.if !defined(WITHOUT_TERMINAL)
RUN_DEPENDS+=	Terminal:${PORTSDIR}/x11/Terminal
.endif

.if !defined(WITHOUT_APPFINDER)
RUN_DEPENDS+=	xfce4-appfinder:${PORTSDIR}/misc/xfce4-appfinder
.endif

.if !defined(WITHOUT_MIXER)
RUN_DEPENDS+=	${LOCALBASE}/bin/xfce4-mixer:${PORTSDIR}/audio/xfce4-mixer
.endif

.if !defined(WITHOUT_PRINT)
RUN_DEPENDS+=	xfprint4:${PORTSDIR}/print/xfce4-print
.endif

.if !defined(WITHOUT_SQUEEZE)
RUN_DEPENDS+=   squeeze:${PORTSDIR}/archivers/squeeze
.endif

do-install:	# empty

post-install:
.if defined(WITH_GDM)
	@${TEST} -d ${PREFIX}/etc/gdm/Sessions || \
		${MKDIR} -p ${PREFIX}/etc/gdm/Sessions
	@${INSTALL_SCRIPT} ${FILESDIR}/XFce4 ${PREFIX}/etc/gdm/Sessions
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/XFce4.desktop > ${PREFIX}/etc/dm/Sessions/XFce4.desktop
.endif
	@${ECHO} "================================================================"
	@${ECHO}
	@${ECHO} "If you want to allow users to restart or shutdown the system,"
	@${ECHO} "do not forget to add the following lines between the <config>"
	@${ECHO} "tags in your PolicyKit.conf file."
	@${ECHO} "  ${PREFIX}/etc/PolicyKit/PolicyKit.conf
	@${ECHO} ""
	@${ECHO} "<match action=\"org.freedesktop.hal.power-management.shutdown\">"
	@${ECHO} "    <return result=\"yes\"/>"
	@${ECHO} "</match>"
	@${ECHO} ""
	@${ECHO} "<match action=\"org.freedesktop.hal.power-management.reboot\">"
	@${ECHO} "    <return result=\"yes\"/>"
	@${ECHO} "</match>"
	@${ECHO}
	@${ECHO} "Make also sure, hald_enable, dbus_enable"
	@${ECHO} "is set to YES in your /etc/rc.conf"
	@${ECHO}
	@${ECHO} "================================================================"


.include <bsd.port.post.mk>
