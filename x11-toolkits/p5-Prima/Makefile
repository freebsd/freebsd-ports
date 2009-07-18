# New ports collection makefile for: Prima
# Date created:        25 Sept 2001
# Whom:                dmitry@karasik.eu.org
#
# $FreeBSD$
#

PORTNAME=	Prima
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5 graphics
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@karasik.eu.org
COMMENT=	An extensible Perl toolkit for multi-platform GUI development

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

MAN1=	gencls.1.gz VB.1.gz cfgmaint.1.gz
MAN3=	Prima::Image::AnimateGIF.3.gz Prima::Clipboard.3.gz Prima::CurvedText.3.gz \
	Prima::Drawable.3.gz Prima::File.3.gz Prima::Image.3.gz \
	Prima::Menu.3.gz Prima::Object.3.gz Prima::Printer.3.gz Prima::Timer.3.gz  \
	Prima::Widget.3.gz Prima::Widget::pack.3.gz Prima::Widget::place.3.gz  \
	Prima::Window.3.gz Prima::codecs.3.gz Prima::gp-problems.3.gz Prima::image-load.3.gz  \
	Prima::faq.3.gz Prima::internals.3.gz Prima.3.gz Prima::Image::TransparencyControl.3.gz  \
	Prima::PS::Encodings.3.gz Prima::PS::Fonts.3.gz Prima::PS::Printer.3.gz  \
	Prima::PS::Drawable.3.gz Prima::VB::CfgMaint.3.gz Prima::VB::Classes.3.gz  \
	Prima::VB::VBLoader.3.gz Prima::ComboBox.3.gz Prima::Application.3.gz Prima::Buttons.3.gz  \
	Prima::ColorDialog.3.gz Prima::Const.3.gz Prima::DockManager.3.gz Prima::Docks.3.gz  \
	Prima::EditDialog.3.gz Prima::ExtLists.3.gz Prima::FontDialog.3.gz Prima::Grids.3.gz  \
	Prima::Lists.3.gz Prima::Header.3.gz Prima::DetailedList.3.gz Prima::DetailedOutline.3.gz  \
	Prima::Edit.3.gz Prima::ImageViewer.3.gz Prima::IniFile.3.gz Prima::ImageDialog.3.gz  \
	Prima::InputLine.3.gz Prima::IntUtils.3.gz Prima::KeySelector.3.gz Prima::Label.3.gz  \
	Prima::MDI.3.gz Prima::MsgBox.3.gz Prima::Notebooks.3.gz Prima::noX11.3.gz Prima::Outlines.3.gz  \
	Prima::PrintDialog.3.gz Prima::ScrollBar.3.gz Prima::ScrollWidget.3.gz  \
	Prima::StartupWindow.3.gz Prima::StdBitmap.3.gz Prima::StdDlg.3.gz Prima::Stress.3.gz  \
	Prima::Themes.3.gz Prima::Utils.3.gz Prima::Widgets.3.gz Prima::Classes.3.gz  \
	Prima::FileDialog.3.gz Prima::PodView.3.gz Prima::Sliders.3.gz Prima::FrameSet.3.gz  \
	Prima::TextView.3.gz Prima::Tie.3.gz Prima::HelpViewer.3.gz Prima::Calendar.3.gz Prima::X11.3.gz  \
	Prima::EventHook.3.gz Prima::sys::win32::FileDialog.3.gz Prima::tutorial.3.gz \
	Prima::sys::gtk2::FileDialog.3.gz

CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALL_MAN3="${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3" \
			INSTALL_MAN1="${PREFIX}/man/man1" X11BASE="${LOCALBASE}"
CONFIGURE_SCRIPT=	Makefile.PL
USE_XORG=		x11 xpm xext xrender
USE_PERL5=		yes
MAN3PREFIX=		lib/perl5/${PERL_VERSION}
NOMANCOMPRESS=	yes

post-configure:
	@cd ${CONFIGURE_WRKSRC} && ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

test: build
	cd ${WRKSRC} && make test

post-install:
	${STRIP_CMD} ${SITE_PERL}/${PERL_ARCH}/auto/Prima/Prima.so

.if defined (WITHOUT_XFT)
CONFIGURE_ARGS+=	WITH_XFT=0
.else
USE_XORG+=		xft
.if defined (WITHOUT_ICONV)
CONFIGURE_ARGS+=	WITH_ICONV=0
.else
USE_ICONV=	yes
.endif
.endif

.if defined(WITH_GTK)
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	WITH_GTK2=1
.endif

.include <bsd.port.mk>
