# Created by: gpalmer@FreeBSD.org
# $FreeBSD$

PORTNAME=	rxvt
PORTVERSION=	2.6.4
PORTREVISION=	6
CATEGORIES+=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low memory usage xterm replacement that supports color

USES=		xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		BIG5 GB GREEK HALF_SHADOW KANJI MENUBAR NEXT \
			TRANSPARENCY XGETDEFAULT XIM XTERM
BIG5_DESC=		Build with BIG5 support
GB_DESC=		Build with GB support
GREEK_DESC=		Build with greek keyboard support
HALF_SHADOW_DESC=	Build with half shadows support
KANJI_DESC=		Build with Kanji support
MENUBAR_DESC=		Build with menubar support
NEXT_DESC=		Build with NeXT scrollbar
TRANSPARENCY_DESC=	Build with transparency support
XGETDEFAULT_DESC=	Build with XGetDefault() support
XIM_DESC=		Build with XIM support
XTERM_DESC=		Build with Xterm scrollbar

CONFIGURE_ARGS=	--enable-ttygid \
		--with-xpm --enable-xpm-background \
		--with-xpm-includes=${LOCALBASE}/include/X11 \
		--with-xpm-library=${LOCALBASE}/lib \
		--disable-utmp --disable-wtmp # fails to build with new utmpx
PLIST_FILES=	bin/rxvt man/man1/${PORTNAME}.1.gz

BIG5_CONFIGURE_ON=	--enable-big5
GB_CONFIGURE_ON=	--enable-gb
GREEK_CONFIGURE_ON=	--enable-greek
# enable half width/height shadows scrollbar
HALF_SHADOW_CONFIGURE_ON=	--enable-half-shadow
KANJI_CONFIGURE_ON=	--enable-kanji
MENUBAR_CONFIGURE_ON=	--enable-menubar
NEXT_CONFIGURE_ON=	--enable-next-scroll
TRANSPARENCY_CONFIGURE_ON=	--enable-transparency
# make resources checking via XGetDefault()
XGETDEFAULT_CONFIGURE_ON=	--enable-xgetdefault
# XIM (X Input Method) protocol support
XIM_CONFIGURE_ON=	--enable-xim
XTERM_CONFIGURE_ON=	--enable-xterm-scroll

post-patch:
	@${REINPLACE_CMD} -e 's|getpt()|posix_openpt(0)|' ${WRKSRC}/configure

post-install:
	@${CHMOD} 4711 ${STAGEDIR}${PREFIX}/bin/rxvt

.include <bsd.port.mk>
