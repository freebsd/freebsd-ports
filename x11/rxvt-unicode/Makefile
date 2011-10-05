# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rxvt-unicode
PORTVERSION=	9.12
PORTREVISION=	1
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
CONFIGURE_ENV=		LIBS="-lutil"
CONFIGURE_ARGS=		--enable-everything --with-term=rxvt	\
			--with-terminfo=${LOCALBASE}/share/misc/terminfo.db
USE_BZIP2=		yes
WANT_PERL=		yes

OPTIONS=	\
	PERL		"Embedded perl interpreter"			On	\
	XIM		"Support for XIM (X Input Method) protocol"	On	\
	UNICODE3	"Support Unicode codepoints above 65535"	On	\
	ISO14755	"Support for extended ISO 14755 modes"		On	\
	COMBINING	"Automatic composition of combining chars"	On	\
	RXVT_SCROLLBAR	"Support for the original rxvt scrollbar"	On	\
	NEXT_SCROLLBAR	"Support for a NeXT-like scrollbar"		On	\
	XTERM_SCROLLBAR	"Support for an Xterm-like scrollbar"		On	\
	BACKSPACE_KEY	"Handling of the backspace key by rxvt"		On	\
	DELETE_KEY	"Handling of the delete key by rxvt"		On	\
	MOUSEWHEEL	"Support for scrolling via mouse wheel"		On	\
	SMART_RESIZE	"Smart growth/shrink behaviour"			On	\
	IMLOCALE_FIX	"imlocale encoding conversion fix" 		On	\
	GDK_PIXBUF	"Use gdk-pixbuf for background images"		On	\
	AFTERIMAGE	"Use libAfterImage for background images"	Off	\
	256_COLOR	"Support for 256 colors"			Off

.include <bsd.port.pre.mk>

MAN1=		urxvt.1 urxvtc.1 urxvtcd.1 urxvtd.1
MAN7=		urxvt.7

PORTDOCS1=	Changes README.FAQ README.configure
PORTDOCS=	README.xvt ${PORTDOCS1}

.if !defined(WITHOUT_IMLOCALE_FIX)
PATCH_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode/HanExtra.pm:${PORTSDIR}/chinese/p5-Encode-HanExtra \
		${SITE_PERL}/${PERL_ARCH}/Encode/JIS2K.pm:${PORTSDIR}/converters/p5-Encode-JIS2K
.endif

# disable the embedded perl interpreter
.if defined(WITHOUT_PERL)
CONFIGURE_ARGS+=	--disable-perl
USE_PERL5_BUILD=	yes
PLIST_SUB=		PERL="@comment "
.else
USE_PERL5=		yes
MAN3=			urxvtperl.3
PLIST_SUB=		PERL=""
.endif

# disable XIM (X Input Method) protocol support
.if defined(WITHOUT_XIM)
CONFIGURE_ARGS+=	--disable-xim
.endif

# disable support for Unicode codepoints above 65535
.if defined(WITHOUT_UNICODE3)
CONFIGURE_ARGS+=	--disable-unicode3
.endif

# disable support for extended ISO 14755 modes
.if defined(WITHOUT_ISO14755)
CONFIGURE_ARGS+=	--disable-iso14755
.endif

# disable automatic composition of combining characters
# into composite characters
.if defined(WITHOUT_COMBINING)
CONFIGURE_ARGS+=	--disable-combining
.endif

# disable support for the original rxvt scrollbar
.if defined(WITHOUT_RXVT_SCROLLBAR)
CONFIGURE_ARGS+=	--disable-rxvt-scroll
.endif

# disable support for a NeXT-like scrollbar
.if defined(WITHOUT_NEXT_SCROLLBAR)
CONFIGURE_ARGS+=	--disable-next-scroll
.endif

# disable support for an Xterm-like scrollbar
.if defined(WITHOUT_XTERM_SCROLLBAR)
CONFIGURE_ARGS+=	--disable-xterm-scroll
.endif

# disable any handling of the backspace key by rxvt
# let the X server do it
.if defined(WITHOUT_BACKSPACE_KEY)
CONFIGURE_ARGS+=	--disable-backspace-key
.endif

# disable any handling of the delete key by rxvt
.if defined(WITHOUT_DELETE_KEY)
CONFIGURE_ARGS+=	--disable-delete-key
.endif

# enable scrolling via mouse wheel or buttons 4 & 5
.if defined(WITHOUT_MOUSEWHEEL)
CONFIGURE_ARGS+=	--disable-mousewheel
.endif

# enable smart resize
.if defined(WITHOUT_SMART_RESIZE)
CONFIGURE_ARGS+=	--disable-smart-resize
.else
CONFIGURE_ARGS+=	--enable-smart-resize
.endif

# enable integration with gdk-pixbuf / or libAfterImage for background images
.if defined(WITHOUT_GDK_PIXBUF)
CONFIGURE_ARGS+=	--disable-pixbuf
. if defined(WITHOUT_AFTERIMAGE)
CONFIGURE_ARGS+=	--disable-afterimage	# To be upgraded
. else
LIB_DEPENDS+=		AfterImage.0:${PORTSDIR}/graphics/libafterimage
CONFIGURE_ARGS+=	--enable-afterimage
. endif
.else
USE_GNOME+=		gdkpixbuf2
CONFIGURE_ARGS+=	--enable-pixbuf
.endif

# enable support for 256 colors
.if defined(WITH_256_COLOR)
CONFIGURE_ARGS+=	--enable-256-color
.endif

# compile in support for additional codeset groups
.if defined(WITH_ENCODING)
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
.if defined(WITH_ENCODING)
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

.if !defined(WITHOUT_IMLOCALE_FIX)
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

.include <bsd.port.post.mk>
