# Created by: Sean Farley <sean-freebsd@farley.org>
# $FreeBSD$

PORTNAME=	X11-IdleTime
PORTVERSION=	0.09
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that reports number of seconds that X11 has been idle

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0.44:devel/p5-Inline \
		p5-Inline-C>=0.44:devel/p5-Inline-C

MAKE_JOBS_UNSAFE=	yes
USES=		perl5 xorg
USE_PERL5=	configure
USE_XORG=	x11 xext xscrnsaver

PORTSCOUT=	skipv:0.5

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/IdleTime.pm ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/X11/IdleTime/IdleTime.so

.include <bsd.port.mk>
