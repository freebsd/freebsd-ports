# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Gtk2-Chmod
PORTVERSION=	0.0.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a dialog for getting values to use with chmod

BUILD_DEPENDS=	p5-File-Stat-Bits>=0:sysutils/p5-File-Stat-Bits \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
