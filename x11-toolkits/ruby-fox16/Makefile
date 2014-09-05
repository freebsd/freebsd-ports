# Created by: Luiz Eduardo Roncato Cordeiro <lercordeiro@gmail.com>
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.6.19
PORTREVISION=	14
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FXRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby extension module to use FOX 1.6, aka FXRuby

LIB_DEPENDS=	libFOX-1.6.so:${PORTSDIR}/x11-toolkits/fox16 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfxscintilla.so:${PORTSDIR}/x11-toolkits/fxscintilla

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}16

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
NOHARM_ARGS=	--no-harm
USE_XORG=	xcursor xproto x11 xextproto xext xrandr
USE_GL=		yes

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

install-noharm:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${NOHARM_ARGS} ${RUBY_INSTALL_ARGS}

post-configure:
	@${REINPLACE_CMD} -e 's|CPPFLAGS = -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.6|CPPFLAGS = -ffriend-injection -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.6|' \
	${WRKSRC}/ext/fox16/Makefile

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Does not build with Ruby 2.0 or newer
.endif

.include <bsd.port.post.mk>
