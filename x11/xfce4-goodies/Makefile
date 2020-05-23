# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-goodies
PORTVERSION=	4.14
CATEGORIES=	x11

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Meta-port for software and artwork from the Xfce4 Goodies Project

USES=		metaport

OPTIONS_DEFAULT=        DASHBOARD DICTIONARY GIGOLO PAROLE  POWERMANAGER \
			RISTRETTO SCREENSAVER SCREENSHOOTER TASKMANAGER \
			TERMINAL XFBURN \
			BATTERY CALCULATOR CLIPMAN CPUGRAPH DATETIME \
			DISKPERF EMBED FSGUARD GENMON MAILWATCH \
			MENULIBRE MOUNT NETLOAD NOTES SMARTBOOKMARK \
			SYSTEMLOAD TIMER TIMEOUT VERVE WAVELAN \
			WEATHER WHISKERMENU XKB ARCHIVE MEDIATAGS \
			VCS BSDCPUFREQ EQUAKE THEMES VOLUMED

OPTIONS_EXCLUDE_powerpc=	BATTERY
OPTIONS_EXCLUDE_powerpc64=	BATTERY
OPTIONS_EXCLUDE_powerpcspe=	BATTERY

OPTIONS_GROUP=	APPLICATIONS PANELPLUGINS THUNARPLUGINS UNOFFICIAL

OPTIONS_GROUP_APPLICATIONS=	DASHBOARD DICTIONARY GIGOLO MIDORI PAROLE \
				POWERMANAGER RISTRETTO SCREENSHOOTER \
				TASKMANAGER TERMINAL VOLUMEDPULSE XFBURN \
				XFMPC SCREENSAVER
DASHBOARD_DESC=			GNOME shell like dashboard for the Xfce desktop
DICTIONARY_DESC=		Xfce4 plugin to query different dictionaries
GIGOLO_DESC=			Frontend to easily manage filesystem connections
MIDORI_DESC=			Lightweight web browser using WebKit engine
PAROLE_DESC=			Lightweight media player based on GStreamer
POWERMANAGER_DESC=		Power manager for the Xfce Desktop
RISTRETTO_DESC=			Image viewer with Xfce integration
SCREENSAVER_DESC=		Screen Saver for the Xfce Desktop
SCREENSHOOTER_DESC=		Application and panel plugin to take screenshots
TASKMANAGER_DESC=		Task manager for the Xfce desktop
TERMINAL_DESC=			Terminal emulator for the X windowing system
VOLUMEDPULSE_DESC=		Volume management daemon for Xfce using PulseAudio
XFBURN_DESC=			CD/DVD burning tool for Xfce
XFMPC_DESC=			Graphical MPD client focusing on low footprint

DASHBOARD_RUN_DEPENDS=		xfce4-dashboard>=0:x11/xfce4-dashboard
DICTIONARY_RUN_DEPENDS=		xfce4-dict-plugin>=0:textproc/xfce4-dict-plugin
GIGOLO_RUN_DEPENDS=		gigolo>=0:sysutils/gigolo
MIDORI_RUN_DEPENDS=		midori>=0:www/midori
PAROLE_RUN_DEPENDS=		parole>=0:multimedia/xfce4-parole
POWERMANAGER_RUN_DEPENDS=	xfce4-power-manager>=0:sysutils/xfce4-power-manager
RISTRETTO_RUN_DEPENDS=		ristretto>=0:graphics/ristretto
SCREENSAVER_RUN_DEPENDS=	xfce4-screensaver>=0:x11/xfce4-screensaver
SCREENSHOOTER_RUN_DEPENDS=	xfce4-screenshooter-plugin>=0:x11/xfce4-screenshooter-plugin
TASKMANAGER_RUN_DEPENDS=	xfce4-taskmanager>=0:x11/xfce4-taskmanager
TERMINAL_RUN_DEPENDS=		xfce4-terminal>=0:x11/xfce4-terminal
VOLUMEDPULSE_RUN_DEPENDS=	xfce4-volumed-pulse>=0:deskutils/xfce4-volumed-pulse
XFBURN_RUN_DEPENDS=		xfburn>=0:sysutils/xfburn
XFMPC_RUN_DEPENDS=		xfmpc>=0:audio/xfmpc

OPTIONS_GROUP_PANELPLUGINS=	BATTERY CALCULATOR CLIPMAN CPUGRAPH DATETIME \
				DISKPERF EMBED FSGUARD GENERICSLIDER GENMON \
				MAILWATCH MOUNT MPC NETLOAD NOTES PULSEAUDIO \
				QUICKLAUNCHER SMARTBOOKMARK SYSTEMLOAD TIMER \
				TIMEOUT VERVE WAVELAN WEATHER WHISKERMENU \
				WMDOCK XKB
BATTERY_DESC=			Battery monitor panel plugin for Xfce4
CALCULATOR_DESC=		Simple calculator for the Xfce panel
CLIPMAN_DESC=			Clipboard manager for the Xfce panel
CPUGRAPH_DESC=			Graphical representation of the CPU load
DATETIME_DESC=			Datetime panel plugin for the Xfce desktop
DISKPERF_DESC=			Graphical representation of the disk IO
EMBED_DESC=			Embed arbitrary windows into the Xfce panel
FSGUARD_DESC=			Displays free space of mountpoint
GENERICSLIDER_DESC=		Slider to adjust / monitor any numeric variable
GENMON_DESC=			Generic Monitor Xfce4 panel plugin
MAILWATCH_DESC=			Mail notification applet for the Xfce panel
MOUNT_DESC=			Mount and umount utility for the Xfce4 panel
MPC_DESC=			Musicpd client plugin for the Xfce panel
NETLOAD_DESC=			Network Load plugin for Xfce4
NOTES_DESC=			Notes plugin for the Xfce panel
PULSEAUDIO_DESC=		Panel plugin for controlling PulseAudio mixer
QUICKLAUNCHER_DESC=		Quicklauncher plugin for Xfce
SMARTBOOKMARK_DESC=		Query search engines from the Xfce panel
SYSTEMLOAD_DESC=		System Load plugin for Xfce4 panel
TIMEOUT_DESC=			Prompts the user to take a break every X minutes
TIMER_DESC=			Set alarm at specific time or after time period
VERVE_DESC=			Command line plugin for the Xfce Desktop
WAVELAN_DESC=			Displays information about a WaveLAN device
WEATHER_DESC=			Weather plugin for the Xfce panel
WHISKERMENU_DESC=		Alternate menu for the Xfce Desktop
WMDOCK_DESC=			WMdock plugin for Xfce
XKB_DESC=			Keyboard layout switching plugin for Xfce panel

BATTERY_RUN_DEPENDS=		xfce4-battery-plugin>=0:sysutils/xfce4-battery-plugin
CALCULATOR_RUN_DEPENDS=		xfce4-calculator-plugin>=0:math/xfce4-calculator-plugin
CLIPMAN_RUN_DEPENDS=		xfce4-clipman-plugin>=0:x11/xfce4-clipman-plugin
CPUGRAPH_RUN_DEPENDS=		xfce4-cpugraph-plugin>=0:sysutils/xfce4-cpugraph-plugin
DATETIME_RUN_DEPENDS=		xfce4-datetime-plugin>=0:x11-clocks/xfce4-datetime-plugin
DISKPERF_RUN_DEPENDS=		xfce4-diskperf-plugin>=0:sysutils/xfce4-diskperf-plugin
EMBED_RUN_DEPENDS=		xfce4-embed-plugin>=0:x11/xfce4-embed-plugin
FSGUARD_RUN_DEPENDS=		xfce4-fsguard-plugin>=0:sysutils/xfce4-fsguard-plugin
GENERICSLIDER_RUN_DEPENDS=	xfce4-generic-slider>=0:deskutils/xfce4-generic-slider
GENMON_RUN_DEPENDS=		xfce4-genmon-plugin>=0:sysutils/xfce4-genmon-plugin
MAILWATCH_RUN_DEPENDS=		xfce4-mailwatch-plugin>=0:mail/xfce4-mailwatch-plugin
MOUNT_RUN_DEPENDS=		xfce4-mount-plugin>=0:sysutils/xfce4-mount-plugin
MPC_RUN_DEPENDS=		xfce4-mpc-plugin>=0:audio/xfce4-mpc-plugin
NETLOAD_RUN_DEPENDS=		xfce4-netload-plugin>=0:sysutils/xfce4-netload-plugin
NOTES_RUN_DEPENDS=		xfce4-notes-plugin>=0:deskutils/xfce4-notes-plugin
PULSEAUDIO_RUN_DEPENDS=		xfce4-pulseaudio-plugin>=0:audio/xfce4-pulseaudio-plugin
QUICKLAUNCHER_RUN_DEPENDS=	xfce4-quicklauncher-plugin>=0:x11/xfce4-quicklauncher-plugin
SMARTBOOKMARK_RUN_DEPENDS=	xfce4-smartbookmark-plugin>=0:www/xfce4-smartbookmark-plugin
SYSTEMLOAD_RUN_DEPENDS=		xfce4-systemload-plugin>=0:sysutils/xfce4-systemload-plugin
TIMEOUT_RUN_DEPENDS=		xfce4-time-out-plugin>=0:x11-clocks/xfce4-time-out-plugin
TIMER_RUN_DEPENDS=		xfce4-timer-plugin>=0:x11-clocks/xfce4-timer-plugin
VERVE_RUN_DEPENDS=		xfce4-verve-plugin>=0:x11/xfce4-verve-plugin
WAVELAN_RUN_DEPENDS=		xfce4-wavelan-plugin>=0:sysutils/xfce4-wavelan-plugin
WEATHER_RUN_DEPENDS=		xfce4-weather-plugin>=0:misc/xfce4-weather-plugin
WHISKERMENU_RUN_DEPENDS=	xfce4-whiskermenu-plugin>=0:x11/xfce4-whiskermenu-plugin
WMDOCK_RUN_DEPENDS=		xfce4-wmdock-plugin>=0:x11/xfce4-wmdock-plugin
XKB_RUN_DEPENDS=		xfce4-xkb-plugin>=0:deskutils/xfce4-xkb-plugin

OPTIONS_GROUP_THUNARPLUGINS=	ARCHIVE MEDIATAGS VCS
ARCHIVE_DESC=			Create/extract archives from file context menus
MEDIATAGS_DESC=			View/edit id3/ogg tags in file properties dialog
VCS_DESC=			SVN+GIT Version Control System integration

ARCHIVE_RUN_DEPENDS=		thunar-archive-plugin>=0:archivers/thunar-archive-plugin
MEDIATAGS_RUN_DEPENDS=		thunar-media-tags-plugin>=0:audio/thunar-media-tags-plugin
VCS_RUN_DEPENDS=		thunar-vcs-plugin>=0:devel/thunar-vcs-plugin

OPTIONS_GROUP_UNOFFICIAL=	BSDCPUFREQ EQUAKE MENULIBRE MIXER PRINT THEMES \
				VOLUMED
BSDCPUFREQ_DESC=		Display the CPU clock frequency in Xfce panel
EQUAKE_DESC=			Earthquake monitor plugin for the Xfce panel
MENULIBRE_DESC=			Advanced compliant menu editor
MIXER_DESC=			Volume control for the Xfce desktop
PRINT_DESC=			Print system support for the Xfce Desktop
THEMES_DESC=			Additional themes for xfwm4
VOLUMED_DESC=			Volume management daemon for the Xfce desktop

BSDCPUFREQ_RUN_DEPENDS=		xfce4-bsdcpufreq-plugin>=0:sysutils/xfce4-bsdcpufreq-plugin
EQUAKE_RUN_DEPENDS=		xfce4-equake-plugin>=0:science/xfce4-equake-plugin
MENULIBRE_RUN_DEPENDS=		py${PYTHON3_DEFAULT:S/.//}-menulibre>=0:x11/menulibre
MIXER_RUN_DEPENDS=		xfce4-mixer>=0:audio/xfce4-mixer
PRINT_RUN_DEPENDS=		xfce4-print>=0:print/xfce4-print
THEMES_RUN_DEPENDS=		xfce4-wm-themes>=0:misc/xfce4-wm-themes
VOLUMED_RUN_DEPENDS=		xfce4-volumed>=0:deskutils/xfce4-volumed

.include <bsd.port.mk>
