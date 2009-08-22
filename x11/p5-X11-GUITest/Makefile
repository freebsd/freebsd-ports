# ex:ts=8
# Ports collection makefile for:	X11-GUITest
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	X11-GUITest
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN/X11 \
		SF/x11guitest/x11guitest/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides GUI testing/interaction facilities

USE_XORG=	x11 xt xext xtst
PERL_CONFIGURE=	5.8.0+
MAN3=	X11::GUITest.3

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${LOCALBASE},g" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
