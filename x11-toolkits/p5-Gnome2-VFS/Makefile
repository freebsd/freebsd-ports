# ex:ts=8
# Ports collection makefile for:	p5-Gnome2-VFS
# Date created:			Jan 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2-VFS
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	../by-authors/id/R/RM/RMCFARLA/Gtk2-Perl \
		gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to use the GNOME Virtual File System library from Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	gnomevfs2
PERL_CONFIGURE=	yes

MAN3=		Gnome2::VFS.3 \
		Gnome2::VFS::Application.3 \
		Gnome2::VFS::ApplicationRegistry.3 \
		Gnome2::VFS::Async.3 \
		Gnome2::VFS::Async::Handle.3 \
		Gnome2::VFS::Directory.3 \
		Gnome2::VFS::Directory::Handle.3 \
		Gnome2::VFS::FileInfo.3 \
		Gnome2::VFS::Handle.3 \
		Gnome2::VFS::Mime.3 \
		Gnome2::VFS::Mime::Application.3 \
		Gnome2::VFS::Mime::Monitor.3 \
		Gnome2::VFS::Mime::Type.3 \
		Gnome2::VFS::Monitor.3 \
		Gnome2::VFS::Monitor::Handle.3 \
		Gnome2::VFS::URI.3 \
		Gnome2::VFS::Xfer.3 \
		Gnome2::VFS::index.3 \
		Gnome2::VFS::main.3

.include <bsd.port.mk>
