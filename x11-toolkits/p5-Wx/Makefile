# New ports collection makefile for:	p5-Wx
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Wx
PORTVERSION=	0.97
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit

BUILD_DEPENDS=	p5-Alien-wxWidgets>=0.25:${PORTSDIR}/x11-toolkits/p5-Alien-wxWidgets \
		p5-ExtUtils-ParseXS>=2.22:${PORTSDIR}/devel/p5-ExtUtils-ParseXS \
		p5-ExtUtils-XSpp>=0.06:${PORTSDIR}/devel/p5-ExtUtils-XSpp
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	UNICODE "Build with Unicode support"    on

USE_WX=		2.6+
WX_COMPS=	wx contrib
USE_DISPLAY=	yes
PERL_CONFIGURE=	yes
CC=		${CXX}
CFLAGS+=	-pthread -Wno-write-strings
MAKE_JOBS_UNSAFE=	yes

.if defined(WITH_UNICODE)
WX_UNICODE=	yes
.endif

ALIEN_UNICODE=	${PERL} -MAlien::wxWidgets -e 'print Alien::wxWidgets->key' | ${GREP} "_uni_"

MAN1=		wxperl_overload.1
MAN3=		Wx::Perl::TextValidator.3 \
		Wx::Perl::Carp.3 \
		Wx::Socket.3 \
		Wx::Api.3 \
		Wx::build::Utils.3 \
		Wx::build::Options.3 \
		Wx::Perl::SplashFast.3 \
		Wx::build::MakeMaker::Win32_MSVC.3 \
		Wx::build::MakeMaker.3 \
		Wx::Loader.3 \
		Wx::Thread.3 \
		Wx.3

.if defined(WITH_UNICODE)
pre-configure:
	@if [ ! "$$(${ALIEN_UNICODE})" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  It seems x11-toolkits/p5-Alien-wxWidget was compiled without"; \
		${ECHO_MSG} "      Unicode suport. Please rebuild it and try again."; \
		${ECHO_MSG}; \
		exit 1; \
	fi
.endif

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's/^CCFLAGS = .*$$/CCFLAGS = ${CFLAGS}/'

.include <bsd.port.mk>
