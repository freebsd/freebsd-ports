# ex:ts=8
# Ports collection makefile for:	X11-GUITest
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	X11-GUITest
PORTVERSION=	0.20
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	X11/:cpan \
			x11guitest/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities

USE_REINPLACE=	yes
USE_XLIB=	yes
PERL_CONFIGURE=	yes
MAN3=	X11::GUITest.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${X11BASE},g" ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
