# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	Gtk2-Ex-PodViewer
PORTVERSION=	0.18
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Displays plain old documentation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Gtk2-Ex-Simple-List>=0.50:x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Pod-Simple>=0:textproc/p5-Pod-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 503100
BUILD_DEPENDS+=	p5-Pod-Parser>=0:textproc/p5-Pod-Parser
.endif

.include <bsd.port.post.mk>
