# Created by: gpalmer@FreeBSD.org
# $FreeBSD$

PORTNAME=	rxvt-unicode
PORTVERSION=	9.22
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Attic

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Clone of the terminal emulator rxvt modified to support Unicode

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/bin/fc-cache:x11-fonts/fontconfig

USES=			cpe pkgconfig shebangfix tar:bzip2 terminfo
USE_XORG=		xpm xft xrender
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-lutil
CONFIGURE_ENV=		TIC=${LOCALBASE}/bin/tic
CONFIGURE_ARGS=		--enable-everything --with-term=rxvt	\
			--with-terminfo=${LOCALBASE}/share/misc/terminfo.db
CPE_VENDOR=		marc_lehmann

OPTIONS_DEFINE=	PERL XIM UNICODE3 ISO14755 COMBINING RXVT_SCROLLBAR	\
		NEXT_SCROLLBAR XTERM_SCROLLBAR BACKSPACE_KEY DELETE_KEY	\
		MOUSEWHEEL SMART_RESIZE IMLOCALE_FIX GDK_PIXBUF		\
		NOTIFY 256_COLOR DOCS

SHEBANG_FILES=	${WRKSRC}/src/perl/*
perl_OLD_CMD=	perl
perl_CMD=	${SETENV} perl

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
		MOUSEWHEEL SMART_RESIZE IMLOCALE_FIX GDK_PIXBUF		\
		256_COLOR

PORTDOCS1=	Changes README.FAQ README.configure
PORTDOCS=	README.xvt ${PORTDOCS1}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMLOCALE_FIX}
PATCH_DEPENDS+=	p5-Encode-HanExtra>=0:chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>=0:converters/p5-Encode-JIS2K
.endif

# disable the embedded perl interpreter
.if !${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--disable-perl
USES+=			perl5
USE_PERL5=		build
PLIST_SUB=		PERL="@comment "
.else
USES+=			perl5
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

# enable integration with gdk-pixbuf for background images
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
LIB_DEPENDS+=		libstartup-notification-1.so:x11/startup-notification
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

post-build:
.if ${PORT_OPTIONS:MDOCS}
	${CP} ${PORTDOCS1:S|^|${WRKSRC}/|} ${WRKSRC}/doc
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/etc/rxvt-unicode.terminfo	\
		${STAGEDIR}${PREFIX}/share/misc/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
