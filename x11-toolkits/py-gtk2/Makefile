# New ports collection makefile for:	pygtk
# Version required:			0.5.9
# Date created:				12/26/1998
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.15 1998/12/31 05:40:03 nectar Exp $
#

DISTNAME=	pygtk-0.5.9
PKGNAME=	py-gtk-0.5.9
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	nectar@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	Imlib.1:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

BROKEN=		repository copy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk11d-config
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
