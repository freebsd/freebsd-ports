# New ports collection makefile for:   aterm
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aterm
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES+=	x11	# `+=' is for slave ports
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A color vt102 terminal emulator with transparency support

USE_XORG=	xpm
GNU_CONFIGURE=	yes
# `+=' is for slave ports
CONFIGURE_ARGS+=	--enable-transparency \
			--enable-fading --enable-utmp --enable-wtmp \
			--without-afterstep-config

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_BACKGROUND_IMAGE)
LIB_DEPENDS+=	AfterImage.0:${PORTSDIR}/graphics/libafterimage
CONFIGURE_ARGS+=	--enable-background-image
.endif

.if !defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--with-png
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--with-png=no
.endif

.if !defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--with-jpeg
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
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

.if defined(WITH_KANJI)
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if defined(WITH_BIG5)
CONFIGURE_ARGS+=	--enable-big5
.endif

.if defined(WITH_GREEK)
CONFIGURE_ARGS+=	--enable-greek
.endif

MAN1=		aterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/aterm

.include <bsd.port.mk>
