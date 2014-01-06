# Created by: Murray Stokely <murray@FreeBSD.org>
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
LIB_DEPENDS=	libast.so:${PORTSDIR}/devel/libast

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	MMX

USE_XORG=	x11 xt
USES=		iconv
USE_EFL=	imlib2
MMX_CONFIGURE_ARGS=	--enable-mmx

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
