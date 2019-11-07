# $FreeBSD$

PORTNAME=	X11-Xlib
PORTVERSION=	0.18
PORTREVISION=	2
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Low-level access to the X11 library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny


USES=		perl5 xorg
USE_XORG=	x11 xcomposite xext xfixes xinerama xorgproto xrender xtst

pre-configure:
	cd ${WRKSRC} && ${PERL} Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/X11/Xlib/Xlib.so

.include <bsd.port.mk>
