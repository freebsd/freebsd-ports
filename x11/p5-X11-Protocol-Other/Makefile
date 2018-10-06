# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	X11-Protocol-Other
PORTVERSION=	30
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for window manager related functions for use by client programs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-X11-Protocol>=0:x11/p5-X11-Protocol

USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

SHEBANG_FILES=	examples/*.pl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
