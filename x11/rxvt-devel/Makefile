# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11-clocks/rclock
# when you upgrade rxvt. These ports all use the same distfile.

PORTNAME=	rxvt
PORTVERSION=	2.7.10
PORTREVISION=	5
CATEGORIES+=	x11
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel

MAINTAINER=	akosela@andykosela.com
COMMENT=	A low memory usage xterm replacement that supports color

USE_AUTOTOOLS=	libtool:15
USE_PERL5_BUILD=yes
USE_XORG=	xpm
GNU_CONFIGURE=	yes

OPTIONS=	256_COLOR	"Build with 256-color support" off \
		BIG5		"Build with BIG5 support" off \
		EUCJ		"Build with EUC Japanese support" off \
		GB		"Build with GB support" off \
		GREEK		"Build with greek keyboard support" off \
		KR		"Build with EUC Korean support" off \
		LINESPACE	"Build with linespace support" off \
		MENUBAR		"Build with menubar support" off \
		NEXT		"Build with NeXT scrollbar" off \
		RXVT		"Build with rxvt scrollbar" off \
		SJIS		"Build with Shift JIS support" off \
		SMART		"Build with smart resize support" off \
		TRANSPARENCY	"Build with transparency support" off \
		XGETDEFAULT	"Build with XGetDefault() support" off \
		XIM		"Build with XIM support" off \
		XTERM		"Build with Xterm scrollbar" off

CONFIGURE_ARGS=	--enable-utmp --enable-wtmp --enable-languages \
		--with-xpm --enable-xpm-background --enable-shared \
		--enable-mousewheel --disable-languages
USE_LDCONFIG=	yes

MAN1=		rxvt.1

.include <bsd.port.pre.mk>

# enable 256 color
.if defined(WITH_256_COLOR)
CONFIGURE_ARGS+=	--enable-256-color
.endif

# enable big5 support
.if defined(WITH_BIG5)
CONFIGURE_ARGS+=	--with-encoding=big5 --enable-languages
.endif

# enable euc japanese support
.if defined(WITH_EUCJ)
CONFIGURE_ARGS+=	--with-encoding=eucj --enable-languages
.endif

# enable gb support
.if defined(WITH_GB)
CONFIGURE_ARGS+=	--with-encoding=gb --enable-languages
.endif

# enable greek keyboard support
.if defined(WITH_GREEK)
CONFIGURE_ARGS+=	--enable-greek
.endif

# enable euc korean support
.if defined(WITH_KR)
CONFIGURE_ARGS+=	--with-encoding=kr --enable-languages
.endif

# enable line-spacing
.if defined(WITH_LINESPACE)
CONFIGURE_ARGS+=	--enable-linespace
.endif

# enable menubar
.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif

# enable NeXT style scrollbar
.if defined(WITH_NEXT)
CONFIGURE_ARGS+=	--enable-next-scroll
.endif

# enable rxvt style scrollbar
.if defined(WITH_RXVT)
CONFIGURE_ARGS+=	--enable-rxvt-scroll
.endif

# enable shift jis support
.if defined(WITH_SJIS)
CONFIGURE_ARGS+=	--with-encoding=sjis --enable-languages
.endif

# enable smart resize
.if defined(WITH_SMART)
CONFIGURE_ARGS+=	--enable-smart-resize
.endif

# enable transparency support
.if defined(WITH_TRANSPARENCY)
CONFIGURE_ARGS+=	--enable-transparency
.endif

# make resources checking via XGetDefault()
.if defined(WITH_XGETDEFAULT)
CONFIGURE_ARGS+=	--enable-xgetdefault
.endif

# XIM (X Input Method) protocol support
.if defined(WITH_XIM)
CONFIGURE_ARGS+=	--enable-xim
.endif

# enable Xterm style scrollbar
.if defined(WITH_XTERM)
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif

CONFIGURE_ENV+=		LIBS="-lutil"

post-patch:
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.c
	@${REINPLACE_CMD} -e 's|--mode=compile|& --tag=CC|' \
		-e 's|--mode=link|& --tag=CC|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.post.mk>
