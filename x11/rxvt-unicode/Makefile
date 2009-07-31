# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rxvt-unicode
PORTVERSION=	9.06
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Attic

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A clone of the terminal emulator rxvt modified to support Unicode

.if !defined(WITHOUT_IMLOCALE_FIX)
PATCH_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Encode/HanExtra.pm:${PORTSDIR}/chinese/p5-Encode-HanExtra \
		${SITE_PERL}/${PERL_ARCH}/Encode/JIS2K.pm:${PORTSDIR}/converters/p5-Encode-JIS2K
.endif

USE_GNOME=	pkgconfig
USE_XORG=		xpm xft
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=		--enable-shared --enable-everything --with-term=rxvt
USE_BZIP2=		yes

MAN1=		urxvt.1 urxvtc.1 urxvtd.1
MAN7=		urxvt.7

PORTDOCS1=	Changes README.FAQ README.configure
PORTDOCS=	README.xvt ${PORTDOCS1}

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

# disable automatic composition of combining characters
# into composite characters
.if defined(WITHOUT_COMBINING)
CONFIGURE_ARGS+=	--disable-combining
.endif

# disable support for menu bar system
.if defined(WITHOUT_MENUBAR)
CONFIGURE_ARGS+=	--disable-menubar
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

# disable support for a very unobtrusive, plain-looking scrollbar
.if defined(WITHOUT_PLAIN_SCROLLBAR)
CONFIGURE_ARGS+=	--disable-plain-scroll
.endif

# enable half width/height shadows rxvt scrollbar
.if defined(WITH_HALF_SHADOW)
CONFIGURE_ARGS+=	--enable-half-shadow
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

# disable support to provide user specified line spacing between text rows
.if defined(WITHOUT_LINESPACE)
CONFIGURE_ARGS+=	--disable-linespace
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

.if defined(WITHOUT_TERMINFO)
CONFIGURE_ARGS+=	--without-terminfo
PLIST_SUB+=		TERMINFO="@comment "
.else
BUILD_DEPENDS+=	tic:${PORTSDIR}/devel/ncurses
CONFIGURE_ARGS+=	--with-terminfo=${LOCALBASE}/share/misc/terminfo.db
RUN_DEPENDS+=	${LOCALBASE}/share/misc/terminfo.db:${PORTSDIR}/devel/ncurses
PLIST_SUB+=		TERMINFO=""
.endif

# enable integration with libAfterImage for background images
.if defined(WITHOUT_AFTERIMAGE)
CONFIGURE_ARGS+=	--disable-afterimage	# To be upgraded
.else
LIB_DEPENDS+=		AfterImage.0:${PORTSDIR}/graphics/libafterimage
CONFIGURE_ARGS+=	--enable-afterimage
.endif

CONFIGURE_ENV+=		LIBS="-lutil"

# enable support for xterm 256 colors
.if defined(WITH_XTERM_COLOR)
CONFIGURE_ARGS+=	--enable-xterm-colors=256
.endif

.include <bsd.port.pre.mk>

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
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITHOUT_PERL		disable the embedded Perl interpreter"
	@${ECHO_MSG} "WITHOUT_XIM		disable support for XIM (X Input Method) protocol"
	@${ECHO_MSG} "WITHOUT_MENUBAR		disable support for menu bar system"
	@${ECHO_MSG} "WITHOUT_RXVT_SCROLLBAR	disable support for the original rxvt scrollbar"
	@${ECHO_MSG} "WITHOUT_NEXT_SCROLLBAR	disable support for a NeXT-like scrollbar"
	@${ECHO_MSG} "WITHOUT_XTERM_SCROLLBAR	disable support for an Xterm-like scrollbar"
	@${ECHO_MSG} "WITHOUT_PLAIN_SCROLLBAR	disable support for a plain-looking scrollbar"
	@${ECHO_MSG} "WITH_HALF_SHADOW      	use half width/height shadows on rxvt scrollbar"
	@${ECHO_MSG} "WITHOUT_BACKSPACE_KEY	disable handling of the backspace key"
	@${ECHO_MSG} "WITHOUT_DELETE_KEY	disable handling of the delete key"
	@${ECHO_MSG} "WITHOUT_LINESPACE	disable support for line-spacing"
	@${ECHO_MSG} "WITHOUT_MOUSEWHEEL	disable support for scrolling via mouse wheel"
	@${ECHO_MSG} "WITHOUT_SMART_RESIZE	disable smart growth/shrink behaviour"
	@${ECHO_MSG} "WITHOUT_IMLOCALE_FIX	disable imlocale encoding conversion fix"
	@${ECHO_MSG} "WITHOUT_TERMINFO	don't register urxvt in the terminfo database"
	@${ECHO_MSG} "WITHOUT_AFTERIMAGE	disable integration with libAfterImage for background images"
	@${ECHO_MSG} "WITH_XTERM_COLOR	enable support for xterm 256 colors"
	@${ECHO_MSG}
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

.if !defined(WITHOUT_IMLOCALE_FIX) || defined(WITH_XTERM_COLOR)
post-patch:
.if !defined(WITHOUT_IMLOCALE_FIX)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-imlocale
	@cd ${WRKSRC}/src && ./gentables
.endif
.if defined(WITH_XTERM_COLOR)
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKSRC}/doc/urxvt-8.2-256color.patch
.endif
.endif

pre-configure:
	@${RM} ${WRKSRC}/src/perl/kuake.orig
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.C

post-install:
	${CHMOD} 4711 ${PREFIX}/bin/urxvt ${PREFIX}/bin/urxvtd
.if !defined(WITHOUT_TERMINFO)
	${INSTALL_DATA} ${WRKSRC}/doc/etc/rxvt-unicode.terminfo	\
		${LOCALBASE}/share/misc/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} ${PORTDOCS1:S|^|${WRKSRC}/|} ${WRKSRC}/doc
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
