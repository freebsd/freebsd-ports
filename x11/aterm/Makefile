# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aterm
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color vt102 terminal emulator with transparency support

MAKE_JOBS_UNSAFE= yes

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-wtmp \
		--enable-xgetdefault \
		--disable-memset \
		--disable-swapscreen \
		--disable-thai \
		--without-afterstep-config

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	TRANS BSDEL MOUSE BGIMG KANJI BIG5S GREEK
OPTIONS_DEFAULT=	TRANS BSDEL MOUSE
TRANS_DESC=	Transparency support
BSDEL_DESC=	BSD-style backspace and delete
BGIMG_DESC=	XPM, JPEG, PNG backgrounds
KANJI_DESC=	Kanji (EUC-JP or SJIS) support
BIG5S_DESC=	Chinese character (BIG5) support
GREEK_DESC=	Greek keyboard support

MAN1=		aterm.1

PLIST_FILES=       bin/aterm

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${OSVERSION} > 900007
CONFIGURE_ARGS+=	--disable-utmp
.else
CONFIGURE_ARGS+=	--enable-utmp
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRANS}
CONFIGURE_ARGS+=	--enable-transparency
.else
CONFIGURE_ARGS+=	--disable-transparency
.endif

.if ${PORT_OPTIONS:MBSDEL}
CONFIGURE_ARGS+=	--disable-backspace-key --disable-delete-key
.else
CONFIGURE_ARGS+=	--enable-backspace-key --enable-delete-key
.endif

.if ${PORT_OPTIONS:MMOUSE}
CONFIGURE_ARGS+=	--enable-mousewheel
.else
CONFIGURE_ARGS+=	--disable-mousewheel
.endif

.if ${PORT_OPTIONS:MBGIMG}
LIB_DEPENDS+=	AfterImage:${PORTSDIR}/graphics/libafterimage \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-afterimage-config --with-png --with-jpeg
.else
CONFIGURE_ARGS+=	--without-afterimage-config --with-png=no --with-jpeg=no
.endif

.if ${PORT_OPTIONS:MKANJI}
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if ${PORT_OPTIONS:MBIG5S}
CONFIGURE_ARGS+=	--enable-big5
.endif

.if ${PORT_OPTIONS:MGREEK}
CONFIGURE_ARGS+=	--enable-greek
.endif

.include <bsd.port.post.mk>
