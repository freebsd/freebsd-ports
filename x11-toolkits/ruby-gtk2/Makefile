# New ports collection makefile for:    ruby-gtk
# Version required:     0.23
# Date created:         19 April 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

DISTNAME=	ruby-gtk-0.23
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
WRKSRC=		${WRKDIR}/gtk-0.23
PLIST_SUB+=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

.if defined(NO_IMLIB)
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
.else
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
GTK_CONFIG?=	${X11BASE}/bin/imlib-config
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${GTK_CONFIG}

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb ${PREFIX}/lib/ruby/${RUBY_VER}
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${PREFIX}/share/examples/ruby/gtk
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk/browser
	${INSTALL_DATA} ${WRKSRC}/doc/*.rb ${PREFIX}/share/examples/ruby/gtk/browser
.if !defined(NO_IMLIB)
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk/gdkimlib
	${INSTALL_DATA} ${WRKSRC}/sample/gdkimlib/*.rb ${PREFIX}/share/examples/ruby/gtk/gdkimlib
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/gtk/ja
	${INSTALL_DATA} ${WRKSRC}/doc/api/* ${PREFIX}/share/doc/ruby/gtk
	${INSTALL_DATA} ${WRKSRC}/doc/api-ja/* ${PREFIX}/share/doc/ruby/gtk/ja
.endif

.include <bsd.port.mk>
