# New ports collection makefile for:	p5-X11-IdleTime
# Date created:		9 July 2003
# Whom:			Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	X11-IdleTime
PORTVERSION=	0.01
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	X11
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that reports number of seconds that X11 has been idle

BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_XLIB=	yes
USE_REINPLACE=	yes
PERL_CONFIGURE=	yes

MANPREFIX=	${SITE_PERL}
MAN3=		X11::IdleTime.3

post-patch:
.for i in IdleTime.pm
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/${i}
.endfor

.include <bsd.port.pre.mk>

##
## this port requires PERL 5.8.x or later
##
.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
