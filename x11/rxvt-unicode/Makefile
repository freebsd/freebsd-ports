# Created by: gpalmer@FreeBSD.org
# $FreeBSD$

PORTNAME=	rxvt-unicode
PORTVERSION=	9.16
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Attic

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A clone of the terminal emulator rxvt modified to support Unicode

LICENSE=	GPLv2

BUILD_DEPENDS=	tic:${PORTSDIR}/devel/ncurses	\
		${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/bin/fc-cache:${PORTSDIR}/x11-fonts/fontconfig	\
		${LOCALBASE}/share/misc/terminfo.db:${PORTSDIR}/devel/ncurses

USE_GNOME=		pkgconfig
USE_XORG=		xpm xft xrender
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV=		LIBS="-lstdc++ -lutil"
CONFIGURE_ARGS=		--enable-everything --with-term=rxvt	\
			--with-terminfo=${LOCALBASE}/share/misc/terminfo.db
USE_BZIP2=		yes
WANT_PERL=		yes

OPTIONS_DEFINE=	PERL XIM UNICODE3 ISO14755 COMBINING RXVT_SCROLLBAR	\
		NEXT_SCROLLBAR XTERM_SCROLLBAR BACKSPACE_KEY DELETE_KEY	\
		MOUSEWHEEL SMART_RESIZE IMLOCALE_FIX GDK_PIXBUF		\
		NOTIFY 256_COLOR

PERL_DESC=		Embedded Perl interpreter
XIM_DESC=		Support for XIM (X Input Method) protocol
UNICODE3_DESC=		Support Unicode codepoints above 65535
ISO14755_DESC=		Support for extended ISO 14755 modes
COMBINING_DESC=		Automatic composition of combining chars
RXVT_SCROLLBAR_DESC=	Support for the original rxvt scrollbar
NEXT_SCROLLBAR_DESC=	Support for a NeXT-like scrollbar
XTERM_SCROLLBAR_DESC=	Support for an Xterm-like scrollbar
BACKSPACE_KEY_DESC=	Handling of the backspace key by rxvt
DELETE_KEY_DESC=	Handling of the delete key by rxvt
MOUSEWHEEL_DESC=	Support for scrolling via mouse wheel
SMART_RESIZE_DESC=	Smart growth/shrink behaviour
IMLOCALE_FIX_DESC=	imlocale encoding conversion fix
GDK_PIXBUF_DESC=	Use gdk-pixbuf for background images
NOTIFY_DESC=		Freedesktop startup notification support
256_COLOR_DESC=		Support for 256 colors

OPTIONS_DEFAULT=PERL XIM UNICODE3 ISO14755 COMBINING RXVT_SCROLLBAR	\
		NEXT_SCROLLBAR XTERM_SCROLLBAR BACKSPACE_KEY DELETE_KEY	\
		MOUSEWHEEL SMART_RESIZE IMLOCALE_FIX GDK_PIXBUF

MAN1=		urxvt.1 urxvtc.1 urxvtcd.1 urxvtd.1
MAN7=		urxvt.7

PORTDOCS1=	Changes README.FAQ README.configure
PORTDOCS=	README.xvt ${PORTDOCS1}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMLOCALE_FIX}
PATCH_DEPENDS+=	p5-Encode-HanExtra>=0:${PORTSDIR}/chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>=0:${PORTSDIR}/converters/p5-Encode-JIS2K
.endif

# disable the embedded perl interpreter
.if !${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--disable-perl
USE_PERL5_BUILD=	yes
PLIST_SUB=		PERL="@comment "
.else
USE_PERL5=		yes
MAN1+=			urxvt-background.1 urxvt-bell-command.1 urxvt-block-graphics-to-ascii.1 \
			urxvt-clipboard-osc.1 urxvt-confirm-paste.1 urxvt-digital-clock.1	\
			urxvt-example-refresh-hooks.1 urxvt-extensions.1 urxvt-keysym-list.1	\
			urxvt-kuake.1 urxvt-macosx-clipboard-native.1 urxvt-macosx-clipboard.1	\
			urxvt-matcher.1 urxvt-option-popup.1 urxvt-overlay-osc.1		\
			urxvt-readline.1 urxvt-remote-clipboard.1 urxvt-searchable-scrollback.1	\
			urxvt-selection-autotransform.1 urxvt-selection-pastebin.1		\
			urxvt-selection-popup.1 urxvt-selection.1 urxvt-tabbed.1		\
			urxvt-xim-onthespot.1
MAN3=			urxvtperl.3
PLIST_SUB=		PERL=""
.endif

# disable XIM (X Input Method) protocol support
.if !${PORT_OPTIONS:MXIM}
CONFIGURE_ARGS+=	--disable-xim
.endif

# disable support for Unicode codepoints above 65535
.if !${PORT_OPTIONS:MUNICODE3}
CONFIGURE_ARGS+=	--disable-unicode3
.endif

# disable support for extended ISO 14755 modes
.if !${PORT_OPTIONS:MISO14755}
CONFIGURE_ARGS+=	--disable-iso14755
.endif

# disable automatic composition of combining characters
# into composite characters
.if !${PORT_OPTIONS:MCOMBINING}
CONFIGURE_ARGS+=	--disable-combining
.endif

# disable support for the original rxvt scrollbar
.if !${PORT_OPTIONS:MRXVT_SCROLLBAR}
CONFIGURE_ARGS+=	--disable-rxvt-scroll
.endif

# disable support for a NeXT-like scrollbar
.if !${PORT_OPTIONS:MNEXT_SCROLLBAR}
CONFIGURE_ARGS+=	--disable-next-scroll
.endif

# disable support for an Xterm-like scrollbar
.if !${PORT_OPTIONS:MXTERM_SCROLLBAR}
CONFIGURE_ARGS+=	--disable-xterm-scroll
.endif

# disable any handling of the backspace key by rxvt
# let the X server do it
.if !${PORT_OPTIONS:MBACKSPACE_KEY}
CONFIGURE_ARGS+=	--disable-backspace-key
.endif

# disable any handling of the delete key by rxvt
.if !${PORT_OPTIONS:MDELETE_KEY}
CONFIGURE_ARGS+=	--disable-delete-key
.endif

# enable scrolling via mouse wheel or buttons 4 & 5
.if !${PORT_OPTIONS:MMOUSEWHEEL}
CONFIGURE_ARGS+=	--disable-mousewheel
.endif

# enable smart resize
.if !${PORT_OPTIONS:MSMART_RESIZE}
CONFIGURE_ARGS+=	--disable-smart-resize
.else
CONFIGURE_ARGS+=	--enable-smart-resize
.endif

# enable integration with gdk-pixbuf
.if !${PORT_OPTIONS:MGDK_PIXBUF}
CONFIGURE_ARGS+=	--disable-pixbuf
.else
USE_GNOME+=		gdkpixbuf2
CONFIGURE_ARGS+=	--enable-pixbuf
.endif

# enable startup notification
.if !${PORT_OPTIONS:MNOTIFY}
CONFIGURE_ARGS+=	--disable-startup-notification
.else
CONFIGURE_ARGS+=	--enable-startup-notification
LIB_DEPENDS+=		startup-notification-1:${PORTSDIR}/x11/startup-notification
.endif

# enable support for 256 colors
.if ${PORT_OPTIONS:M256_COLOR}
CONFIGURE_ARGS+=	--enable-256-color
.endif

# compile in support for additional codeset groups
.if ${PORT_OPTIONS:MENCODING}
AVAIL_ENC=	jp jp_ext kr zh zh_ext all
. for ENC in ${AVAIL_ENC}
.  if (${WITH_ENCODING} == ${ENC})
_ENC=		${ENC}
.  endif
. endfor
. if !defined(_ENC)
.  error	Invalid encoding for WITH_ENCODING
. endif
.else
. if defined(PACKAGE_BUILDING)
WITH_ENCODING=	all
. endif
.endif
.if ${PORT_OPTIONS:MENCODING}
CONFIGURE_ARGS+=	--with-codesets=${WITH_ENCODING}
.endif # WITH_ENCODING

pre-everything::
.ifndef(WITH_ENCODING)
	@${ECHO_MSG} "==> You can compile in support for additional codeset groups by setting the WITH_ENCODING variable"
	@${ECHO_MSG} '==> Options are: "jp"     common japanese encodings;'
	@${ECHO_MSG} '                 "jp_ext" rarely used but big japanese encodings;'
	@${ECHO_MSG} '                 "kr"     korean encodings;'
	@${ECHO_MSG} '                 "zh"     common chinese encodings;'
	@${ECHO_MSG} '                 "zh_ext" rarely used but very big chinese encodigs;'
	@${ECHO_MSG} '                 "all"    all of the above;'
	@${ECHO_MSG} '==> For example, "WITH_ENCODING=kr" for korean encodings.'
	@${ECHO_MSG}
.endif

.if ${PORT_OPTIONS:MIMLOCALE_FIX}
post-patch:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-imlocale
	cd ${WRKSRC}/src && ./gentables
.endif

pre-configure:
	${RM} ${WRKSRC}/src/perl/kuake.orig

post-install:
	${CHMOD} 4711 ${PREFIX}/bin/urxvt ${PREFIX}/bin/urxvtd
	${INSTALL_DATA} ${WRKSRC}/doc/etc/rxvt-unicode.terminfo	\
		${LOCALBASE}/share/misc/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} ${PORTDOCS1:S|^|${WRKSRC}/|} ${WRKSRC}/doc
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
