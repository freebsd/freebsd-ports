# New ports collection makefile for:	KDE4
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The meta-port for KDE Software Compilation 4

OPTIONS=	KDEACCESSIBILITY "Accessibility applications" on \
		KDEADMIN "Administration utilities" on \
    		KDEARTWORK "Additional screensavers and wallpapers" on \
		KDEBINDINGS "Bindings for programming languages" off \
		KDEEDU "Entertaining, educational programs" on \
		KDEGAMES "Collection of games" on \
		KDEGRAPHICS "Graphics utilities" on \
		KDEMULTIMEDIA "Multimedia applications" on \
		KDENETWORK "Network-related programs" on \
		KDEPIM "Personal information management" on \
		KDEPLASMA "Extra plasmoids and plugins for Plasma" on \
		KDESDK "Software development kit" on \
		KDETOYS "Miscellaneous small applications" on \
		KDEUTILS "Set of generic utilities" on \
		KDEWALLPAPERS "Official KDE wallpapers" on \
		KDEWEBDEV "Web development environment" on

USE_KDE4=	baseapps kdelibs kdeprefix oxygen pimlibs runtime workspace
NO_BUILD=	yes

.include <bsd.port.options.mk>

.ifndef(WITHOUT_KDEACCESSIBILITY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmag:${PORTSDIR}/accessibility/kdeaccessibility4
.endif

.ifndef(WITHOUT_KDEADMIN)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kuser:${PORTSDIR}/sysutils/kdeadmin4
.endif

.ifndef(WITHOUT_KDEARTWORK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kxsconfig:${PORTSDIR}/x11-themes/kdeartwork4
.endif

.ifdef(WITH_KDEBINDINGS)
RUN_DEPENDS+=	kdebindings>=4.1.0:${PORTSDIR}/devel/kdebindings4
.endif

.ifndef(WITHOUT_KDEEDU)
RUN_DEPENDS+=	kdeedu>=4.1.0:${PORTSDIR}/misc/kdeedu4
.endif

.ifndef(WITHOUT_KDEGAMES)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmines:${PORTSDIR}/games/kdegames4
.endif

.ifndef(WITHOUT_KDEGRAPHICS)
RUN_DEPENDS+=	kdegraphics>=4.1.0:${PORTSDIR}/graphics/kdegraphics4
.endif

.ifndef(WITHOUT_KDEMULTIMEDIA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmix:${PORTSDIR}/multimedia/kdemultimedia4
.endif

.ifndef(WITHOUT_KDENETWORK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kget:${PORTSDIR}/net/kdenetwork4
.endif

.ifndef(WITHOUT_KDEPIM)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmail:${PORTSDIR}/deskutils/kdepim4
.endif

.ifndef(WITHOUT_KDEPLASMA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/lancelot:${PORTSDIR}/deskutils/kdeplasma-addons
.endif

.ifndef(WITHOUT_KDESDK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kompare:${PORTSDIR}/devel/kdesdk4
.endif

.ifndef(WITHOUT_KDETOYS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kteatime:${PORTSDIR}/x11-clocks/kdetoys4
.endif

.ifndef(WITHOUT_KDEUTILS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcalc:${PORTSDIR}/misc/kdeutils4
.endif

.ifndef(WITHOUT_KDEWALLPAPERS)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/wallpapers/Plasmalicious/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers
.endif

.ifndef(WITHOUT_KDEWEBDEV)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/klinkstatus:${PORTSDIR}/www/kdewebdev4
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
