# Created by: gpalmer@FreeBSD.org
# $FreeBSD$

PORTNAME=	rxvt
PORTVERSION=	2.6.4
PORTREVISION=	6
CATEGORIES+=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low memory usage xterm replacement that supports color

USE_XORG=	xpm
GNU_CONFIGURE=	yes

OPTIONS_DEFINE =	BIG5 GB GREEK HALF_SHADOW KANJI MENUBAR NEXT \
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
		--with-xpm-library=${LOCALBASE}/lib
PLIST_FILES=	bin/rxvt man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

# fails to build with new utmpx
.if ${OSVERSION} > 900007
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp
.else
CONFIGURE_ARGS+=	--enable-utmp --enable-wtmp
.endif

.if ${PORT_OPTIONS:MBIG5}
CONFIGURE_ARGS+=	--enable-big5
.endif

.if ${PORT_OPTIONS:MGB}
CONFIGURE_ARGS+=	--enable-gb
.endif

.if ${PORT_OPTIONS:MGREEK}
CONFIGURE_ARGS+=	--enable-greek
.endif

# enable half width/height shadows scrollbar
.if ${PORT_OPTIONS:MHALF_SHADOW}
CONFIGURE_ARGS+=	--enable-half-shadow
.endif

.if ${PORT_OPTIONS:MKANJI}
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if ${PORT_OPTIONS:MMENUBAR}
CONFIGURE_ARGS+=	--enable-menubar
.endif

.if ${PORT_OPTIONS:MNEXT}
CONFIGURE_ARGS+=	--enable-next-scroll
.endif

.if ${PORT_OPTIONS:MTRANSPARENCY}
CONFIGURE_ARGS+=	--enable-transparency
.endif

# make resources checking via XGetDefault()
.if ${PORT_OPTIONS:MXGETDEFAULT}
CONFIGURE_ARGS+=	--enable-xgetdefault
.endif

# XIM (X Input Method) protocol support
.if ${PORT_OPTIONS:MXIM}
CONFIGURE_ARGS+=	--enable-xim
.endif

.if ${PORT_OPTIONS:MXTERM}
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|getpt()|posix_openpt(0)|' ${WRKSRC}/configure

post-install:
	@${CHMOD} 4711 ${STAGEDIR}${PREFIX}/bin/rxvt

.include <bsd.port.post.mk>
