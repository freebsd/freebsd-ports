# New ports collection makefile for:	KDE4
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde4
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The "meta-port" for KDE

OPTIONS=	KDEACCESSIBILITY "Accessibility applications" on \
		KDEADMIN "KDE Administration applications" on \
    		KDEARTWORK "Additional themes, sounds, etc" on \
		KDEGAMES "Games like kolf, patience, atlantik, etc" on \
		KDEEDU "Educational applications" on \
		KDEGRAPHICS "Graphics utilities like kview, kpaint, etc" on \
		KDENETWORK "Network-related programs like kopete, etc" on \
		KDEMULTIMEDIA "Multimedia utilities like noatun, etc" on \
		KDEPIM "Personal Information Management: mail, etc" on \
		KDEPLASMA "Extra plasmoids for KDE" on \
		KDESDK "KDE software development kit" on \
		KDETOYS "Miscellaneous small applications" on \
		KDEUTILS "Utilities like kcalc, kcharselect, etc" on \
		KDEWEBDEV "Website development environment" on \
		KTTS "KDE text-to-speech subsystem" on \
		MARBLE "Virtual globe and world atlas" on \
		PLASMA_PYTHON "Support for plasmoids written in Python" on \
		PLASMA_RUBY "Support for plasmoids written in Ruby" on \
		PRINTER_APPLET "Install printer system tray utility" on \
		PRINTER_CONFIG "Install printer configuration utility" on \
		XINE "Xine backend for Phonon" on \
		VLC "VLC backend for Phonon" off

USE_KDE4=	kdelibs kdebase pimlibs workspace kdeprefix runtime oxygen
NO_BUILD=	yes

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KDEACCESSIBILITY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmag:${PORTSDIR}/accessibility/kdeaccessibility4
.endif
.if !defined(WITHOUT_KDEADMIN)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kuser:${PORTSDIR}/sysutils/kdeadmin4
.endif
.if !defined(WITHOUT_KDEARTWORK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kxsconfig:${PORTSDIR}/x11-themes/kdeartwork4
.endif
.if !defined(WITHOUT_KDEGAMES)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmines:${PORTSDIR}/games/kdegames4
.endif
.if !defined(WITHOUT_KDEEDU)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ktouch:${PORTSDIR}/misc/kdeedu4
.endif
.if !defined(WITHOUT_KDEGRAPHICS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/okular:${PORTSDIR}/graphics/kdegraphics4
.endif
.if !defined(WITHOUT_KDENETWORK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kget:${PORTSDIR}/net/kdenetwork4
.endif
.if !defined(WITHOUT_KDEMULTIMEDIA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmix:${PORTSDIR}/multimedia/kdemultimedia4
.endif
.if !defined(WITHOUT_KDEPIM)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmail:${PORTSDIR}/deskutils/kdepim4
.endif
.if !defined(WITHOUT_KDEPLASMA)
RUN_DEPENDS+=	kdeplasma-addons>=4:${PORTSDIR}/deskutils/kdeplasma-addons
.endif
.if !defined(WITHOUT_KDETOYS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kteatime:${PORTSDIR}/x11-clocks/kdetoys4
.endif
.if !defined(WITHOUT_KDESDK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kompare:${PORTSDIR}/devel/kdesdk4
.endif
.if !defined(WITHOUT_KDEUTILS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcalc:${PORTSDIR}/misc/kdeutils4
.endif
.if !defined(WITHOUT_KDEWEBDEV)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/klinkstatus:${PORTSDIR}/www/kdewebdev4
.endif
.if !defined(WITHOUT_KTTS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kttsd:${PORTSDIR}/accessibility/ktts
.endif
.if !defined(WITHOUT_MARBLE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/marble:${PORTSDIR}/astro/marble
.endif
.if !defined(WITHOUT_PLASMA_PYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:${PORTSDIR}/x11/plasma-scriptengine-python
.endif
.if !defined(WITHOUT_PLASMA_RUBY)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:${PORTSDIR}/x11/plasma-scriptengine-ruby
.endif
.if !defined(WITHOUT_PRINTER_APPLET)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/printer-applet:${PORTSDIR}/print/kdeutils4-printer-applet
.endif
.if !defined(WITHOUT_PRINTER_CONFIG)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/system-config-printer-kde/system-config-printer-kde.py:${PORTSDIR}/print/system-config-printer-kde
.endif
.if !defined(WITHOUT_XINE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so:${PORTSDIR}/multimedia/phonon-xine
.endif
.if !defined(WITHOUT_VLC)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so:${PORTSDIR}/multimedia/phonon-vlc
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
