# Created by: Sean Farley <sean-freebsd@farley.org>
# $FreeBSD$

PORTNAME=	X11-IdleTime
PORTVERSION=	0.5
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that reports number of seconds that X11 has been idle

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline \
    		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USE_XORG=	x11 xscrnsaver
USES=		perl5
USE_PERL5=	configure patch

MANPREFIX=	${SITE_PERL}
MAN3=		X11::IdleTime.3

post-patch:
.for i in IdleTime.pm
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/${i}
	@${PERL} -pi -e "s,[\d\.]+,${PORTVERSION:C/0./0.0/}, if m{VERSION}" ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
