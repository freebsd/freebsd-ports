# New ports collection makefile for:	eterm
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES+=	x11
MASTER_SITES=	http://www.eterm.org/download/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER?=	olgeni@FreeBSD.org
COMMENT?=	X11 terminal emulator based on rxvt/xterm

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html
LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		ast.2:${PORTSDIR}/devel/libast

USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
OPTIONS=	MMX	"With MMX instruction set" off

MAN1=		Eterm.1

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=--enable-mmx
.endif

post-patch:
	@${FIND} ${WRKSRC} -name *.orig | ${XARGS} ${RM}

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.post.mk>
