# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	Gtk2-Ex-Dialogs
PORTVERSION=	0.11
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Useful tools for Gnome2/Gtk2 Perl GUI design

BUILD_DEPENDS=	p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type \
		p5-Gtk2-Ex-Utils>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
