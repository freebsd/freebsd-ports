# Created by: Chris Hutchinson <portmaster@BSDforge.com>
# $FreeBSD$

PORTNAME=	xvt
PORTVERSION=	3.0.0
CATEGORIES+=	x11
MASTER_SITES=	http://BSDforge.com/projects/source/x11/xvt/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Xterm replacement supporting color, transparency, and more, with less

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		libtool perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build patch
USE_XORG=	xpm
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES=	"xvt" "xvt terminal emulator" \
			"${PREFIX}/share/pixmaps/xvt.png" \
			"xvt" "GNOME;X-XFCE;X-Xfce-Toplevel;System;Utility;TerminalEmulator;" \
			false

OPTIONS_DEFINE=	256_COLOR BIG5 EUCJ GB GREEK KR LINESPACE MENUBAR NEXT XVT \
		SJIS SMART TRANSPARENCY XIM XTERM

256_COLOR_DESC=		Build with 256-color support
BIG5_DESC=		Build with BIG5 support
EUCJ_DESC=		Build with EUC Japanese support
GB_DESC=		Build with GB support
GREEK_DESC=		Build with greek keyboard support
KR_DESC=		Build with EUC Korean support
LINESPACE_DESC=		Build with linespace support
MENUBAR_DESC=		Build with menubar support
NEXT_DESC=		Build with NeXT scrollbar
XVT_DESC=		Build with xvt scrollbar
SJIS_DESC=		Build with Shift JIS support
SMART_DESC=		Build with smart resize support
TRANSPARENCY_DESC=	Build with transparency support
XIM_DESC=		Build with XIM support
XTERM_DESC=		Build with Xterm scrollbar

OPTIONS_DEFAULT=256_COLOR GB LINESPACE MENUBAR NEXT XVT SMART TRANSPARENCY \
		XIM XTERM

CONFIGURE_ARGS=	--enable-utmp --enable-lastlog \
		--with-xpm --enable-xpm-background --enable-shared \
		--enable-mousewheel --disable-languages
LIBS+=		-lutil

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-wtmp
EXTRA_PATCHES+=	${FILESDIR}/extra-utmpx_patch-src__logging.c
.else
CONFIGURE_ARGS+=	--enable-wtmp
EXTRA_PATCHES+=	${FILESDIR}/extra-utmp_patch-src__logging.c
.endif

# enable 256 color
.if ${PORT_OPTIONS:M256_COLOR}
CONFIGURE_ARGS+=	--enable-256-color
.endif

# enable big5 support
.if ${PORT_OPTIONS:MBIG5}
CONFIGURE_ARGS+=	--with-encoding=big5 --enable-languages
.endif

# enable euc japanese support
.if ${PORT_OPTIONS:MEUCJ}
CONFIGURE_ARGS+=	--with-encoding=eucj --enable-languages
.endif

# enable gb support
.if ${PORT_OPTIONS:MGB}
CONFIGURE_ARGS+=	--with-encoding=gb --enable-languages
.endif

# enable greek keyboard support
.if ${PORT_OPTIONS:MGREEK}
CONFIGURE_ARGS+=	--enable-greek
.endif

# enable euc korean support
.if ${PORT_OPTIONS:MKR}
CONFIGURE_ARGS+=	--with-encoding=kr --enable-languages
.endif

# enable line-spacing
.if ${PORT_OPTIONS:MLINESPACE}
CONFIGURE_ARGS+=	--enable-linespace
.endif

# enable menubar
.if ${PORT_OPTIONS:MMENUBAR}
CONFIGURE_ARGS+=	--enable-menubar
.endif

# enable NeXT style scrollbar
.if ${PORT_OPTIONS:MNEXT}
CONFIGURE_ARGS+=	--enable-next-scroll
.endif

# enable xvt style scrollbar
.if ${PORT_OPTIONS:MXVT}
CONFIGURE_ARGS+=	--enable-xvt-scroll
.endif

# enable shift jis support
.if ${PORT_OPTIONS:MSJIS}
CONFIGURE_ARGS+=	--with-encoding=sjis --enable-languages
.endif

# enable smart resize
.if ${PORT_OPTIONS:MSMART}
CONFIGURE_ARGS+=	--enable-smart-resize
.endif

# enable transparency support
.if ${PORT_OPTIONS:MTRANSPARENCY}
CONFIGURE_ARGS+=	--enable-transparency
.endif

# XIM (X Input Method) protocol support
.if ${PORT_OPTIONS:MXIM}
CONFIGURE_ARGS+=	--enable-xim
.endif

# enable Xterm style scrollbar
.if ${PORT_OPTIONS:MXTERM}
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif

post-patch:
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xvt; \
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxvt.so.1.0.0 ;\
	${CP} ${WRKSRC}/W11/wrap/xvt.png ${STAGEDIR}${PREFIX}/share/pixmaps/xvt.png

.include <bsd.port.post.mk>
