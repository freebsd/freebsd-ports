# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.8.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://movingparts.thelinuxcommunity.org/bbkeys/

MAINTAINER=	stijn@win.tue.nl

RUN_DEPENDS=	bbconf:${PORTSDIR}/x11-wm/bbconf \
		blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_QT_VER=	2

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5 bbkeys.bb.5

pre-patch:
.if !defined(NOPORTDOCS)
	@${PERL} -pi -e 's@doc/bbkeys@share/doc/bbkeys@g' ${WRKSRC}/Makefile.in
.else
	@${PERL} -ni -e '/^(docdir|doc_DATA)/ && next; print' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
