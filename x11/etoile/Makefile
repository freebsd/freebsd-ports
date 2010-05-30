# New ports collection makefile for:    etoile
# Date created:         21 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	etoile
PORTVERSION=	0.4.1
CATEGORIES=	x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Metaport for Etoile desktop

NO_BUILD=	yes
NO_INSTALL=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BACK=	yes
.if !defined(WITH_GNUSTEP_SINGLE_BACKEND)
USE_GNUSTEP_XLIB=	yes
USE_GNUSTEP_LIBART=	yes
USE_GNUSTEP_CAIRO=	yes
.endif

USE_GNUSTEP_SYSTEM_LIBS+=	\
	TrackerKit:deskutils/etoile-trackerkit \
	ServicesBarKit:deskutils/etoile-servicesbarkit \
	ExtendedWorkspace:deskutils/etoile-extendedworkspacekit \
	XWindowServerKit:x11/etoile-xwindowserverkit \
	WorkspaceCommKit:sysutils/etoile-system \

USE_GNUSTEP_LOCAL_LIBS+=	\
	Addresses:mail/addresses \
	SQLClient:databases/sqlclient \
	UnitKit:devel/etoile-unitkit \
	BookmarkKit:www/etoile-bookmarkkit \
	IconKit:x11-themes/etoile-iconkit \
	RSSKit:www/etoile-rsskit \
	PopplerKit:graphics/popplerkit \
	OgreKit:textproc/etoile-ogrekit \
	LuceneKit:textproc/etoile-lucenekit \
	CollectionKit:devel/etoile-collectionkit \
	EtoileFoundation:devel/etoile-foundation \
	PaneKit:deskutils/etoile-panekit \
	SystemConfig:deskutils/etoile-systemconfig \
	MultimediaKit:multimedia/etoile-multimediakit \
	EtoileSerialize:devel/etoile-serialize \
	CoreObject:devel/etoile-coreobject \
	EtoileUI:deskutils/etoile-ui \
	DistributedView:deskutils/etoile-distributedview \
	InspectorKit:deskutils/etoile-inspectorkit \
	OPMLKit:textproc/etoile-opmlkit \
	ScriptKit:lang/etoile-scriptkit \
	MediaKit:multimedia/etoile-mediakit \
	LanguageKit:lang/etoile-languagekit \
	SmalltalkSupport:lang/etoile-smalltalkkit \
	XMPPKit:net-im/etoile-xmppkit \

USE_GNUSTEP_SYSTEM_BUNDLES+=	\
	EtoileMenus:x11-themes/etoile-etoilemenus \
	EtoileBehavior:sysutils/etoile-behavior \

USE_GNUSTEP_LOCAL_BUNDLES+=	\

USE_GNUSTEP_SYSTEM_THEMES+=	\
	Camaelon:x11-themes/etoile-camaelon \

USE_GNUSTEP_LOCAL_THEMES+=	\
	WildMenus:x11-themes/etoile-wildmenus \

USE_GNUSTEP_LOCAL_MENULETS+=	\
	PowerMenulet:sysutils/etoile-powermenulet \
	ServiceMenulet:deskutils/etoile-servicemenulet \
	VolumeControlMenulet:audio/etoile-volumecontrolmenulet \

USE_GNUSTEP_LOCAL_ASTS+=	\
	CommentToLog:lang/etoile-lkplugins \

USE_GNUSTEP_SYSTEM_APPS+=	\
	Azalea:x11-wm/etoile-azalea \
	AZDock:x11-wm/etoile-azdock \
	AZBackground:x11-themes/etoile-azbackground \
	AZSwitch:x11-wm/etoile-azswitch \
	Login:x11-wm/etoile-login \
	EtoileMenuServer:deskutils/etoile-menuserver \

USE_GNUSTEP_LOCAL_APPS+=	\
	DictionaryReader:deskutils/etoile-dictionaryreader \
	iTerm:x11/etoile-iterm \
	Installer:sysutils/etoile-installer \
	Hardware:deskutils/etoile-hardware \
	LookAndBehavior:deskutils/etoile-lookandbehavior \
	Vindaloo:graphics/vindaloo \
	Typewriter:editors/etoile-typewriter \
	Babbler:multimedia/etoile-babbler \
	Mollusk:www/etoile-mollusk \
	FontManager:x11-fm/etoile-fontmanager \
	ScriptServices:deskutils/etoile-scriptservices \
	Melodie:audio/etoile-melodie \
	StepChat:net-im/etoile-stepchat \

#	Mantella:www/etoile-mantella \

USE_GNUSTEP_SYSTEM_TOOLS+=	\
	Idle:x11/etoile-idle \
	Corner:deskutils/etoile-corner \

USE_GNUSTEP_LOCAL_TOOLS+=	\
	ioobjc:lang/etoile-io \
	edlc:lang/etoile-compiler \

.include <bsd.port.mk>
