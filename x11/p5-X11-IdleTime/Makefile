# New ports collection makefile for:	p5-X11-IdleTime
# Date created:		9 July 2003
# Whom:			Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	X11-IdleTime
PORTVERSION=	0.5
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that reports number of seconds that X11 has been idle

BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
    		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_XLIB=	yes
PERL_CONFIGURE=	5.8.0+

MANPREFIX=	${SITE_PERL}
MAN3=		X11::IdleTime.3

post-patch:
.for i in IdleTime.pm
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/${i}
	@${PERL} -pi -e "s,[\d\.]+,${PORTVERSION:C/0./0.0/}, if m{VERSION}" ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
