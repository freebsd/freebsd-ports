# New ports collection makefile for:	gdkxft
# Date created:				3 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdkxft
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://philrsss.anu.edu.au/~josh/gdkxft/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --disable-static
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS=-lgnuregex
PKGMESSAGE=	${WRKDIR}/.message

.include <bsd.port.pre.mk>

.if $(XFREE86_VERSION) < 4
IGNORE=		"requires XFree86-4.x or later to run"
.endif

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@/usr/bin/printf "\nRefer to ${DOCSDIR}/README for details on how to enable gdkxft.\n\n" > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
