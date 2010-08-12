# New ports collection makefile for:   aterm
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aterm
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A color vt102 terminal emulator with transparency support

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-wtmp \
		--enable-xgetdefault \
		--disable-memset \
		--disable-swapscreen \
		--disable-thai \
		--without-afterstep-config

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TRANS "Transparency support" on \
		BSDEL "BSD-style backspace and delete" on \
		MOUSE "Mousewheel support" on \
		BGIMG "XPM, JPEG, PNG backgrounds" off \
		KANJI "Kanji (EUC-JP or SJIS) support" off \
		BIG5S "Chinese character support (BIG5)" off \
		GREEK "Greek keyboard support" off

MAN1=		aterm.1

PLIST_FILES=       bin/aterm

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 900007
CONFIGURE_ARGS+=	--disable-utmp
.else
CONFIGURE_ARGS+=	--enable-utmp
.endif

.if !defined(WITHOUT_TRANS)
CONFIGURE_ARGS+=	--enable-transparency
.else
CONFIGURE_ARGS+=	--disable-transparency
.endif

.if !defined(WITHOUT_BSDEL)
CONFIGURE_ARGS+=	--disable-backspace-key --disable-delete-key
.else
CONFIGURE_ARGS+=	--enable-backspace-key --enable-delete-key
.endif

.if !defined(WITHOUT_MOUSE)
CONFIGURE_ARGS+=	--enable-mousewheel
.else
CONFIGURE_ARGS+=	--disable-mousewheel
.endif

.if defined(WITH_BGIMG)
LIB_DEPENDS+=	AfterImage.0:${PORTSDIR}/graphics/libafterimage \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-afterimage-config --with-png --with-jpeg
.else
CONFIGURE_ARGS+=	--without-afterimage-config --with-png=no --with-jpeg=no
.endif

.if defined(WITH_KANJI)
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if defined(WITH_BIG5S)
CONFIGURE_ARGS+=	--enable-big5
.endif

.if defined(WITH_GREEK)
CONFIGURE_ARGS+=	--enable-greek
.endif

.include <bsd.port.post.mk>
