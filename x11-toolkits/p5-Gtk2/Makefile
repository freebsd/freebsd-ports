# New ports collection makefile for:		x11-toolkits/p5-Gtk2
# Date created:					Oct 27 2003
# Whom:						clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2
PORTVERSION=	1.021
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl \
		gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Perl module for Gtk+ 2.x graphical user interface library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20
PERL_CONFIGURE=	yes
USE_GMAKE=	yes

MAN3=		Gtk2.3 \
	Gtk2::AccelGroup.3 \
	Gtk2::AccelLabel.3 \
	Gtk2::Accelerator.3 \
	Gtk2::Adjustment.3 \
	Gtk2::Alignment.3 \
	Gtk2::Arrow.3 \
	Gtk2::AspectFrame.3 \
	Gtk2::Bin.3 \
	Gtk2::Box.3 \
	Gtk2::Button.3 \
	Gtk2::ButtonBox.3 \
	Gtk2::Calendar.3 \
	Gtk2::CellEditable.3 \
	Gtk2::CellRenderer.3 \
	Gtk2::CellRendererPixbuf.3 \
	Gtk2::CellRendererText.3 \
	Gtk2::CellRendererToggle.3 \
	Gtk2::CheckButton.3 \
	Gtk2::CheckMenuItem.3 \
	Gtk2::Clipboard.3 \
	Gtk2::CodeGen.3 \
	Gtk2::ColorSelection.3 \
	Gtk2::ColorSelectionDialog.3 \
	Gtk2::Combo.3 \
	Gtk2::Container.3 \
	Gtk2::Curve.3 \
	Gtk2::Dialog.3 \
	Gtk2::Drag.3 \
	Gtk2::DrawingArea.3 \
	Gtk2::Editable.3 \
	Gtk2::Entry.3 \
	Gtk2::EventBox.3 \
	Gtk2::FileSelection.3 \
	Gtk2::Fixed.3 \
	Gtk2::FontSelection.3 \
	Gtk2::FontSelectionDialog.3 \
	Gtk2::Frame.3 \
	Gtk2::GammaCurve.3 \
	Gtk2::Gdk.3 \
	Gtk2::Gdk::Atom.3 \
	Gtk2::Gdk::Bitmap.3 \
	Gtk2::Gdk::Color.3 \
	Gtk2::Gdk::Colormap.3 \
	Gtk2::Gdk::Cursor.3 \
	Gtk2::Gdk::Display.3 \
	Gtk2::Gdk::DisplayManager.3 \
	Gtk2::Gdk::DragContext.3 \
	Gtk2::Gdk::Drawable.3 \
	Gtk2::Gdk::Event.3 \
	Gtk2::Gdk::GC.3 \
	Gtk2::Gdk::Geometry.3 \
	Gtk2::Gdk::Keymap.3 \
	Gtk2::Gdk::Keysyms.3 \
	Gtk2::Gdk::Keyval.3 \
	Gtk2::Gdk::Pixbuf.3 \
	Gtk2::Gdk::PixbufAnimation.3 \
	Gtk2::Gdk::PixbufAnimationIter.3 \
	Gtk2::Gdk::PixbufLoader.3 \
	Gtk2::Gdk::Pixmap.3 \
	Gtk2::Gdk::Rectangle.3 \
	Gtk2::Gdk::Rgb.3 \
	Gtk2::Gdk::Screen.3 \
	Gtk2::Gdk::Selection.3 \
	Gtk2::Gdk::Threads.3 \
	Gtk2::Gdk::Window.3 \
	Gtk2::HBox.3 \
	Gtk2::HButtonBox.3 \
	Gtk2::HPaned.3 \
	Gtk2::HRuler.3 \
	Gtk2::HScale.3 \
	Gtk2::HScrollbar.3 \
	Gtk2::HSeparator.3 \
	Gtk2::HandleBox.3 \
	Gtk2::Helper.3 \
	Gtk2::IconFactory.3 \
	Gtk2::IconSet.3 \
	Gtk2::IconSize.3 \
	Gtk2::IconSource.3 \
	Gtk2::Image.3 \
	Gtk2::ImageMenuItem.3 \
	Gtk2::InputDialog.3 \
	Gtk2::Invisible.3 \
	Gtk2::Item.3 \
	Gtk2::ItemFactory.3 \
	Gtk2::Label.3 \
	Gtk2::Layout.3 \
	Gtk2::List.3 \
	Gtk2::ListItem.3 \
	Gtk2::ListStore.3 \
	Gtk2::Menu.3 \
	Gtk2::MenuBar.3 \
	Gtk2::MenuItem.3 \
	Gtk2::MenuShell.3 \
	Gtk2::MessageDialog.3 \
	Gtk2::Misc.3 \
	Gtk2::Notebook.3 \
	Gtk2::Object.3 \
	Gtk2::OptionMenu.3 \
	Gtk2::Paned.3 \
	Gtk2::Pango.3 \
	Gtk2::Pango::Context.3 \
	Gtk2::Pango::FontDescription.3 \
	Gtk2::Pango::FontFamily.3 \
	Gtk2::Pango::FontMetrics.3 \
	Gtk2::Pango::Layout.3 \
	Gtk2::Pango::TabArray.3 \
	Gtk2::Plug.3 \
	Gtk2::ProgressBar.3 \
	Gtk2::RadioButton.3 \
	Gtk2::RadioMenuItem.3 \
	Gtk2::Range.3 \
	Gtk2::Rc.3 \
	Gtk2::RcStyle.3 \
	Gtk2::Requisition.3 \
	Gtk2::Ruler.3 \
	Gtk2::Scale.3 \
	Gtk2::Scrollbar.3 \
	Gtk2::ScrolledWindow.3 \
	Gtk2::Selection.3 \
	Gtk2::SelectionData.3 \
	Gtk2::Separator.3 \
	Gtk2::SeparatorMenuItem.3 \
	Gtk2::SimpleList.3 \
	Gtk2::SimpleMenu.3 \
	Gtk2::SizeGroup.3 \
	Gtk2::Socket.3 \
	Gtk2::SpinButton.3 \
	Gtk2::Statusbar.3 \
	Gtk2::Stock.3 \
	Gtk2::Style.3 \
	Gtk2::Table.3 \
	Gtk2::TargetList.3 \
	Gtk2::TearoffMenuItem.3 \
	Gtk2::TextAttributes.3 \
	Gtk2::TextBuffer.3 \
	Gtk2::TextIter.3 \
	Gtk2::TextMark.3 \
	Gtk2::TextTag.3 \
	Gtk2::TextTagTable.3 \
	Gtk2::TextView.3 \
	Gtk2::ToggleButton.3 \
	Gtk2::Toolbar.3 \
	Gtk2::Tooltips.3 \
	Gtk2::TreeDragDest.3 \
	Gtk2::TreeDragSource.3 \
	Gtk2::TreeModel.3 \
	Gtk2::TreeModelSort.3 \
	Gtk2::TreePath.3 \
	Gtk2::TreeRowReference.3 \
	Gtk2::TreeSelection.3 \
	Gtk2::TreeSortable.3 \
	Gtk2::TreeStore.3 \
	Gtk2::TreeView.3 \
	Gtk2::TreeViewColumn.3 \
	Gtk2::VBox.3 \
	Gtk2::VButtonBox.3 \
	Gtk2::VPaned.3 \
	Gtk2::VRuler.3 \
	Gtk2::VScale.3 \
	Gtk2::VScrollbar.3 \
	Gtk2::VSeparator.3 \
	Gtk2::Viewport.3 \
	Gtk2::Widget.3 \
	Gtk2::Window.3 \
	Gtk2::api.3 \
	Gtk2::devel.3 \
	Gtk2::index.3 \
	Gtk2::main.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
