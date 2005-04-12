# New ports collection makefile for:	multi-aterm
# Date created:		2003-07-11
# Whom:			Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	multi-aterm
PORTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/materm/

MAINTAINER=	esn@x123.info
COMMENT=	A multi terminal based on aterm

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=13
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS ChangeLog INSTALL TODO
MAN1=		multi-aterm.1

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--enable-utmp
.endif

.if defined(WITH_WTMP)
CONFIGURE_ARGS+=	--enable-wtmp
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can specify the following options:"
	@${ECHO_MSG} "WITH_UTMP=yes - enable utmp support"
	@${ECHO_MSG} "WITH_WTMP=yes - enable wtmp support"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
