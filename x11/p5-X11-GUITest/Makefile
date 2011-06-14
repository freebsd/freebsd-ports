# Ports collection makefile for:	X11-GUITest
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	X11-GUITest
PORTVERSION=	0.25
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN \
		SF/x11guitest/x11guitest/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities

USE_XORG=	x11 xt xext xtst
PERL_CONFIGURE=	yes

MAN3=		X11::GUITest.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/\([a-z]*\)\(64\)*|${LOCALBASE}/\1|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
