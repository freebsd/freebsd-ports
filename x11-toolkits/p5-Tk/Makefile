# New ports collection makefile for:	p5-Tk
# Version required:			402.002
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.23 1998/11/28 09:07:24 asami Exp $
#

DISTNAME=	Tk800.008
PKGNAME=	p5-Tk-800.008
CATEGORIES=	x11-toolkits tk80 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk

MAINTAINER=	jfitz@FreeBSD.ORG

USE_XLIB=	YES
USE_PERL5=	YES

MAN1=	ptked.1 ptksh.1 widget.1

MAN3=	Tk::Adjuster.3 Tk::After.3 Tk::Animation.3 Tk::Balloon.3 \
	Tk::Bitmap.3 Tk::BrowseEntry.3 Tk::Button.3 Tk::Canvas.3 \
	Tk::Checkbutton.3 Tk::Clipboard.3 Tk::CmdLine.3 Tk::ColorEditor.3 \
	Tk::Common.3 Tk::DItem.3 Tk::Derived.3 Tk::Dialog.3 Tk::DialogBox.3 \
	Tk::DirTree.3 Tk::Entry.3 Tk::Error.3 Tk::FileSelect.3 Tk::Font.3 \
	Tk::Frame.3 Tk::HList.3 Tk::IO.3 Tk::Image.3 Tk::InputO.3 \
	Tk::Internals.3 Tk::Item.3 Tk::LabFrame.3 Tk::Label.3 Tk::Listbox.3 \
	Tk::MainWindow.3 Tk::Menu.3 Tk::Menubutton.3 Tk::Message.3 Tk::Mwm.3 \
	Tk::NoteBook.3 Tk::Optionmenu.3 Tk::Photo.3 Tk::Pixmap.3 Tk::ROText.3 \
	Tk::Radiobutton.3 Tk::Scale.3 Tk::Scrollbar.3 Tk::Scrolled.3 \
	Tk::Submethods.3 Tk::SunConst.3 Tk::TList.3 Tk::Table.3 Tk::Tcl-perl.3 \
	Tk::Text.3 Tk::TextUndo.3 Tk::Tiler.3 Tk::TixGrid.3 Tk::Toplevel.3 \
	Tk::Tree.3 Tk::UserGuide.3 Tk::Widget.3 Tk::WidgetDemo.3 Tk::Wm.3 \
	Tk::X.3 Tk::Xrm.3 Tk::bind.3 Tk::bindtags.3 Tk::callbacks.3 \
	Tk::chooseColor.3 Tk::composite.3 Tk::configspec.3 Tk::event.3 \
	Tk::exit.3 Tk::fileevent.3 Tk::focus.3 Tk::form.3 Tk::getOpenFile.3 \
	Tk::grab.3 Tk::grid.3 Tk::mega.3 Tk::messageBox.3 Tk::option.3 \
	Tk::options.3 Tk::overview.3 Tk::pTk.3 Tk::pack.3 Tk::palette.3 \
	Tk::place.3 Tk::selection.3 Tk::send.3 Tk::tixWm.3 Tk::tkvars.3 \
	Tk::widgets.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX} INSTALLSCRIPT=${PREFIX}/bin INSTALLMAN1DIR=${PREFIX}/man/man1

.include <bsd.port.mk>
