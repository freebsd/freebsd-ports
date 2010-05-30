# New ports collection makefile for:    gnustep-app
# Date created:         28 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-app
PORTVERSION=	1.19.1
PORTREVISION=	1
CATEGORIES=	x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Metaport for GNUstep applications

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
	ScriptKit:lang/gnustep-guile \
	Renaissance:x11-toolkits/renaissance \
	PreferencePanes:deskutils/preferencepanes \
	TrackerKit:deskutils/etoile-trackerkit \
	ExtendedWorkspace:deskutils/etoile-extendedworkspacekit \
	ServicesBarKit:deskutils/etoile-servicesbarkit \
	XWindowServerKit:x11/etoile-xwindowserverkit \
	WorkspaceCommKit:sysutils/etoile-system \

USE_GNUSTEP_LOCAL_LIBS+=	\
	Pantomime:mail/pantomime \
	GToolKit:x11-toolkits/gtoolkit \
	rigs:devel/ruby-gnustep \
	Addresses:mail/addresses \
	SlideShow:graphics/gnustep-slideshowkit \
	netclasses:net/netclasses \
	EOInterface:databases/gdl2 \
	WizardKit:devel/wizardkit \
	HighlighterKit:devel/highlighterkit \
	Performance:devel/performance \
	SQLClient:databases/sqlclient \
	WebServer:www/webserver \
	StepTalk:lang/steptalk \
	MathArray:math/matharray \
	ObjcUnit:devel/objcunit \
	GSKrab:x11/gskrab \
	UnitKit:devel/etoile-unitkit \
	BookmarkKit:www/etoile-bookmarkkit \
	IconKit:x11-themes/etoile-iconkit \
	RSSKit:www/etoile-rsskit \
	Encore:devel/fortytwo-encore \
	BDB:databases/fortytwo-bdb \
	FT:graphics/fortytwo \
	ObjectiveLib:devel/objectivelib \
	PopplerKit:graphics/popplerkit \
	CameraKit:graphics/camerakit \
	Toolbox:deskutils/toolboxkit \
	Tryst:net/tryst \
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
	WebServices:www/webservices \

USE_GNUSTEP_SYSTEM_BUNDLES+=	\
	EtoileMenus:x11-themes/etoile-etoilemenus \
	EtoileBehavior:sysutils/etoile-behavior \

USE_GNUSTEP_LOCAL_BUNDLES+=	\
	Cddb:audio/cddb-bundle	\

USE_GNUSTEP_LOCAL_BURNS+=	\
	MP3ToWav:audio/mp3towav-bundle \

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
	Gorm:devel/gorm \
	GShisen:games/gshisen \
	ProjectCenter:devel/projectcenter.app \
	Preferences:deskutils/preferences.app \
	GWorkspace:deskutils/gworkspace \
	TextEdit:editors/textedit.app \
	Terminal:x11/terminal.app \
	Emacs:editors/emacs.app \
	GSPdf:print/gspdf \
	SystemPreferences:deskutils/systempreferences \
	WrapperFactory:deskutils/gnustep-wrapper \
	GRubik:games/grubik \
	Azalea:x11-wm/etoile-azalea \
	AZDock:x11-wm/etoile-azdock \
	Position:astro/position \
	AZBackground:x11-themes/etoile-azbackground \
	ClipBook:deskutils/gworkspace-clipbook \
	MDFinder:deskutils/gworkspace-gwmetadata \
	AZSwitch:x11-wm/etoile-azswitch \
	Login:x11-wm/etoile-login \
	EtoileMenuServer:deskutils/etoile-menuserver \

USE_GNUSTEP_LOCAL_APPS+=	\
	Gomoku:games/gomoku.app \
	GNUMail:mail/gnumail \
	EasyDiff:textproc/easydiff \
	Ink:misc/gnustep-examples \
	GSCommander:shells/gscommander \
	ImageViewer:graphics/imageviewer \
	SlideShow:graphics/gnustep-slideshow \
	Preview:graphics/preview \
	oolite:games/oolite \
	TimeMon:sysutils/timemon \
	Cenon:graphics/cenon \
	Gridlock:games/gridlock \
	PRICE:graphics/price \
	EdenMath:math/edenmath \
	Stepulator:math/stepulator \
	VolumeControl:audio/volumecontrol.app \
	Cynthiune:audio/cynthiune \
	TalkSoup:irc/talksoup \
	Grouch:net-im/grouch \
	Zipper:archivers/zipper \
	Camera:graphics/camera \
	Ladder:games/gnustep-ladder \
	StepBill:games/stepbill \
	Charmap:deskutils/charmap \
	GTAMSAnalyzer:science/gtamsanalyzer \
	Paje:science/paje \
	AClock:x11-clocks/aclock \
	PhotoClip:graphics/photoclip \
	LapisPuzzle:games/lapispuzzle \
	Waiho:ftp/waiho \
	Affiche:deskutils/affiche \
	ProjectManager:devel/projectmanager \
	GMastermind2:games/gmastermind \
	Jigsaw:games/jigsaw \
	Ticker:www/gnustep-ticker \
	NoteBook:deskutils/gnustep-notebook \
	HelpViewer:deskutils/helpviewer \
	Duncan:textproc/duncan \
	Jishyo:japanese/jishyo \
	GMines:games/gmines \
	InnerSpace:x11/innerspace \
	FTP:ftp/gnustep-ftp \
	DictionaryReader:deskutils/etoile-dictionaryreader \
	batmon:sysutils/batmon \
	UL:biology/adun \
	RemoteDesk:net/remotedesk \
	DisplayCalibrator:deskutils/displaycalibrator \
	GNUWash:deskutils/gnuwash \
	Poe:multimedia/poe \
	MPDCon:audio/mpdcon \
	PlopFolio:deskutils/plopfolio \
	CDPlayer:audio/gnustep-cdplayer \
	Burn:sysutils/burn \
	GScheme:lang/gscheme \
	Mplayer:multimedia/gnustep-mplayer \
	MyLibrary:databases/mylibrary \
	NeXTGo:games/nextgo \
	iTerm:x11/etoile-iterm \
	Installer:sysutils/etoile-installer \
	Hardware:deskutils/etoile-hardware \
	LookAndBehavior:deskutils/etoile-lookandbehavior \
	Expense:finance/expense \
	FreeTar:archivers/freetar \
	CodeEditor:editors/codeeditor \
	Localize:textproc/localize \
	GSBench:benchmarks/gsbench \
	SVGViewer:graphics/svgviewer \
	Vindaloo:graphics/vindaloo \
	Digibux:german/digibux \
	AppWrapper:deskutils/appwrapper \
	Pixen:graphics/pixen \
	MyWiki:deskutils/mywiki \
	Cartotheque:deskutils/cartotheque \
	LuserNET:news/lusernet \
	Popup:textproc/popup \
	Toolbox:deskutils/toolbox \
	Fortunate:games/fortunate \
	TBrowser:net/tryst-examples \
	Typewriter:editors/etoile-typewriter \
	Babbler:multimedia/etoile-babbler \
	Mollusk:www/etoile-mollusk \
	BioCocoa:biology/biococoa \
	Yap:graphics/yap \
	Sudoku:games/gnustep-sudoku \
	FontManager:x11-fm/etoile-fontmanager \
	ScriptServices:deskutils/etoile-scriptservices \
	Melodie:audio/etoile-melodie \
	StepChat:net-im/etoile-stepchat \
	LaternaMagica:graphics/laternamagica \
	SimpleAgenda:deskutils/simpleagenda \

#	CameraTransfer:graphics/cameratransfer \
#	Mantella:www/etoile-mantella \

USE_GNUSTEP_SYSTEM_TOOLS+=	\
	Idle:x11/etoile-idle \
	Corner:deskutils/etoile-corner \

USE_GNUSTEP_LOCAL_TOOLS+=	\
	zillion:net/zillion \
	adtool:mail/addresses-goodies \
	ioobjc:lang/etoile-io \
	edlc:lang/etoile-compiler \

#	open:deskutils/openapp \

USE_GNUSTEP_LOCAL_SERVICES+=	\
	LaTeX:textproc/latex-service \

.include <bsd.port.mk>
