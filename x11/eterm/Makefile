# Created by: Murray Stokely <murray@freebsd.org>
# $FreeBSD$

PORTNAME=	eterm
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Eterm-${PORTVERSION}
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER?=	olgeni@FreeBSD.org
COMMENT?=	X11 terminal emulator based on rxvt/xterm

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html
LIB_DEPENDS=	ast:${PORTSDIR}/devel/libast

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89

OPTIONS_DEFINE=	MMX

USE_XORG=	x11 xt
USES=		iconv
USE_EFL=	imlib2

MAN1=		Eterm.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMMX} && (${ARCH} == "i386")
CONFIGURE_ARGS+=--enable-mmx
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
