# New ports collection makefile for:    ruby-gtk
# Version required:     0.20
# Date created:         19 April 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $Id$
#

DISTNAME=	ruby-gtk-0.20
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/ \
		ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/contrib/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/contrib/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/contrib/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/contrib/

MAINTAINER=	yasuf@big.or.jp

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/gtk
PLIST_SUB+=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${PREFIX}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${GTK_CONFIG}

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${PREFIX}/share/examples/ruby/gtk
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk/browser
	${INSTALL_DATA} ${WRKSRC}/doc/*.rb ${PREFIX}/share/examples/ruby/gtk/browser

.include <bsd.port.mk>
