# New ports collection makefile for:   bbconf
# Date created:        29 October 2001
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	bbconf
PORTVERSION=	1.10
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurator for the Blackbox window manager

USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		bbconf.1
PORTDOCS=	AUTHORS ChangeLog README README.html TODO
PLIST_FILES=	bin/bbconf \
		lib/bbconf/plugins/libbbconf.so \
		lib/bbconf/plugins/libkeybindings.so \
		lib/bbconf/plugins/libmenu.so \
		lib/bbconf/plugins/libthemes.so
PLIST_DIRS=	lib/bbconf/plugins lib/bbconf

post-patch:
	@${PERL} -pi -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's|-O2 ||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
