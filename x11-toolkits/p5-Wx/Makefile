# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx
PORTVERSION=	0.99.16
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Alien-wxWidgets>=0.25:${PORTSDIR}/x11-toolkits/p5-Alien-wxWidgets \
		p5-ExtUtils-XSpp>=0.16.03:${PORTSDIR}/devel/p5-ExtUtils-XSpp
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	UNICODE
OPTIONS_DEFAULT=	UNICODE
UNICODE_DESC=	Build with Unicode support

USE_WX=		2.6+
WX_COMPS=	wx contrib
PERL_CONFIGURE=	yes
CC=		${CXX}
CFLAGS+=	-pthread -Wno-write-strings
MAKE_JOBS_UNSAFE=	yes

MAN1=		wxperl_overload.1
MAN3=		Wx.3 \
		Wx::Api.3 \
		Wx::Loader.3 \
		Wx::NewClass.3 \
		Wx::Perl::Carp.3 \
		Wx::Perl::SplashFast.3 \
		Wx::Perl::TextValidator.3 \
		Wx::Socket.3 \
		Wx::Thread.3 \
		Wx::XSP::Overload.3 \
		Wx::build::MakeMaker.3 \
		Wx::build::MakeMaker::Win32_MSVC.3 \
		Wx::build::Options.3 \
		Wx::build::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501508
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=3.15:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
RUN_DEPENDS+=	p5-ExtUtils-ParseXS>=3.15:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.if ${PORT_OPTIONS:MUNICODE}
WX_UNICODE=	yes
ALIEN_UNICODE=	${LS} ${SITE_PERL}/${PERL_ARCH}/Alien/wxWidgets/Config | ${GREP} "_uni_"

pre-configure:
	@if [ ! "$$(${ALIEN_UNICODE})" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  It seems x11-toolkits/p5-Alien-wxWidgets was compiled without"; \
		${ECHO_MSG} "      Unicode suport. Please rebuild it and try again."; \
		${ECHO_MSG}; \
		exit 1; \
	fi
.endif

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's/^CCFLAGS = .*$$/CCFLAGS = ${CFLAGS}/'

.include <bsd.port.post.mk>
