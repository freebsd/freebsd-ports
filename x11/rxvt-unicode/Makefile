# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rxvt-unicode
PORTVERSION=	3.9
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/
MASTER_SITE_SUBDIR=	. Attic

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A clone of the terminal emulator rxvt modified to support Unicode

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_PERL5_BUILD=	yes
USE_X_PREFIX=		yes
USE_XPM=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=		--enable-shared --enable-everything --with-term=rxvt
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes
USE_BZIP2=		yes

CONFLICTS=	rxvt-devel-2*

MAN1=		urxvt.1 urxvtc.1 urxvtd.1
MAN7=		urxvt.7

PORTDOCS1=	Changes
PORTDOCS=	README.menu ${PORTDOCS1}
EXAMPLES=	example.menu jedmenu.sl menu rxvt.menu rxvt.zh-menu terminal.menu

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

CONFIGURE_ENV+=		LIBS="-lutil"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		missing wide-character functions in FreeBSD-4.x libc
.endif

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	${LOCALBASE}/share/locale/fr_FR.UTF-8/LC_TIME:${PORTSDIR}/misc/utf8locale
.endif

# compile in support for additional codeset groups
.if defined(WITH_ENCODING)
AVAIL_ENC=	jp jp_ext kr cn cn_ext all
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
	@${ECHO_MSG} "WITHOUT_XIM		disable support for XIM (X Input Method) protocol"
	@${ECHO_MSG} "WITHOUT_MENUBAR		disable support for menu bar system"
	@${ECHO_MSG} "WITHOUT_RXVT_SCROLLBAR	disable support for the original rxvt scrollbar"
	@${ECHO_MSG} "WITHOUT_NEXT_SCROLLBAR	disable support for a NeXT-like scrollbar"
	@${ECHO_MSG} "WITHOUT_XTERM_SCROLLBAR	disable support for an Xterm-like scrollbar"
	@${ECHO_MSG} "WITHOUT_PLAIN_SCROLLBAR	disable support for a plain-looking scrollbar"
	@${ECHO_MSG} "WITH_HALF_SHADOW      	use half width/height shadows on rxvt scrollbar"
	@${ECHO_MSG} "WITHOUT_BACKSPACE_KEY	disable handling of the backspace key"
	@${ECHO_MSG} "WITHOUT_DELETE_KEY	disable handling of the delete key"
	@${ECHO_MSG} "WITHOUT_LINESPACE		disable support for line-spacing"
	@${ECHO_MSG} "WITHOUT_MOUSEWHEEL	disable support for scrolling via mouse wheel"
	@${ECHO_MSG} "WITHOUT_SMART_RESIZE	disable smart growth/shrink behaviour"
	@${ECHO_MSG}
.ifndef(WITH_ENCODING)
	@${ECHO_MSG} "==> You can compile in support for additional codeset groups by setting the WITH_ENCODING variable"
	@${ECHO_MSG} '==> Options are: "jp"     common japanese encodings;'
	@${ECHO_MSG} '                 "jp_ext" rarely used but big japanese encodings;'
	@${ECHO_MSG} '                 "kr"     korean encodings;'
	@${ECHO_MSG} '                 "cn"     common chinese encodings;'
	@${ECHO_MSG} '                 "cn_ext" rarely used but very big chinese encodigs;'
	@${ECHO_MSG} '                 "all"    all of the above;'
	@${ECHO_MSG} '==> For example, "WITH_ENCODING=kr" for korean encodings.'
	@${ECHO_MSG}
.endif

pre-configure:
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.C

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/urxvt
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} ${PORTDOCS1:S|^|${WRKSRC}/|} ${WRKSRC}/doc
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/doc/menu/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
