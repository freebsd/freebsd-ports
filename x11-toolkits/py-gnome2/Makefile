# New ports collection makefile for:	pygtk
# Version required:	0.4.3
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/06/25 06:43:28 tg Exp $
#

DISTNAME=	pygtk-0.4.3
PKGNAME=	py-gtk-0.4.3
CATEGORIES=	x11 python
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

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
