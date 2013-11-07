# Created by: ijliao
# $FreeBSD$

PORTNAME=	X11-GUITest
PORTVERSION=	0.25
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN \
		SF/x11guitest/x11guitest/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities

USE_XORG=	x11 xt xext xtst
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/\([a-z]*\)\(64\)*|${LOCALBASE}/\1|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
