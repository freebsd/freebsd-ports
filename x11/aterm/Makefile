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

PLIST_FILES=	bin/aterm \
		man/man1/aterm.1.gz

TRANS_CONFIGURE_ENABLE=	transparency
BSDEL_CONFIGURE_OFF=	--disable-backspace-key --disable-delete-key
BSDEL_CONFIGURE_ON=	--enable-backspace-key --enable-delete-key
MOUSE_CONFIGURE_ENABLE=	mousewheel
BGIMG_LIB_DEPENDS=	libAfterImage.so:${PORTSDIR}/graphics/libafterimage \
			libpng15.so:${PORTSDIR}/graphics/png \
			libjpeg.so:${PORTSDIR}/graphics/jpeg
BGIMG_CONFIGURE_ON=	--with-afterimage-config --with-png --with-jpeg
BGIMG_CONFIGURE_OFF=	--without-afterimage-config --with-png=no --with-jpeg=no
KANJI_CONFIGURE_ENABLE=	kanji
BIG5S_CONFIGURE_ENABLE=	big5
GREEK_CONFIGURE_ENABLE=	greek


.include <bsd.port.options.mk>

.if ${OSVERSION} > 900007
CONFIGURE_ARGS+=	--disable-utmp
.else
CONFIGURE_ARGS+=	--enable-utmp
.endif

.include <bsd.port.mk>
