# New ports collection makefile for:	eterm
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	SF
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER?=	olgeni@FreeBSD.org
COMMENT?=	X11 terminal emulator based on rxvt/xterm

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html
LIB_DEPENDS=	ast.2:${PORTSDIR}/devel/libast

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
OPTIONS=	MMX	"With MMX instruction set" off
USE_XORG=	x11 xt
USE_ICONV=	yes
USE_EFL=	imlib2

MAN1=		Eterm.1

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=--enable-mmx
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
