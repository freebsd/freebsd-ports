# New ports collection makefile for:	mlterm
# Date created:		9 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	mlterm
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-imagelib=gdk-pixbuf1 --enable-utmp

.if defined(WITH_FRIBIDI)
CONFIGURE_ARGS=	--enable-fribidi
LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi
.endif

INSTALLS_SHLIB=	yes

MAN1=	mlterm.1 mlclient.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
PKGNAMESUFFIX=	-noaa
.else
CONFIGURE_ARGS+=	--enable-anti-alias
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.endif

pre-everything::
.if !defined(WITH_FRIBIDI)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may enable BiDi support by using the"
	@${ECHO_MSG} "WITH_FRIBIDI option."
	@${ECHO_MSG}
.endif

post-configure:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		-e "s,%%PERL%%,${PERL}," \
		${WRKSRC}/tool/w3mmlconfig/Makefile

post-build:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE})

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE} install)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/mlterm
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${PREFIX}/share/doc/ja/mlterm
.endif

.include <bsd.port.post.mk>
