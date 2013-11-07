# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Gtk2-Ex-Simple-List
PORTVERSION=	0.50
PORTREVISION=	6
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple interface to complex MVC list widget

BUILD_DEPENDS=	p5-Glib2>=1.00:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
