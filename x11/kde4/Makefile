# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	x11 kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Compilation 4 (legacy)

USES=		kde:4 metaport
USE_KDE=	baseapps_run runtime_run workspace_run

OPTIONS_DEFINE=	KDEACCESSIBILITY KDEADMIN KDEARTWORK KDEBINDINGS KDEEDU \
		KDEGAMES KDEGRAPHICS KDEMULTIMEDIA KDENETWORK \
		KDEPLASMA KDEPIM KDESDK KDETOYS KDEUTILS KDEWEBDEV
OPTIONS_DEFAULT=${OPTIONS_DEFINE:NKDEBINDINGS}

KDEACCESSIBILITY_DESC=	Accessibility applications
KDEACCESSIBILITY_RUN_DEPENDS=	kdeaccessibility-kde4>=${KDE4_VERSION}:accessibility/kdeaccessibility-kde4

KDEADMIN_DESC=		Administration utilities
KDEADMIN_RUN_DEPENDS=	kdeadmin-kde4>=${KDE4_VERSION}:sysutils/kdeadmin-kde4

KDEARTWORK_DESC=	Additional screensavers and wallpapers
KDEARTWORK_RUN_DEPENDS=	${KDE_PREFIX}/bin/kxsconfig:x11-themes/kdeartwork-kde4

KDEBINDINGS_DESC=	Bindings for programming languages
KDEBINDINGS_RUN_DEPENDS=	kdebindings-kde4>=${KDE4_VERSION}:devel/kdebindings-kde4

KDEEDU_DESC=		Entertaining, educational programs
KDEEDU_RUN_DEPENDS=	kdeedu-kde4>=${KDE4_VERSION}:misc/kdeedu-kde4

KDEGAMES_DESC=		Collection of games
KDEGAMES_RUN_DEPENDS=	kdegames-kde4>=${KDE4_VERSION}:games/kdegames-kde4

KDEGRAPHICS_DESC=	Graphics utilities
KDEGRAPHICS_RUN_DEPENDS=	kdegraphics-kde4>=${KDE4_VERSION}:graphics/kdegraphics-kde4

KDEMULTIMEDIA_DESC=	Multimedia applications
KDEMULTIMEDIA_RUN_DEPENDS=	kdemultimedia-kde4>=${KDE4_VERSION}:multimedia/kdemultimedia-kde4

KDENETWORK_DESC=	Network-related programs
KDENETWORK_RUN_DEPENDS=	kdenetwork-kde4>=${KDE4_VERSION}:net/kdenetwork-kde4

KDEPIM_DESC=		Personal information management
KDEPIM_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmail:deskutils/kdepim-kde4

KDEPLASMA_DESC=		Extra plasmoids and plugins for Plasma
KDEPLASMA_RUN_DEPENDS=	${KDE_PREFIX}/bin/lancelot:deskutils/kdeplasma-addons-kde4

KDESDK_DESC=		Software development kit
KDESDK_RUN_DEPENDS=	kdesdk-kde4>=${KDE4_VERSION}:devel/kdesdk-kde4

KDETOYS_DESC=		Miscellaneous small applications
KDETOYS_RUN_DEPENDS=	kdetoys-kde4>=${KDE4_VERSION}:x11-clocks/kdetoys-kde4

KDEUTILS_DESC=		Set of generic utilities
KDEUTILS_RUN_DEPENDS=	kdeutils-kde4>=${KDE4_VERSION}:misc/kdeutils-kde4

KDEWEBDEV_DESC=		Web development environment
KDEWEBDEV_RUN_DEPENDS=	${KDE_PREFIX}/bin/klinkstatus:www/kdewebdev-kde4

.include <bsd.port.mk>
