# Created by: vanilla
# $FreeBSD$

PORTNAME=	Tk-Getopt
PORTVERSION=	0.51
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	User configuration window for Tk with interface to Getopt::Long

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tk>=804:x11-toolkits/p5-Tk \
		p5-Tk-FontDialog>=0:x11-toolkits/p5-Tk-FontDialog
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
