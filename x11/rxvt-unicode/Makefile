# Created by: gpalmer@FreeBSD.org

PORTNAME=	rxvt-unicode
PORTVERSION=	9.26
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Attic

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Clone of the terminal emulator rxvt modified to support Unicode

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig
LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/bin/fc-cache:x11-fonts/fontconfig

USES=			cpe perl5 pkgconfig shebangfix tar:bzip2 xorg
USE_XORG=		x11 xft xmu xpm xrender xt
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-lutil
CONFIGURE_ARGS=		--enable-everything --with-term=rxvt
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

OPTIONS_DEFAULT=	PERL XIM UNICODE3 ISO14755 COMBINING RXVT_SCROLLBAR	\
			NEXT_SCROLLBAR XTERM_SCROLLBAR BACKSPACE_KEY DELETE_KEY	\
			MOUSEWHEEL SMART_RESIZE IMLOCALE_FIX GDK_PIXBUF		\
			256_COLOR
OPTIONS_EXCLUDE_armv6=	IMLOCALE_FIX
OPTIONS_EXCLUDE_armv7=	IMLOCALE_FIX
OPTIONS_SUB=		yes

PORTDOCS1=	Changes README.FAQ README.configure
PORTDOCS=	README.xvt ${PORTDOCS1}

IMLOCALE_FIX_PATCH_DEPENDS=	p5-Encode-HanExtra>=0:chinese/p5-Encode-HanExtra \
				p5-Encode-JIS2K>=0:converters/p5-Encode-JIS2K

# disable the embedded perl interpreter
PERL_CONFIGURE_ENABLE=	perl
PERL_USE_OFF=		PERL5=build

# disable XIM (X Input Method) protocol support
XIM_CONFIGURE_ENABLE=	xim

# disable support for Unicode codepoints above 65535
UNICODE3_CONFIGURE_ENABLE=	unicode3

# disable support for extended ISO 14755 modes
ISO14755_CONFIGURE_ENABLE=	iso14755

# disable automatic composition of combining characters
# into composite characters
COMBINING_CONFIGURE_ENABLE=	combining

# disable support for the original rxvt scrollbar
RXVT_SCROLLBAR_CONFIGURE_ENABLE=	rxvt-scroll

# disable support for a NeXT-like scrollbar
NEXT_SCROLLBAR_CONFIGURE_ENABLE=	next-scroll

# disable support for an Xterm-like scrollbar
XTERM_SCROLLBAR_CONFIGURE_ENABLE=	xterm-scroll

# disable any handling of the backspace key by rxvt
# let the X server do it
BACKSPACE_KEY_CONFIGURE_ENABLE=	backspace-key

# disable any handling of the delete key by rxvt
DELETE_KEY_CONFIGURE_ENABLE=	delete-key

# enable scrolling via mouse wheel or buttons 4 & 5
MOUSEWHEEL_CONFIGURE_ENABLE=	mousewheel

# enable smart resize
SMART_RESIZE_CONFIGURE_ENABLE=	smart-resize

# enable integration with gdk-pixbuf for background images
GDK_PIXBUF_USES=	gnome
GDK_PIXBUF_USE=		GNOME=gdkpixbuf2
GDK_PIXBUF_CONFIGURE_ENABLE=	pixbuf

# enable startup notification
NOTIFY_CONFIGURE_ENABLE=	startup-notification
NOTIFY_LIB_DEPENDS=		libstartup-notification-1.so:x11/startup-notification
NOTIFY_USE=			XORG=xcb

# enable support for 256 colors
256_COLOR_CONFIGURE_ON=	--enable-256-color

.include <bsd.port.options.mk>

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

post-patch-IMLOCALE_FIX-on:
	${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-imlocale
	cd ${WRKSRC}/src && ./gentables

pre-configure:
	${REINPLACE_CMD} -e "/rxvt-unicode.terminfo/d" ${WRKSRC}/doc/Makefile.in
	${RM} ${WRKSRC}/src/perl/kuake.orig

post-build-DOCS-on:
	${CP} ${PORTDOCS1:S|^|${WRKSRC}/|} ${WRKSRC}/doc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
