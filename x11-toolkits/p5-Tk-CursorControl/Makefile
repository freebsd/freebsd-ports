# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-CursorControl
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate the mouse cursor programmatically

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tk>=800.015:x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

ALL_TARGETS=	pure_install
NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e \
		'/Tk\/demos\/widtrib\/cursor.pl/ s|cursor.pl|cursorcontrol.pl|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
