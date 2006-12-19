# New ports collection makefile for:    gnustep-app
# Date created:         28 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-app
PORTVERSION=	1.13.0
PORTREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Metaport for GNUstep applications

NO_BUILD=	yes
NO_INSTALL=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_XLIB=	yes
USE_GNUSTEP_LIBART=	yes

USE_GNUSTEP_SYSTEM_LIBS+=	\
	ScriptKit:lang/gnustep-guile \
	gnustep-db2:databases/gdl2 \
	Renaissance:x11-toolkits/renaissance \
	PreferencePanes:deskutils/preferencepanes \
	TrackerKit:deskutils/etoile-trackerkit \
	PreferencesKit:deskutils/etoile-preferenceskit \
	ExtendedWorkspace:deskutils/etoile-extendedworkspacekit \
	BookmarkKit:www/etoile-bookmarkkit \
	ServicesBarKit:deskutils/etoile-servicesbarkit \
	IconKit:x11-themes/etoile-iconkit \

USE_GNUSTEP_LOCAL_LIBS+=	\
	Pantomime:mail/pantomime \
	GToolKit:x11-toolkits/gtoolkit \
	rigs:devel/ruby-gnustep \
	Addresses:mail/addresses \
	SlideShow:graphics/gnustep-slideshowkit \
	netclasses:net/netclasses \
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
	XWindowServerKit:x11/etoile-xwindowserverkit \
	RSSKit:www/etoile-rsskit \
	EtoileExtensions:deskutils/etoile-etoileextensionskit \
	Encore:devel/fortytwo-encore \
	BDB:databases/fortytwo-bdb \
	FT:graphics/fortytwo \
	ObjectiveLib:devel/objectivelib \
	PopplerKit:graphics/popplerkit \
	CameraKit:graphics/camerakit \

USE_GNUSTEP_SYSTEM_BUNDLES+=	\
	EtoileMenus:x11-themes/etoile-etoilemenus \

USE_GNUSTEP_LOCAL_BUNDLES+=	\
	Cddb:audio/cddb-bundle	\
	MP3ToWav:audio/mp3towav-bundle \

USE_GNUSTEP_SYSTEM_THEMES+=	\
	Camaelon:x11-themes/etoile-camaelon \

USE_GNUSTEP_LOCAL_THEMES+=	\
	WildMenus:x11-themes/etoile-wildmenus

USE_GNUSTEP_SYSTEM_APPS+=	\
	Gorm:devel/gorm \
	GShisen:games/gshisen \
	ProjectCenter:devel/projectcenter.app \
	Preferences:deskutils/preferences.app \
	GWorkspace:deskutils/gworkspace \
	TextEdit:editors/textedit.app \
	TimeMon:sysutils/timemon \
	Terminal:x11/terminal.app \
	Emacs:editors/emacs.app \
	GSPdf:print/gspdf \
	SystemPreferences:deskutils/systempreferences \
	WrapperFactory:deskutils/gnustep-wrapper \
	GRubik:games/grubik \
	AZDock:x11-wm/etoile-azdock \

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
	GPuzzle2:games/gpuzzle \
	Ticker:www/gnustep-ticker \
	NoteBook:deskutils/gnustep-notebook \
	HelpViewer:deskutils/helpviewer \
	Duncan:textproc/duncan \
	Jishyo:japanese/jishyo \
	GMines:games/gmines \
	InnerSpace:x11/innerspace \
	FTP:ftp/gnustep-ftp \
	DictionaryReader:deskutils/etoile \
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
	Grr:www/etoile-grr \
	iTerm:x11/etoile-iterm \
	Installer:sysutils/etoile-installer \
	Hardware:deskutils/etoile-hardware \
	LookAndBehavior:deskutils/etoile-lookandbehavior \
	Azalea:x11-wm/etoile-azalea \
	EtoileMenuServer:deskutils/etoile-menuserver \
	Position:astro/position \
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

USE_GNUSTEP_LOCAL_TOOLS+=	\
	zillion:net/zillion \
	adtool:mail/addresses-goodies \

.include <bsd.port.mk>
