# New ports collection makefile for:   aterm
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aterm
PORTVERSION=	0.4.2
CATEGORIES+=	x11	# `+=' is for slave ports
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
# `+=' is for slave ports
CONFIGURE_ARGS+= \
		--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key \
		--enable-fading --enable-utmp --enable-wtmp

.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+= --enable-menubar
.endif

.if defined(WITH_NEXTSCROLL)
CONFIGURE_ARGS+= --enable-next-scroll
.endif

MAN1=		aterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

.include <bsd.port.mk>
