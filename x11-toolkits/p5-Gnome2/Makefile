# ex:ts=8
# Ports collection makefile for:	p5-Gnome2
# Date created:			Jan 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2
PORTVERSION=	0.90
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl \
		gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS

USE_GNOME=	libgnomeui libgnome libbonoboui
PERL_CONFIGURE=	yes

MAN3=	Gnome2.3 \
	Gnome2::About.3 \
	Gnome2::App.3 \
	Gnome2::AppBar.3 \
	Gnome2::AppHelper.3 \
	Gnome2::AuthenticationManager.3 \
	Gnome2::Bonobo.3 \
	Gnome2::Bonobo::Dock.3 \
	Gnome2::Bonobo::DockItem.3 \
	Gnome2::Client.3 \
	Gnome2::ColorPicker.3 \
	Gnome2::Config.3 \
	Gnome2::Config::Iterator.3 \
	Gnome2::DateEdit.3 \
	Gnome2::Druid.3 \
	Gnome2::DruidPage.3 \
	Gnome2::DruidPageEdge.3 \
	Gnome2::DruidPageStandard.3 \
	Gnome2::Entry.3 \
	Gnome2::FileEntry.3 \
	Gnome2::FontPicker.3 \
	Gnome2::HRef.3 \
	Gnome2::Help.3 \
	Gnome2::I18N.3 \
	Gnome2::IconEntry.3 \
	Gnome2::IconList.3 \
	Gnome2::IconSelection.3 \
	Gnome2::IconTextItem.3 \
	Gnome2::IconTheme.3 \
	Gnome2::ModuleInfo.3 \
	Gnome2::PasswordDialog.3 \
	Gnome2::PixmapEntry.3 \
	Gnome2::PopupMenu.3 \
	Gnome2::Program.3 \
	Gnome2::Score.3 \
	Gnome2::Scores.3 \
	Gnome2::Sound.3 \
	Gnome2::Thumbnail.3 \
	Gnome2::ThumbnailFactory.3 \
	Gnome2::UIDefs.3 \
	Gnome2::URL.3 \
	Gnome2::Util.3 \
	Gnome2::Window.3 \
	Gnome2::WindowIcon.3 \
	Gnome2::index.3 \
	Gnome2::main.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
