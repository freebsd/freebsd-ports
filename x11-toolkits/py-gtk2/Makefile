# New ports collection makefile for:	py-gtk
# Version required:			0.5.10
# Date created:				12/26/1998
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.20 1999/02/28 09:28:34 obrien Exp $
#

DISTNAME=	pygtk-0.5.11
PKGNAME=	py-gtk-0.5.11
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	nectar@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	Imlib.2:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk11d-config
MAKE_FLAGS=	OPT="${CFLAGS}"

# NOTE: for packaging to work properly, this port should be
# built with PREFIX set the same as when the python port
# was built.

post-install:
	@${MKDIR} ${PREFIX}/share/examples/py-gtk
	@(cd ${WRKSRC}/examples; tar cf - *) | \
		(cd ${PREFIX}/share/examples/py-gtk; tar xf -)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-gtk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-gtk
.endif

.include <bsd.port.mk>
