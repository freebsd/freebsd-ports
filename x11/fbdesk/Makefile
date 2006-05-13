# New ports collection makefile for:    fbdesk
# Date created: 16 January 2003
# Whom: Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	fbdesk
PORTVERSION=	1.2.1
CATEGORIES=	x11
MASTER_SITES=	http://fluxbox.sourceforge.net/download/ \
		${MASTER_SITE_GENTOO} \
		http://dl.fkb.wormulon.net/fbdesk/ \
		http://dl.kel.wormulon.net/fbdesk/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	hendrik@scholz.net
COMMENT=	A Fluxbox utility to create and manage icons on the desktop

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

PLIST_FILES=	bin/fbdesk
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	COPYING ChangeLog INSTALL README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
post-patch:
	${REINPLACE_CMD} -e "s/inttypes\.h/stdint\.h/" \
		${WRKSRC}/src/FbTk/Timer.hh
.endif

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
