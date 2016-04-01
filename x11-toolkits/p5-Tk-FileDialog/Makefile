# Created by: minter@lunenburg.org
# $FreeBSD$

PORTNAME=	Tk-FileDialog
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tk::FileDialog - A file selector dialog for perl/Tk

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_SUB=	PERL_VERSION=${PERL_VERSION}

.include <bsd.port.mk>
