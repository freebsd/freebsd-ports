# ex:ts=8
# Ports collection makefile for:	X11-GUITest
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	X11-GUITest
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	X11/:cpan \
			x11guitest/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan,sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities

USE_XLIB=	yes
PERL_CONFIGURE=	5.8.0+
MAN3=	X11::GUITest.3

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${X11BASE},g" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
