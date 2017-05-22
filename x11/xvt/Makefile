# Created by: Chris Hutchinson <portmaster@BSDforge.com>
# $FreeBSD$

PORTNAME=	xvt
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	http://BSDforge.com/projects/source/x11/xvt/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Xterm replacement, supporting color, transparency, and more, with less

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

PORTDOCS=	xvt.1.html xvtRef.html xvtRef.txt

USES=		libtool perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build patch
USE_XORG=	x11 xpm
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES=	"xvt" "xvt terminal emulator" \
			"${PREFIX}/share/pixmaps/xvt.png" \
			"xvt" "GNOME;X-XFCE;X-Xfce-Toplevel;System;Utility;TerminalEmulator;" \
			false

OPTIONS_DEFINE=	256_COLOR BIG5 EUCJ GB GREEK KR LINESPACE MENUBAR NEXT XVT \
		SJIS SMART TRANSPARENCY XIM XTERM DOCS XGETDEFAULT

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
XGETDEFAULT_DESC=	Build with resources checking via XGetDefault

OPTIONS_DEFAULT=256_COLOR GB LINESPACE MENUBAR NEXT XVT SMART TRANSPARENCY \
		XIM XTERM DOCS

CONFIGURE_ARGS=	--enable-utmp --enable-lastlog \
		--with-xpm --enable-xpm-background --enable-shared \
		--enable-mousewheel --disable-languages \
		--disable-wtmp
LIBS+=		-lutil

# enable 256 color
256_COLOR_CONFIGURE_ON=	--enable-256-color
# enable big5 support
BIG5_CONFIGURE_ON=	--with-encoding=big5 --enable-languages
# enable euc japanese support
EUCJ_CONFIGURE_ON=	--with-encoding=eucj --enable-languages
# enable gb support
GB_CONFIGURE_ON=	--with-encoding=gb --enable-languages
# enable greek keyboard support
GREEK_CONFIGURE_ON=	--enable-greek
# enable euc korean support
KR_CONFIGURE_ON=	--with-encoding=kr --enable-languages
# enable line-spacing
LINESPACE_CONFIGURE_ON=	--enable-linespace
# enable menubar
MENUBAR_CONFIGURE_ON=	--enable-menubar
# enable NeXT style scrollbar
NEXT_CONFIGURE_ON=	--enable-next-scroll
# enable xvt style scrollbar
XVT_CONFIGURE_ON=	--enable-xvt-scroll
# enable shift jis support
SJIS_CONFIGURE_ON=	--with-encoding=sjis --enable-languages
# enable smart resize
SMART_CONFIGURE_ON=	--enable-smart-resize
# enable transparency support
TRANSPARENCY_CONFIGURE_ON=	--enable-transparency
# XIM (X Input Method) protocol support
XIM_CONFIGURE_ON=	--enable-xim
# enable Xterm style scrollbar
XTERM_CONFIGURE_ON=	--enable-xterm-scroll
# make resources checking via XGetDefault
XGETDEFAULT_CONFIGURE_ON=	--enable-xgetdefault

post-patch:
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.c

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xvt; \
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxvt.so.1.0.0 ;\
	${INSTALL_DATA} ${WRKSRC}/W11/wrap/xvt.png ${STAGEDIR}${PREFIX}/share/pixmaps/xvt.png

.include <bsd.port.mk>
