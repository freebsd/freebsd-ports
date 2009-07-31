# ex:ts=8
# Ports collection makefile for:	p5-Gnome2
# Date created:			Jan 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2
PORTVERSION=	1.042
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Allows a perl developer to use the Gnome libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/Canvas.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/VFS.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-VFS \
		${SITE_PERL}/${PERL_ARCH}/Gnome2/Canvas.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2-Canvas

USE_GNOME=	libgnomeui libgnome libbonoboui
PERL_CONFIGURE=	5.8.0+

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
