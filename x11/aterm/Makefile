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

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A color vt102 terminal emulator with transparency support

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
# `+=' is for slave ports
CONFIGURE_ARGS+=	\
			--enable-transparency --enable-background-image \
			--enable-fading --enable-utmp --enable-wtmp

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--with-png=no
.endif

.if !defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--with-jpeg
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--with-jpeg=no
.endif

.if !defined(WITH_BSDEL)
CONFIGURE_ARGS+=	--disable-backspace-key --disable-delete-key
.endif

.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif

.if defined(WITH_NEXTSCROLL)
CONFIGURE_ARGS+=	--enable-next-scroll
.endif

MAN1=		aterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

.include <bsd.port.mk>
