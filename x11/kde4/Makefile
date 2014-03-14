# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Compilation 4 (meta port)

USE_KDE4=	baseapps_run kdeprefix runtime_run workspace_run
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	KDEACCESSIBILITY KDEADMIN KDEARTWORK KDEBINDINGS KDEEDU \
		KDEGAMES KDEGRAPHICS KDEMULTIMEDIA KDENETWORK \
		KDEPLASMA KDEPIM KDESDK KDETOYS KDEUTILS KDEWEBDEV
OPTIONS_DEFAULT=${OPTIONS_DEFINE:NKDEBINDINGS}

KDEACCESSIBILITY_DESC=	Accessibility applications
KDEACCESSIBILITY_RUN_DEPENDS=	kdeaccessibility>=${KDE4_VERSION}:${PORTSDIR}/accessibility/kdeaccessibility4

KDEADMIN_DESC=		Administration utilities
KDEADMIN_RUN_DEPENDS=	kdeadmin>=${KDE4_VERSION}:${PORTSDIR}/sysutils/kdeadmin4

KDEARTWORK_DESC=	Additional screensavers and wallpapers
KDEARTWORK_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kxsconfig:${PORTSDIR}/x11-themes/kdeartwork4

KDEBINDINGS_DESC=	Bindings for programming languages
KDEBINDINGS_RUN_DEPENDS=	kdebindings>=${KDE4_VERSION}:${PORTSDIR}/devel/kdebindings4

KDEEDU_DESC=		Entertaining, educational programs
KDEEDU_RUN_DEPENDS=	kdeedu>=${KDE4_VERSION}:${PORTSDIR}/misc/kdeedu4

KDEGAMES_DESC=		Collection of games
KDEGAMES_RUN_DEPENDS=	kdegames>=${KDE4_VERSION}:${PORTSDIR}/games/kdegames4

KDEGRAPHICS_DESC=	Graphics utilities
KDEGRAPHICS_RUN_DEPENDS=	kdegraphics>=${KDE4_VERSION}:${PORTSDIR}/graphics/kdegraphics4

KDEMULTIMEDIA_DESC=	Multimedia applications
KDEMULTIMEDIA_RUN_DEPENDS=	kdemultimedia>=${KDE4_VERSION}:${PORTSDIR}/multimedia/kdemultimedia4

KDENETWORK_DESC=	Network-related programs
KDENETWORK_RUN_DEPENDS=	kdenetwork>=${KDE4_VERSION}:${PORTSDIR}/net/kdenetwork4

KDEPIM_DESC=		Personal information management
KDEPIM_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmail:${PORTSDIR}/deskutils/kdepim4

KDEPLASMA_DESC=		Extra plasmoids and plugins for Plasma
KDEPLASMA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/lancelot:${PORTSDIR}/deskutils/kdeplasma-addons

KDESDK_DESC=		Software development kit
KDESDK_RUN_DEPENDS=	kdesdk>=${KDE4_VERSION}:${PORTSDIR}/devel/kdesdk4

KDETOYS_DESC=		Miscellaneous small applications
KDETOYS_RUN_DEPENDS=	kdetoys>=${KDE4_VERSION}:${PORTSDIR}/x11-clocks/kdetoys4

KDEUTILS_DESC=		Set of generic utilities
KDEUTILS_RUN_DEPENDS=	kdeutils>=${KDE4_VERSION}:${PORTSDIR}/misc/kdeutils4

KDEWEBDEV_DESC=		Web development environment
KDEWEBDEV_RUN_DEPENDS=	${KDE4_PREFIX}/bin/klinkstatus:${PORTSDIR}/www/kdewebdev4

.include <bsd.port.mk>
