# New ports collection makefile for:    fbdesk
# Date created: 16 January 2003
# Whom: Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	fbdesk
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://fluxbox.sourceforge.net/download/ \
		${MASTER_SITE_GENTOO} \
		http://dl.fkb.wormulon.net/fbdesk/ \
		http://dl.kel.wormulon.net/fbdesk/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Fluxbox utility to create and manage icons on the desktop

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

OPTIONS=	IMLIB2 "Imlib2 (pixmap themes) support" On

USE_XORG=	xext xft xpm xrender
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog INSTALL README
PLIST_FILES=	bin/fbdesk
USE_EFL=	imlib2

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IMLIB2)
CONFIGURE_ARGS+=	--disable-imlib2
.else
USE_EFL=	imlib2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
