# New ports collection makefile for:	FXRuby
# Date created:		24 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.2.6
PORTREVISION=	7
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FXRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Ruby extension module to use FOX 1.2, aka FXRuby

LIB_DEPENDS=	FOX-1.2:${PORTSDIR}/x11-toolkits/fox12 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		fxscintilla.19:${PORTSDIR}/x11-toolkits/fxscintilla-fox12

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}12

FETCH_CMD=	/usr/bin/fetch -Rr
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
NOHARM_ARGS=	--no-harm
USE_XORG=	xcursor x11
USE_GL=		yes

.include <bsd.port.pre.mk>

install-noharm:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${NOHARM_ARGS} ${RUBY_INSTALL_ARGS}

post-configure:
.if ${OSVERSION} >= 700000
	@${REINPLACE_CMD} -e 's|CPPFLAGS = -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.2|CPPFLAGS = -ffriend-injection -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.2|' \
	${WRKSRC}/ext/fox12/Makefile
.endif

do-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${RUBY_INSTALL_ARGS}

.include <bsd.port.post.mk>
