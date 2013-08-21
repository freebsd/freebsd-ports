# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-CursorControl
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate the mouse cursor programmatically

BUILD_DEPENDS=	p5-Tk>=800.015:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

ALL_TARGETS=	pure_install
USE_PERL5=	configure
USES=		perl5

MAN3=		Tk::CursorControl.3

post-patch:
	@${REINPLACE_CMD} -e \
		'/Tk\/demos\/widtrib\/cursor.pl/ s|cursor.pl|cursorcontrol.pl|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
