PORTNAME=	X11-GUITest
DISTVERSION=	0.29
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CTRONDLP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities
WWW=		https://metacpan.org/release/X11-GUITest

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		localbase perl5 xorg
USE_PERL5=	configure
USE_XORG=	x11 xt xext xtst

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/\([a-z]*\)\(64\)*|${LOCALBASE}/\1|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
