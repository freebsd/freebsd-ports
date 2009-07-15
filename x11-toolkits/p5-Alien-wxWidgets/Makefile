# New ports collection makefile for:	p5-Alien-wxWidgets
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Alien-wxWidgets
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module for building, finding and using wxWidgets binaries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/CBuilder.pm:${PORTSDIR}/devel/p5-ExtUtils-CBuilder

OPTIONS=	UNICODE "Build with Unicode support"    on

USE_WX=		2.6+
WX_COMPS=	wx contrib
PERL_MODBUILD=	5.6.0+

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
BUILD_DEPENDS+=	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.if defined(WITH_UNICODE)
WX_UNICODE=	yes
WX_UNI=		uni_
CONFIGURE_ARGS+=	--build_wx=0 --unicode=1
.else
CONFIGURE_ARGS+=	--build_wx=0 --unicode=0
.endif

WX_UVER=	${WX_CONFIG:T} --version | ${TR} '.' '_'
PLIST_SUB+=	WX_UVER="$$(${WX_UVER})" WX_UNI=${WX_UNI}

MAN3=		Alien::wxWidgets.3 \
		Alien::wxWidgets::Utility.3

post-patch:
	@${REINPLACE_CMD} -e 's/wx-config/${WX_CONFIG:T}/' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e "s/\'wx-config/\'${WX_CONFIG:T}/" -e "s/lc_r/lpthread/" \
		${WRKSRC}/inc/My/Build/Any_wx_config.pm

.include <bsd.port.post.mk>
