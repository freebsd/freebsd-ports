# New ports collection makefile for:	pygtk
# Version required:	0.4.3
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	pygtk-0.4.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/python/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11/gtk

GNU_CONFIGURE=	yes
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

post-install:
	@${MKDIR} ${PREFIX}/share/examples/pygtk
	@(cd ${WRKSRC}/examples; tar cf - *) | \
		(cd ${PREFIX}/share/examples/pygtk; tar xf -)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pygtk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pygtk
.endif

.include <bsd.port.mk>
