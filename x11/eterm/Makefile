# Created by: Murray Stokely <murray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eterm
PORTVERSION=	0.9.6
PORTREVISION=	5
CATEGORIES+=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Eterm-${PORTVERSION}
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER?=	enlightenment@FreeBSD.org
COMMENT?=	X11 terminal emulator based on rxvt/xterm

BUILD_DEPENDS=	man2html:textproc/man2html
LIB_DEPENDS=	libast.so:devel/libast \
		libImlib2.so:graphics/imlib2

BROKEN_aarch64=		fails to package: gdb.scr: no such file or directory
BROKEN_mips=		fails to package: gdb.scr: no such file or directory
BROKEN_mips64=		fails to package: gdb.scr: no such file or directory
BROKEN_powerpc64=	fails to package: gdb.scr: no such file or directory

GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset

.if exists(/usr/libexec/gdb)
CONFIGURE_ENV=	GDB=/usr/libexec/gdb
.else
CONFIGURE_ENV=	GDB=/usr/bin/gdb
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		iconv libtool shebangfix
SHEBANG_FILES=	${WRKSRC}/utils/kEsetroot.in
perl_OLD_CMD=	@PERL@
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
USE_XORG=	x11 xt

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	MMX

MMX_CONFIGURE_WITH=	mmx

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
