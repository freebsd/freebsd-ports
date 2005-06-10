# New ports collection makefile for:	FXRuby
# Date created:		24 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/1612/
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	FXRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Ruby extension module to use FOX 1.2, aka FXRuby

LIB_DEPENDS=	FOX-1.4:${PORTSDIR}/x11-toolkits/fox-devel \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		fxscintilla.17:${PORTSDIR}/x11-toolkits/fxscintilla

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
NOHARM_ARGS=	--no-harm

USE_XLIB=	yes
USE_GL=		yes

install-noharm:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${NOHARM_ARGS} ${RUBY_INSTALL_ARGS}

do-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${RUBY_INSTALL_ARGS}

.include <bsd.port.mk>
