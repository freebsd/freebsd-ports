# New ports collection makefile for:	eterm
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	http://www.eterm.org/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER?=	olgeni@FreeBSD.org

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2 \
		ast.2:${PORTSDIR}/devel/libast

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--enable-trans --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs --without-terminfo \
		--enable-multi-charset

MAN1=		Eterm.1

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=--enable-mmx
.endif

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.1.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.post.mk>
