# New ports collection makefile for: bbpager
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbpager
DISTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A pager for the Blackbox window manager

BUILD_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_GNOME=	gnomehack pkgconfig
USE_XORG=	xext sm x11 xau xcursor xi
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags xft`" \
		LDFLAGS="`pkg-config --libs xft`"

DOCS=		AUTHORS BUGS COPYING ChangeLog INSTALL NEWS \
		README TODO
EXAMPLES=	bbpager.rc README.bbpager

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/bbpager ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/data/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
