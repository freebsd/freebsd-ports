# New ports collection makefile for:	p5-Tk
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk
PORTVERSION=	804.030
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A re-port of a perl5 interface to Tk8.4

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

CONFIGURE_ARGS=	X11INC=${LOCALBASE}/include X11LIB=${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
PERL_CONFIGURE=	yes
USE_XORG=	x11

MAN1=		ptked.1 \
		ptksh.1 \
		tkjpeg.1 \
		widget.1
MAN3=		Tie::Watch.3 \
		Tk.3 \
		Tk::804delta.3 \
		Tk::Adjuster.3 \
		Tk::Animation.3 \
		Tk::Balloon.3 \
		Tk::Bitmap.3 \
		Tk::BrowseEntry.3 \
		Tk::Button.3 \
		Tk::Canvas.3 \
		Tk::Checkbutton.3 \
		Tk::Clipboard.3 \
		Tk::CmdLine.3 \
		Tk::ColorEditor.3 \
		Tk::Common.3 \
		Tk::Compound.3 \
		Tk::ConfigSpecs.3 \
		Tk::DItem.3 \
		Tk::Derived.3 \
		Tk::Dialog.3 \
		Tk::DialogBox.3 \
		Tk::DirTree.3 \
		Tk::DropSite.3 \
		Tk::Entry.3 \
		Tk::Error.3 \
		Tk::Eventloop.3 \
		Tk::FBox.3 \
		Tk::FileSelect.3 \
		Tk::Font.3 \
		Tk::Frame.3 \
		Tk::HList.3 \
		Tk::IO.3 \
		Tk::IconList.3 \
		Tk::Image.3 \
		Tk::InputO.3 \
		Tk::Internals.3 \
		Tk::JPEG.3 \
		Tk::LabFrame.3 \
		Tk::Label.3 \
		Tk::Labelframe.3 \
		Tk::Listbox.3 \
		Tk::MainWindow.3 \
		Tk::Menu.3 \
		Tk::Menu::Item.3 \
		Tk::Menubutton.3 \
		Tk::Message.3 \
		Tk::MsgBox.3 \
		Tk::Mwm.3 \
		Tk::NoteBook.3 \
		Tk::Optionmenu.3 \
		Tk::PNG.3 \
		Tk::Pane.3 \
		Tk::Panedwindow.3 \
		Tk::Photo.3 \
		Tk::Pixmap.3 \
		Tk::Popup.3 \
		Tk::ProgressBar.3 \
		Tk::ROText.3 \
		Tk::Radiobutton.3 \
		Tk::Reindex.3 \
		Tk::Scale.3 \
		Tk::Scrollbar.3 \
		Tk::Scrolled.3 \
		Tk::Spinbox.3 \
		Tk::Submethods.3 \
		Tk::SunConst.3 \
		Tk::TList.3 \
		Tk::Table.3 \
		Tk::Tcl-perl.3 \
		Tk::Text.3 \
		Tk::TextUndo.3 \
		Tk::Tiler.3 \
		Tk::TixGrid.3 \
		Tk::Toplevel.3 \
		Tk::Trace.3 \
		Tk::Tree.3 \
		Tk::UserGuide.3 \
		Tk::Widget.3 \
		Tk::WidgetDemo.3 \
		Tk::WinPhoto.3 \
		Tk::Wm.3 \
		Tk::X.3 \
		Tk::X11Font.3 \
		Tk::Xrm.3 \
		Tk::after.3 \
		Tk::bind.3 \
		Tk::bindtags.3 \
		Tk::callbacks.3 \
		Tk::chooseColor.3 \
		Tk::chooseDirectory.3 \
		Tk::composite.3 \
		Tk::demos::widget_lib::slide.3 \
		Tk::demos::widget_lib::trace2.3 \
		Tk::event.3 \
		Tk::exit.3 \
		Tk::fileevent.3 \
		Tk::focus.3 \
		Tk::form.3 \
		Tk::getOpenFile.3 \
		Tk::grab.3 \
		Tk::grid.3 \
		Tk::mega.3 \
		Tk::messageBox.3 \
		Tk::option.3 \
		Tk::options.3 \
		Tk::overview.3 \
		Tk::pTk.3 \
		Tk::pack.3 \
		Tk::palette.3 \
		Tk::place.3 \
		Tk::selection.3 \
		Tk::send.3 \
		Tk::tixWm.3 \
		Tk::tkvars.3 \
		Tk::widgets.3

.include <bsd.port.pre.mk>

.if defined(WITH_XFT)
CONFIGURE_ARGS=	XFT=1
USE_XORG+=	xft
.endif

.if !defined(WITH_XFT)
pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> An experimental implementation of client side fonts"
	@${ECHO_MSG} "===> and anti-aliased fonts via Xft"
	@${ECHO_MSG} "===> can be enabled by defining WITH_XFT"
	@${ECHO_MSG} "===>"
.endif

post-patch:
	@${PERL} -i -p -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/pTk/Makefile.PL \
		${WRKSRC}/JPEG/Makefile.PL \
		${WRKSRC}/PNG/Makefile.PL

post-configure:
	@${PERL} -i -p \
		-e 's|^(CC = ).*|$$1 ${CC}|;' \
		-e 's|^(CCFLAGS = ).*|$$1 ${CFLAGS}|;' \
		-e 's|^(LD = ).*|$$1 ${CC} ${CFLAGS} ${LDFLAGS}|;' \
		-e 's|^(FULL_AR = ).*|$$1 ${AR}|' \
		`${FIND} ${WRKSRC} -name Makefile`

.include <bsd.port.post.mk>
