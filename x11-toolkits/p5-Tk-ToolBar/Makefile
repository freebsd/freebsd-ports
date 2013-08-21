# New ports collection makefile for:	p5-Tk-ToolBar
# Date created:		2011-10-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-ToolBar
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolbar widget for Perl/Tk

BUILD_DEPENDS=	p5-Tk-CursorControl>=0:${PORTSDIR}/x11-toolkits/p5-Tk-CursorControl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_ZIP=	yes
USE_PERL5=	configure
USES=		perl5

MAN3=		Tk::ToolBar.3

.include <bsd.port.mk>
