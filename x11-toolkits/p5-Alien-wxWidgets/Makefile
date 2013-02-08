# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Alien-wxWidgets
PORTVERSION=	0.62
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Perl5 module for building, finding and using wxWidgets binaries

OPTIONS_DEFINE=	UNICODE
OPTIONS_DEFAULT=	UNICODE
UNICODE_DESC=	Build with Unicode support

USE_GCC=	any
USE_WX=		2.6+
WX_COMPS=	wx contrib
PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
BUILD_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
.elsif ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.if ${PORT_OPTIONS:MUNICODE}
WX_UNICODE=	yes
WX_UNI=		uni_
CONFIGURE_ARGS+=	--wxWidgets-build=0 --wxWidgets-unicode=1
.else
CONFIGURE_ARGS+=	--wxWidgets-build=0 --wxWidgets-unicode=0
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
