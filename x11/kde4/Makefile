# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Compilation 4

LATEST_LINK=	kde4

USE_KDE4=	baseapps_run kdeprefix runtime_run workspace_run
NO_BUILD=	yes

OPTIONS_DEFINE=	KDEACCESSIBILITY KDEADMIN KDEARTWORK KDEBINDINGS KDEEDU \
		KDEGAMES KDEGRAPHICS KDEMULTIMEDIA KDENETWORK \
		KDEPLASMA KDESDK KDETOYS KDEUTILS KDEWEBDEV
OPTIONS_RADIO=	PIM
OPTIONS_RADIO_PIM=	KDEPIM KDEPIM44
OPTIONS_DEFAULT=${OPTIONS_DEFINE:NKDEBINDINGS} KDEPIM

KDEACCESSIBILITY_DESC=	Accessibility applications
KDEADMIN_DESC=		Administration utilities
KDEARTWORK_DESC=	Additional screensavers and wallpapers
KDEBINDINGS_DESC=	Bindings for programming languages
KDEEDU_DESC=		Entertaining, educational programs
KDEGAMES_DESC=		Collection of games
KDEGRAPHICS_DESC=	Graphics utilities
KDEMULTIMEDIA_DESC=	Multimedia applications
KDENETWORK_DESC=	Network-related programs
KDEPIM_DESC=		Personal information management
KDEPIM44_DESC=		KDE-Pim 4.4 (legacy version)
KDEPLASMA_DESC=		Extra plasmoids and plugins for Plasma
KDESDK_DESC=		Software development kit
KDETOYS_DESC=		Miscellaneous small applications
KDEUTILS_DESC=		Set of generic utilities
KDEWEBDEV_DESC=		Web development environment

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDEACCESSIBILITY}
RUN_DEPENDS+=	kdeaccessibility>=4.8.0:${PORTSDIR}/accessibility/kdeaccessibility4
.endif

.if ${PORT_OPTIONS:MKDEADMIN}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kuser:${PORTSDIR}/sysutils/kdeadmin4
.endif

.if ${PORT_OPTIONS:MKDEARTWORK}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kxsconfig:${PORTSDIR}/x11-themes/kdeartwork4
.endif

.if ${PORT_OPTIONS:MKDEBINDINGS}
RUN_DEPENDS+=	kdebindings>=4.1.0:${PORTSDIR}/devel/kdebindings4
.endif

.if ${PORT_OPTIONS:MKDEEDU}
RUN_DEPENDS+=	kdeedu>=4.1.0:${PORTSDIR}/misc/kdeedu4
.endif

.if ${PORT_OPTIONS:MKDEGAMES}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmines:${PORTSDIR}/games/kdegames4
.endif

.if ${PORT_OPTIONS:MKDEGRAPHICS}
RUN_DEPENDS+=	kdegraphics>=4.1.0:${PORTSDIR}/graphics/kdegraphics4
.endif

.if ${PORT_OPTIONS:MKDEMULTIMEDIA}
RUN_DEPENDS+=	kdemultimedia>=4.8.95:${PORTSDIR}/multimedia/kdemultimedia4
.endif

.if ${PORT_OPTIONS:MKDENETWORK}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kget:${PORTSDIR}/net/kdenetwork4
.endif

.if ${PORT_OPTIONS:MKDEPIM}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmail:${PORTSDIR}/deskutils/kdepim4
.endif

.if ${PORT_OPTIONS:MKDEPIM44}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmail:${PORTSDIR}/deskutils/kdepim44
.endif

.if ${PORT_OPTIONS:MKDEPLASMA}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/lancelot:${PORTSDIR}/deskutils/kdeplasma-addons
.endif

.if ${PORT_OPTIONS:MKDESDK}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kompare:${PORTSDIR}/devel/kdesdk4
.endif

.if ${PORT_OPTIONS:MKDETOYS}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kteatime:${PORTSDIR}/x11-clocks/kdetoys4
.endif

.if ${PORT_OPTIONS:MKDEUTILS}
RUN_DEPENDS+=	kdeutils>=4.8.0:${PORTSDIR}/misc/kdeutils4
.endif

.if ${PORT_OPTIONS:MKDEWEBDEV}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/klinkstatus:${PORTSDIR}/www/kdewebdev4
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
