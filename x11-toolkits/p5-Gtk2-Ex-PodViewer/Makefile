# New ports collection makefile for:	p5-Gtk2-Ex-PodViewer
# Date created:				2004-08-20
# Whom:					ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2-Ex-PodViewer
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Displays plain old documentation

BUILD_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Gtk2-Ex-Simple-List>=0.50:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	podviewer.1
MAN3=	${PORTNAME:S/-/::/g}.3 ${PORTNAME:S/-/::/g}::Parser.3

.include <bsd.port.mk>
