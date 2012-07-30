# New ports collection makefile for: Prima
# Date created:        25 Sept 2001
# Whom:                dmitry@karasik.eu.org
#
# $FreeBSD$
#

PORTNAME=	Prima
PORTVERSION=	1.35
CATEGORIES=	x11-toolkits graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An extensible Perl toolkit for multi-platform GUI development

LICENSE=	BSD

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	GTK2 ICONV XFT
OPTIONS_DEFAULT=ICONV XFT

CONFIGURE_ARGS=	X11BASE=${LOCALBASE}
PERL_CONFIGURE=	yes
USE_PERL5=	yes
USE_XORG=	x11 xext xpm xrender

MAN1=		VB.1 \
		cfgmaint.1 \
		fmview.1 \
		gencls.1 \
		p-class.1 \
		podview.1 \
		tmlink.1
MAN3=		Prima.3 \
		Prima::Application.3 \
		Prima::Buttons.3 \
		Prima::Calendar.3 \
		Prima::Classes.3 \
		Prima::ColorDialog.3 \
		Prima::ComboBox.3 \
		Prima::Config.3 \
		Prima::Const.3 \
		Prima::CurvedText.3 \
		Prima::DetailedList.3 \
		Prima::DetailedOutline.3 \
		Prima::DockManager.3 \
		Prima::Docks.3 \
		Prima::Edit.3 \
		Prima::EditDialog.3 \
		Prima::EventHook.3 \
		Prima::ExtLists.3 \
		Prima::FileDialog.3 \
		Prima::FontDialog.3 \
		Prima::FrameSet.3 \
		Prima::Gencls.3 \
		Prima::Grids.3 \
		Prima::Header.3 \
		Prima::HelpViewer.3 \
		Prima::Image::AnimateGIF.3 \
		Prima::Image::TransparencyControl.3 \
		Prima::Image::gif.3 \
		Prima::Image::jpeg.3 \
		Prima::Image::tiff.3 \
		Prima::ImageDialog.3 \
		Prima::ImageViewer.3 \
		Prima::IniFile.3 \
		Prima::InputLine.3 \
		Prima::IntUtils.3 \
		Prima::KeySelector.3 \
		Prima::Label.3 \
		Prima::Lists.3 \
		Prima::MDI.3 \
		Prima::MsgBox.3 \
		Prima::Notebooks.3 \
		Prima::Outlines.3 \
		Prima::PS::Drawable.3 \
		Prima::PS::Encodings.3 \
		Prima::PS::Fonts.3 \
		Prima::PS::Printer.3 \
		Prima::PS::Setup.3 \
		Prima::PodView.3 \
		Prima::PrintDialog.3 \
		Prima::RubberBand.3 \
		Prima::ScrollBar.3 \
		Prima::ScrollWidget.3 \
		Prima::Sliders.3 \
		Prima::StartupWindow.3 \
		Prima::StdBitmap.3 \
		Prima::StdDlg.3 \
		Prima::Stress.3 \
		Prima::Terminals.3 \
		Prima::TextView.3 \
		Prima::Themes.3 \
		Prima::Tie.3 \
		Prima::Utils.3 \
		Prima::VB::CfgMaint.3 \
		Prima::VB::Classes.3 \
		Prima::VB::Config.3 \
		Prima::VB::CoreClasses.3 \
		Prima::VB::VBControls.3 \
		Prima::VB::VBLoader.3 \
		Prima::VB::examples::Widgety.3 \
		Prima::Widgets.3 \
		Prima::noARGV.3 \
		Prima::noX11.3 \
		Prima::sys::gtk2::FileDialog.3 \
		Prima::sys::win32::FileDialog.3 \
		Prima::themes::color.3 \
		Prima::themes::round3d.3 \
		Prima::themes::sysimage.3 \
		Prima::themes::tabset.3 \
		pod::Prima::Clipboard.3 \
		pod::Prima::Drawable.3 \
		pod::Prima::File.3 \
		pod::Prima::Image.3 \
		pod::Prima::Menu.3 \
		pod::Prima::Object.3 \
		pod::Prima::Printer.3 \
		pod::Prima::Timer.3 \
		pod::Prima::Widget.3 \
		pod::Prima::Widget::pack.3 \
		pod::Prima::Widget::place.3 \
		pod::Prima::Window.3 \
		pod::Prima::X11.3 \
		pod::Prima::codecs.3 \
		pod::Prima::faq.3 \
		pod::Prima::gp-problems.3 \
		pod::Prima::image-load.3 \
		pod::Prima::internals.3 \
		pod::Prima::tutorial.3 \
		pod::gencls.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=WITH_ICONV=0
.endif
.else
CONFIGURE_ARGS+=WITH_XFT=0
.endif

.if ${PORT_OPTIONS:MGTK}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=WITH_GTK2=1
.endif

.include <bsd.port.mk>
