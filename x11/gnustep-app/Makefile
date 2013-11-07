# Created by: dirk.meyer@dinoex.sub.org
# $FreeBSD$

PORTNAME=	gnustep-app
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Metaport for GNUstep applications

NO_BUILD=	yes
NO_INSTALL=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BACK=	yes

USE_GNUSTEP_SYSTEM_LIBS+=	\
	PreferencePanes:deskutils/preferencepanes \

USE_GNUSTEP_LOCAL_LIBS+=	\
	Pantomime:mail/pantomime \
	Addresses:mail/addresses \
	BioCocoa:biology/biococoa \
	SlideShow:graphics/gnustep-slideshowkit \
	WizardKit:devel/wizardkit \
	HighlighterKit:devel/highlighterkit \
	GSKrab:x11/gskrab \
	Encore:devel/fortytwo-encore \
	BDB:databases/fortytwo-bdb \
	FT:graphics/fortytwo \
	CameraKit:graphics/camerakit \
	Toolbox:deskutils/toolboxkit \

USE_GNUSTEP_LOCAL_BUNDLES+=	\
	Cddb:audio/cddb-bundle	\

USE_GNUSTEP_SYSTEM_APPS+=	\
	Gorm:devel/gorm \
	GShisen:games/gshisen \
	GWorkspace:deskutils/gworkspace \
	Terminal:x11/terminal.app \
	GSPdf:print/gspdf \
	SystemPreferences:deskutils/systempreferences \
	WrapperFactory:deskutils/gnustep-wrapper \
	GRubik:games/grubik \
	MDFinder:deskutils/gworkspace-gwmetadata \

USE_GNUSTEP_LOCAL_APPS+=	\
	GNUMail:mail/gnumail \
	EasyDiff:textproc/easydiff \
	ImageViewer:graphics/imageviewer \
	SlideShow:graphics/gnustep-slideshow \
	Preview:graphics/preview \
	TimeMon:sysutils/timemon \
	Cenon:graphics/cenon \
	PRICE:graphics/price \
	EdenMath:math/edenmath \
	Zipper:archivers/zipper \
	Camera:graphics/camera \
	Ladder:games/gnustep-ladder \
	Charmap:deskutils/charmap \
	GTAMSAnalyzer:science/gtamsanalyzer \
	Paje:science/paje \
	AClock:x11-clocks/aclock \
	LapisPuzzle:games/lapispuzzle \
	Waiho:ftp/waiho \
	Affiche:deskutils/affiche \
	GMastermind:games/gmastermind \
	Jigsaw:games/jigsaw \
	NoteBook:deskutils/gnustep-notebook \
	HelpViewer:deskutils/helpviewer \
	Duncan:textproc/duncan \
	Jishyo:japanese/jishyo \
	GMines:games/gmines \
	InnerSpace:x11/innerspace \
	FTP:ftp/gnustep-ftp \
	batmon:sysutils/batmon \
	RemoteDesk:net/remotedesk \
	DisplayCalibrator:deskutils/displaycalibrator \
	Poe:multimedia/poe \
	MPDCon:audio/mpdcon \
	PlopFolio:deskutils/plopfolio \
	CDPlayer:audio/gnustep-cdplayer \
	GScheme:lang/gscheme \
	NeXTGo:games/nextgo \
	Expense:finance/expense \
	FreeTar:archivers/freetar \
	Localize:textproc/localize \
	AppWrapper:deskutils/appwrapper \
	Pixen:graphics/pixen \
	Cartotheque:deskutils/cartotheque \
	LuserNET:news/lusernet \
	Popup:textproc/popup \
	Fortunate:games/fortunate \
	Sudoku:games/gnustep-sudoku \
	LaternaMagica:graphics/laternamagica \
	SimpleAgenda:deskutils/simpleagenda \

USE_GNUSTEP_LOCAL_TOOLS+=	\
	zillion:net/zillion \
	adtool:mail/addresses-goodies \


USE_GNUSTEP_LOCAL_SERVICES+=	\
	LaTeX:textproc/latex-service \

NO_STAGE=	yes
.include <bsd.port.mk>
