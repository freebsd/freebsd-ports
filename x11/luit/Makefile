# New ports collection makefile for:	luit
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	luit
PORTVERSION=	1.1.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Locale and ISO 2022 support for Unicode terminals

XORG_CAT=	app
USE_XORG=	x11 fontenc

CFLAGS+=	-DBSD
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/lib

PLIST_FILES=	bin/luit

MAN1=		luit.1

.if !defined(WITH_SETUID_LUIT)
pre-everything::
	@${ECHO_MSG} "If you want to use xterm with locales in a secure manner, luit must be"
	@${ECHO_MSG} "installed setuid.  If you want to do this, define WITH_SETUID_LUIT when"
	@${ECHO_MSG} "installing this port (either in /etc/make.conf or on command line with"
	@${ECHO_MSG} "install target)."
.endif

post-install:
.if defined(WITH_SETUID_LUIT)
	${CHOWN} root:wheel ${PREFIX}/bin/luit
	${CHMOD} 04711 ${PREFIX}/bin/luit
.endif

.include <bsd.port.mk>
