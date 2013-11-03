# Created by: chinsan
# $FreeBSD$

PORTNAME=	Gtk2-ImageView
PORTVERSION=	0.05
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RATCLIFFE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings to the GtkImageView image viewer widget

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0.2:${PORTSDIR}/devel/p5-ExtUtils-Depends	\
		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.140:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	gtkimageview:${PORTSDIR}/x11-toolkits/gtkimageview
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
