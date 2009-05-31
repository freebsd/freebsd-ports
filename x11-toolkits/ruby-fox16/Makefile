# New ports collection makefile for:	FXRuby
# Date created:    8 October 2008
# Whom:            Luiz Eduardo Roncato Cordeiro <lercordeiro@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.6.16
PORTREVISION=	3
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FXRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	lercordeiro@gmail.com
COMMENT=	Ruby extension module to use FOX 1.6, aka FXRuby

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fxscintilla.19:${PORTSDIR}/x11-toolkits/fxscintilla

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}16

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
NOHARM_ARGS=	--no-harm
USE_XORG=	xcursor xproto x11 xextproto xext xrandr
USE_GL=		yes

.include <bsd.port.pre.mk>

install-noharm:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${NOHARM_ARGS} ${RUBY_INSTALL_ARGS}

post-configure:
.if ${OSVERSION} >= 700000
	@${REINPLACE_CMD} -e 's|CPPFLAGS = -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.6|CPPFLAGS = -ffriend-injection -DHAVE_SYS_TIME_H -DHAVE_SIGNAL_H -I/usr/local/include/fxscintilla -I/usr/local/include/fox-1.6|' \
	${WRKSRC}/ext/fox16/Makefile
.endif

.include <bsd.port.post.mk>
