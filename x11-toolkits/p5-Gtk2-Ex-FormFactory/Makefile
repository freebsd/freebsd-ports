# New ports collection makefile for:	p5-Gtk2-Ex-FormFactory
# Date created:		2006/12/22
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	Gtk2-Ex-FormFactory
PORTVERSION=	0.65
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makes building complex GUI more easy

BUILD_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-Simple-List>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Gtk2::Ex::FormFactory::Menu.3 Gtk2::Ex::FormFactory::VSeparator.3 \
	Gtk2::Ex::FormFactory::Window.3 Gtk2::Ex::FormFactory::Timestamp.3 \
	Gtk2::Ex::FormFactory::Notebook.3 Gtk2::Ex::FormFactory::RadioButton.3 \
	Gtk2::Ex::FormFactory::ToggleButton.3 Gtk2::Ex::FormFactory::Context.3 \
	Gtk2::Ex::FormFactory::Intro.3 Gtk2::Ex::FormFactory::DialogButtons.3 \
	Gtk2::Ex::FormFactory.3 Gtk2::Ex::FormFactory::CheckButtonGroup.3 \
	Gtk2::Ex::FormFactory::YesNo.3 Gtk2::Ex::FormFactory::Expander.3 \
	Gtk2::Ex::FormFactory::Combo.3 Gtk2::Ex::FormFactory::GtkWidget.3 \
	Gtk2::Ex::FormFactory::Popup.3 Gtk2::Ex::FormFactory::Rules.3 \
	Gtk2::Ex::FormFactory::Label.3 Gtk2::Ex::FormFactory::List.3 \
	Gtk2::Ex::FormFactory::Layout.3 Gtk2::Ex::FormFactory::TextView.3 \
	Gtk2::Ex::FormFactory::Entry.3 Gtk2::Ex::FormFactory::CheckButton.3 \
	Gtk2::Ex::FormFactory::Widget.3 Gtk2::Ex::FormFactory::VPaned.3 \
	Gtk2::Ex::FormFactory::Container.3 Gtk2::Ex::FormFactory::HSeparator.3 \
	Gtk2::Ex::FormFactory::Table.3 Gtk2::Ex::FormFactory::Image.3 \
	Gtk2::Ex::FormFactory::ProxyBuffered.3 Gtk2::Ex::FormFactory::Proxy.3 \
	Gtk2::Ex::FormFactory::Button.3 Gtk2::Ex::FormFactory::ProgressBar.3 \
	Gtk2::Ex::FormFactory::HBox.3 Gtk2::Ex::FormFactory::ExecFlow.3 \
	Gtk2::Ex::FormFactory::VBox.3 Gtk2::Ex::FormFactory::Loader.3 \
	Gtk2::Ex::FormFactory::Form.3

.include <bsd.port.mk>
