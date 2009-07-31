# New ports collection makefile for:   bbconf
# Date created:        29 October 2001
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	bbconf
PORTVERSION=	1.10
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurator for the Blackbox window manager

USE_XORG=	x11
USE_QT_VER=	3
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes

MAN1=		bbconf.1
PORTDOCS=	AUTHORS ChangeLog README README.html TODO
PLIST_FILES=	bin/bbconf \
		lib/bbconf/plugins/libbbconf.la \
		lib/bbconf/plugins/libbbconf.so \
		lib/bbconf/plugins/libkeybindings.la \
		lib/bbconf/plugins/libkeybindings.so \
		lib/bbconf/plugins/libmenu.la \
		lib/bbconf/plugins/libmenu.so \
		lib/bbconf/plugins/libthemes.la \
		lib/bbconf/plugins/libthemes.so
PLIST_DIRS=	lib/bbconf/plugins lib/bbconf

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2 ||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g; s|echo aout|echo elf|' \
		${WRKSRC}/configure
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
	@${REINPLACE_CMD} -e '/^CXXFLAGS =/s/$$/ -fPIC/' \
	    ${WRKSRC}/bbconf/plugins/*/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
